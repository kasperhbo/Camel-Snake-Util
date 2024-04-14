//
// Created by Kasper de bruin on 30/03/2024.
//

#include "Server.h"

#include <utility>
#include <HBUI/HBUI.h>

#define OPCUA_LOCALE "en-US"

namespace HB::Utils::Opcua {

    std::string UAStringToString(const UA_String &uaString) {
        // Check if the UA_String is valid
        if (uaString.data == nullptr || uaString.length == 0) {
            return {}; // Return an empty string if UA_String is invalid or empty
        }
        return {reinterpret_cast<char *>(uaString.data), uaString.length};
    }

    Server::Server(std::string mHostname, int mPort, const std::vector<Node *> &nodes)
            : m_Hostname(std::move(mHostname)), m_Port(mPort),
              p_Server(nullptr),
              m_Mutex(), m_Cond(),
              m_ServerThread(), m_RunServer() {

        for (auto node: nodes) {
            m_Nodes[node->nodeId] = node;
        }

        static std::vector<std::string> boolNodeNames = {
                "bStateAborted",
                "bStateAborting",
                "bStateClearing",
                "bStateComplete",
                "bStateCompleting",
                "bStateExecute",
                "bStateHeld",
                "bStateHolding",
                "bStateldle",
                "bStateResetting",
                "bStateStarting",
                "bStateStopped",
                "bStateStopping",
                "bStateSuspended",
                "bStateSuspending",
                "bStateUnHolding",
                "bStateUnsuspending"
        };

        //dbpackml
        {
            auto root = new HB::Utils::Opcua::Node("dbPackML", "dbPackML", "dbPackML",
                                                   HB::Utils::Opcua::NodeType::OBJECT);
            //General
            {
                auto rootGeneralNode = new HB::Utils::Opcua::Node("General", "General", "dbPackML.General",
                                                                  HB::Utils::Opcua::NodeType::OBJECT);
                {
                    auto sWorkOrderIdNode = new HB::Utils::Opcua::Node("sWorkOrderId", "sWorkOrderId",
                                                                       "dbPackML.General.sWorkOrderId",
                                                                       std::string("Unset"), NodeType::VARIABLE);
                    rootGeneralNode->addNode(sWorkOrderIdNode);
                }
                {
                    auto iNofAssembliesInBatchNode = new HB::Utils::Opcua::Node("iNofAssembliesInBatch",
                                                                                "iNofAssembliesInBatch",
                                                                                "dbPackML.General.iNofAssembliesInThisBatch",
                                                                                uint16_t(0), NodeType::VARIABLE);
                    rootGeneralNode->addNode(iNofAssembliesInBatchNode);
                }
                {
                    auto iNofAssembliesInBatchNode = new HB::Utils::Opcua::Node(
                            "iNofAssembliesProduced", "iNofAssembliesProduced",
                            "dbPackML.General.iNofAssembliesProduced",
                            uint16_t(0), NodeType::VARIABLE);
                    rootGeneralNode->addNode(iNofAssembliesInBatchNode);
                }
                root->addNode(rootGeneralNode);
            }

            //currentstate
            {
                auto currentStateRoot = new HB::Utils::Opcua::Node("CurrentState", "CurrentState",
                                                                   "dbPackML.CurrentState",
                                                                   HB::Utils::Opcua::NodeType::OBJECT);
                //all other state
                {
                    for (auto &boolNodeName: boolNodeNames) {
                        auto boolNode = new HB::Utils::Opcua::Node(boolNodeName, boolNodeName,
                                                                   "dbPackML.CurrentState." + boolNodeName,
                                                                   false, NodeType::VARIABLE);
                        currentStateRoot->addNode(boolNode);
                    }
                }

                root->addNode(currentStateRoot);
            }
            m_Nodes[root->nodeId] = root;
        }
    }

    Server::~Server() {
        stopServer();

        for (auto &node: m_Nodes) {
            delete node.second;
        }
    }


    void Server::startServer() {
        ///------------------------------------------
        /// Check if the server is already running
        ///------------------------------------------
        std::unique_lock<std::mutex> lock(m_Mutex);
        if (p_Server != nullptr && p_Server->isRunning()) {
            std::cout << "Server is already running" << std::endl;
            return;
        }

        ///------------------------------------------
        /// Create the server
        ///------------------------------------------
        p_Server = new opcua::Server(m_Port);

        if (m_Hostname.empty()) {
            m_Hostname = "localhost";
        }

        p_Server->setCustomHostname(m_Hostname);//else use the pc's hostname
        p_Server->setApplicationUri("opcua:open62541pp.server.application");
        p_Server->setProductUri("https://open62541pp.github.io");
        p_Server->setLogger([](opcua::LogLevel level, opcua::LogCategory category, std::string_view message) {
            switch (level) {
                case opcua::LogLevel::Error:
                case opcua::LogLevel::Fatal:
                    HBUI::error(std::string(message));
                    break;
                case opcua::LogLevel::Warning:
                    HBUI::warn(std::string(message));
                    break;
                case opcua::LogLevel::Info:
                case opcua::LogLevel::Trace:
                    HBUI::log(std::string(message));
                    break;
                case opcua::LogLevel::Debug:
                    HBUI::debug(std::string(message));
                    break;
            }
        });
        opcua::Node<opcua::Server> parentNode = p_Server->getObjectsNode();
        for (auto &node: m_Nodes) {
            addNodeToServer(*node.second, parentNode);
        }

        ///------------------------------------------
        /// Start the server
        ///------------------------------------------
        m_RunServer = true;
        m_ServerThread = std::thread(&Server::serverThreadFunction, this);
    }


    void Server::stopServer() {
        {
            std::unique_lock<std::mutex> lock(m_Mutex);
            m_RunServer = false;
        }

        if (m_ServerThread.joinable()) {
            m_ServerThread.join();
        }

        // Cleaning up the server...
        if (p_Server != nullptr) {
            p_Server->stop();
            delete p_Server;
            p_Server = nullptr;
        }
    }

    void Server::serverThreadFunction() {
        while (m_RunServer) {
            p_Server->runIterate();
            std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Adjust time as needed
        }
    }


//------------------------------------------------------------------------------------------------------------------
// Private
//------------------------------------------------------------------------------------------------------------------
#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"

    void Server::addNodeToServer(const HB::Utils::Opcua::Node &node, opcua::Node<opcua::Server> &parentNode) {
        std::cout << "Trying to add node to server" << std::endl;
        opcua::AccessLevel accessLevel = opcua::AccessLevel::CurrentRead |
                                         opcua::AccessLevel::CurrentWrite |
                                         opcua::AccessLevel::HistoryRead |
                                         opcua::AccessLevel::HistoryWrite |
                                         opcua::AccessLevel::SemanticChange |
                                         opcua::AccessLevel::StatusWrite |
                                         opcua::AccessLevel::TimestampWrite;

        if (p_Server == nullptr) {
            std::cout << "Server is nullptr" << std::endl;
            return;
        }
        if (node.type == NodeType::OBJECT) {
            auto objectNode = parentNode.addObject(
                    {1, node.nodeId},
                    node.browserName,
                    opcua::ObjectAttributes{}
                            .setDisplayName({OPCUA_LOCALE, node.displayName})
                            .setDescription({OPCUA_LOCALE, node.nodeId})
            );
            for (auto childNode: node.childNodes) {
                addNodeToServer(*childNode, objectNode);
            }
        } else if (node.type == NodeType::VARIABLE) {
            int dataTypeId = node.getDataType();
            auto attributes = opcua::VariableAttributes{
            }.setDisplayName({OPCUA_LOCALE, node.displayName})
                    .setDescription({OPCUA_LOCALE, node.nodeId})
                    .setUserAccessLevel(accessLevel)
                    .setAccessLevel(accessLevel)
                    .setHistorizing(true);

            switch (dataTypeId) {
                case UA_TYPES_UINT16:
                    attributes.setDataType(opcua::DataTypeId::UInt16);
                    break;
                case UA_TYPES_BOOLEAN:
                    attributes.setDataType(opcua::DataTypeId::Boolean);
                    break;
                case UA_TYPES_STRING:
                    attributes.setDataType(opcua::DataTypeId::String);
                    break;
            }

            auto objectNode = parentNode.addVariable(
                    {1, node.nodeId},
                    node.browserName,
                    attributes
            );

            switch (dataTypeId) {
                case UA_TYPES_UINT16: {
                    objectNode.writeValueScalar(std::get<uint16_t>(node.defaultValue));
                    break;
                }
                case UA_TYPES_BOOLEAN: {
                    objectNode.writeValueScalar(std::get<bool>(node.defaultValue));
                    break;
                }
                case UA_TYPES_STRING: {
                    std::string stringVal = std::get<std::string>(node.defaultValue);
                    opcua::String stringValOpcua;
                    opcua::TypeConverter<std::string>::toNative(stringVal, stringValOpcua);
                    objectNode.writeValueScalar(stringValOpcua);
                    break;
                }
                default: {
                    std::cout << "Unknown datatype" << std::endl;
                    break;
                }
//                case UA_TYPES_BOOLEAN:
//                    objectNode.writeValueScalar(std::get<bool>(node.defaultValue));
//                    break;
//                case UA_TYPES_INT32:
//                    objectNode.writeValueScalar(std::get<int>(node.defaultValue));
//                    break;
//                case UA_TYPES_UINT32:
//                    objectNode.writeValueScalar(std::get<int>(node.defaultValue));
//                    break;
//                case UA_TYPES_INT64:
//                    objectNode.writeValueScalar(std::get<int>(node.defaultValue));
//                    break;
//                case UA_TYPES_UINT64:
//                    objectNode.writeValueScalar(std::get<int>(node.defaultValue));
//                    break;
//                case UA_TYPES_FLOAT:
//                    objectNode.writeValueScalar(std::get<int>(node.defaultValue));
//                    break;

            }
            objectNode.writeAccessLevel(
                    accessLevel
            );


            for (auto childNode: node.childNodes) {
                addNodeToServer(*childNode, objectNode);
            }
        }
    }

    bool Server::isRunning() {
        if (p_Server == nullptr) {
            return false;
        }

        return p_Server->isRunning();
    }

    int Server::getPort() const {
        return m_Port;
    }

    u_long Server::getConnectedClientCount() const {
        if (p_Server == nullptr) {
            return 0;
        }

        return p_Server->getSessions().size();
    }

    std::string Server::getHostname() {
        if (isRunning()) {
            auto conf = opcua::detail::getConfig(p_Server->handle());
            std::string hostnamestr = UAStringToString(conf->customHostname);
            return hostnamestr;
        }

        return m_Hostname;
    }


#pragma clang diagnostic pop


} // Opcua
// Utils
// HB