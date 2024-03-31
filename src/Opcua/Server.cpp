//
// Created by Kasper de bruin on 30/03/2024.
//

#include "Server.h"

#define OPCUA_LOCALE "en-US"

namespace HB::Utils::Opcua {

    std::string UAStringToString(const UA_String& uaString) {
        // Check if the UA_String is valid
        if (uaString.data == nullptr || uaString.length == 0) {
            return std::string(); // Return an empty string if UA_String is invalid or empty
        }

        // Construct an std::string from the data and length of UA_String
        return std::string(reinterpret_cast<char*>(uaString.data), uaString.length);
    }

    Server::Server(const std::string &mHostname, int mPort, const std::vector<Node *> &mNodes)
            : m_Hostname(mHostname), m_Port(mPort),
              p_Server(nullptr),
              m_Nodes(mNodes), m_Mutex(), m_Cond(),
              m_ServerThread(), m_RunServer() {
        HB::Utils::Opcua::Node *root = new HB::Utils::Opcua::Node("DatablocksGlobal", "DatablocksGlobal",
                                                                  "DatablocksGlobal",
                                                                  NodeType::OBJECT);
        m_Nodes.push_back(root);

        HB::Utils::Opcua::Node *oeeEnAnalyseDataNode = new HB::Utils::Opcua::Node("OEEenAnalyseData",
                                                                                  "OEEenAnalyseData",
                                                                                  "OEEenAnalyseData",
                                                                                  NodeType::OBJECT);
        root->addNode(oeeEnAnalyseDataNode);

        HB::Utils::Opcua::Node *u4BatchactiveNode = new HB::Utils::Opcua::Node("U4.bBatchactive", "U4.bBatchactive",
                                                                               "OEEenAnalyseData.U4.bBatchactive",
                                                                               false);
        oeeEnAnalyseDataNode->addNode(u4BatchactiveNode);

        HB::Utils::Opcua::Node *u4DelayedAutoNode = new HB::Utils::Opcua::Node("U4.bDelayedAuto", "U4.bDelayedAuto",
                                                                               "OEEenAnalyseData.U4.bDelayedAuto",
                                                                               false);
        oeeEnAnalyseDataNode->addNode(u4DelayedAutoNode);

        HB::Utils::Opcua::Node *u4bInCycleStopNode = new HB::Utils::Opcua::Node("U4.bInCycleStop", "U4.bInCycleStop",
                                                                                "'OEEenAnalyseData'.U4.bInCycleStop",
                                                                                false);
        oeeEnAnalyseDataNode->addNode(u4bInCycleStopNode);

        HB::Utils::Opcua::Node *u4bInStopNode = new HB::Utils::Opcua::Node("U4.bInStop", "U4.bInStop",
                                                                           "OEEenAnalyseData.U4.bInStop",
                                                                           false);
        oeeEnAnalyseDataNode->addNode(u4bInStopNode);

        HB::Utils::Opcua::Node *u4ResetNecessaryNode = new HB::Utils::Opcua::Node("U4.bResetNecessary",
                                                                                  "U4.bResetNecessary",
                                                                                  "OEEenAnalyseData.U4.bResetNecessary",
                                                                                  false);
        oeeEnAnalyseDataNode->addNode(u4ResetNecessaryNode);

        HB::Utils::Opcua::Node *iTargetQuantityNode = new HB::Utils::Opcua::Node("iTargetQuantity", "iTargetQuantity",
                                                                                 "OEEenAnalyseData.iTargetQuantity",
                                                                                 0);
        oeeEnAnalyseDataNode->addNode(iTargetQuantityNode);

        HB::Utils::Opcua::Node *sWorkOrderIdNode = new HB::Utils::Opcua::Node("sWorkOrderId", "sWorkOrderId",
                                                                              "OEEenAnalyseData.sWorkOrderId",
                                                                              "Unset");
        oeeEnAnalyseDataNode->addNode(sWorkOrderIdNode);

    }

    Server::~Server() {
        stopServer();

        for (auto &node: m_Nodes) {
            delete node;
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

        opcua::Node<opcua::Server> parentNode = p_Server->getObjectsNode();
        for (auto &node: m_Nodes) {
            addNodeToServer(*node, parentNode);
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
                    .setUserAccessLevel(opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite)
                    .setAccessLevel(opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite)
                    .setHistorizing(true);

            switch (dataTypeId) {
                case UA_TYPES_BOOLEAN:
                    attributes.setDataType(opcua::DataTypeId::Boolean);
                    break;
                case UA_TYPES_INT32:
                    attributes.setDataType(opcua::DataTypeId::Int32);
                    break;
                case UA_TYPES_UINT32:
                    attributes.setDataType(opcua::DataTypeId::UInt32);
                    break;
                case UA_TYPES_INT64:
                    attributes.setDataType(opcua::DataTypeId::Int64);
                    break;
                case UA_TYPES_UINT64:
                    attributes.setDataType(opcua::DataTypeId::UInt64);
                    break;
                case UA_TYPES_FLOAT:
                    attributes.setDataType(opcua::DataTypeId::Float);
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
                case UA_TYPES_BOOLEAN:
                    objectNode.writeValueScalar(std::get<bool>(node.defaultValue));
                    break;
                case UA_TYPES_INT32:
                    objectNode.writeValueScalar(std::get<int>(node.defaultValue));
                    break;
                case UA_TYPES_UINT32:
                    objectNode.writeValueScalar(std::get<int>(node.defaultValue));
                    break;
                case UA_TYPES_INT64:
                    objectNode.writeValueScalar(std::get<int>(node.defaultValue));
                    break;
                case UA_TYPES_UINT64:
                    objectNode.writeValueScalar(std::get<int>(node.defaultValue));
                    break;
                case UA_TYPES_FLOAT:
                    objectNode.writeValueScalar(std::get<int>(node.defaultValue));
                    break;
                case UA_TYPES_STRING:
                    std::string stringVal = std::get<std::string>(node.defaultValue);
                    opcua::String stringValOpcua;
                    opcua::TypeConverter<std::string>::toNative(stringVal, stringValOpcua);
                    objectNode.writeValueScalar(stringValOpcua);
                    objectNode.writeAccessLevel(
                            opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
                    );
                    break;
            }
            objectNode.writeAccessLevel(
                    opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
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