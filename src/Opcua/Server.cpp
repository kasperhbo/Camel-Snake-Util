//
// Created by Kasper de bruin on 30/03/2024.
//

#include "Server.h"

#define OPCUA_LOCALE "en-US"

namespace HB::Utils::Opcua {
    Server::Server(const std::string &mHostname, int mPort, const std::vector<Node *> &mNodes)
            : m_Hostname(mHostname), m_Port(mPort),
              p_Server(nullptr),
              m_Nodes(mNodes), m_Mutex(), m_Cond(),
              m_ServerThread(), m_RunServer() {
        HB::Utils::Opcua::Node *root = new HB::Utils::Opcua::Node("DatablocksGlobal", "DatablocksGlobal", "DatablocksGlobal",
                                                NodeType::OBJECT);
        m_Nodes.push_back(root);


//        auto oeeEnAnalyseDataNode = root->addNode(
//                {1, "OEEenAnalyseData"},
//                "OEEenAnalyseData",
//                opcua::ObjectAttributes{}
//                        .setDisplayName({"en-US", "OEEenAnalyseData"})
//                        .setDescription({"en-US", "OEEenAnalyseData"})
//        );
//
//        auto generalBatchactiveNode = oeeEnAnalyseDataNode.addVariable(
//                {1, "General.bBatchActive"},
//                "General.bBatchactive",
//                opcua::VariableAttributes{}
//                        .setDisplayName({"en-US", "General.bBatchActive"})
//                        .setDescription({"en-US", "General.bBatchActive"})
//                        .setDataType<UA_Boolean>()
//        );  // This might need to be changed based on the type converter
//        generalBatchactiveNode.writeValueScalar(false);
//        generalBatchactiveNode.writeAccessLevel(
//                opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
//        );

//        opcua::Node<opcua::Server> u4BatchactiveNode = oeeEnAnalyseDataNode.addVariable(
//                {1, "U4.bBatchactive"},
//                "U4.bBatchactive",
//                opcua::VariableAttributes{}
//                        .setDisplayName({"en-US", "U4.bBatchactive"})
//                        .setDescription({"en-US", "U4.bBatchactive"})
//                        .setDataType<UA_Boolean>()
//        );
//        u4BatchactiveNode.writeValueScalar(false);
//        u4BatchactiveNode.writeAccessLevel(
//                opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
//        );
//
//        auto u4DelayedAutoNode = oeeEnAnalyseDataNode.addVariable(
//                {1, "U4.bDelayedAuto"},
//                "U4.bDelayedAuto",
//                opcua::VariableAttributes{}
//                        .setDisplayName({"en-US", "U4.bDelayedAuto"})
//                        .setDescription({"en-US", "U4.bDelayedAuto"})
//                        .setDataType<UA_Boolean>()
//        );
//
//        u4DelayedAutoNode.writeValueScalar(false);
//        u4DelayedAutoNode.writeAccessLevel(
//                opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
//        );
//
//        auto u4bInCycleStopNode = oeeEnAnalyseDataNode.addVariable(
//                {1, "U4.bInCycleStop"},
//                "U4.bInCycleStop",
//                opcua::VariableAttributes{}
//                        .setDisplayName({"en-US", "U4.bInCycleStop"})
//                        .setDescription({"en-US", "U4.bInCycleStop"})
//                        .setDataType<UA_Boolean>()
//        );
//
//        u4bInCycleStopNode.writeValueScalar(false);
//        u4bInCycleStopNode.writeAccessLevel(
//                opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
//        );
//
//        auto u4bInStopNode = oeeEnAnalyseDataNode.addVariable(
//                {1, "U4.bInStop"},
//                "U4.bInStop",
//                opcua::VariableAttributes{}
//                        .setDisplayName({"en-US", "U4.bInStop"})
//                        .setDescription({"en-US", "U4.bInStop"})
//                        .setDataType<UA_Boolean>()
//        );
//
//        u4bInStopNode.writeValueScalar(false);
//        u4bInStopNode.writeAccessLevel(
//                opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
//        );
//
//        auto u4ResetNecessaryNode = oeeEnAnalyseDataNode.addVariable(
//                {1, "U4.bResetNecessary"},
//                "U4.bResetNecessary",
//                opcua::VariableAttributes{}
//                        .setDisplayName({"en-US", "U4.bResetNecessary"})
//                        .setDescription({"en-US", "U4.bResetNecessary"})
//                        .setDataType<UA_Boolean>()
//        );
//
//        u4ResetNecessaryNode.writeValueScalar(false);
//        u4ResetNecessaryNode.writeAccessLevel(
//                opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
//        );
//
//        auto iTargetQuantityNode = oeeEnAnalyseDataNode.addVariable(
//                {1, "iTargetQuantity"},
//                "iTargetQuantity",
//                opcua::VariableAttributes{}
//                        .setDisplayName({"en-US", "iTargetQuantity"})
//                        .setDescription({"en-US", "iTargetQuantity"})
//                        .setDataType<int>()
//        );
//
//        iTargetQuantityNode.writeValueScalar(0);
//        iTargetQuantityNode.writeAccessLevel(
//                opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
//        );
//
//        opcua::Node sWorkOrderIdNode = oeeEnAnalyseDataNode.addVariable(
//                {1, "sWorkOrderId"},
//                "sWorkOrderId",
//                opcua::VariableAttributes{}
//                        .setDisplayName({"en-US", "Work Order ID"})
//                        .setDescription({"en-US", "The identifier for the work order"})
//                        .setDataType<opcua::String>() // This might need to be changed based on the type converter
//        );

        HB::Utils::Opcua::Node *oeeEnAnalyseDataNode = new HB::Utils::Opcua::Node("OEEenAnalyseData", "OEEenAnalyseData", "OEEenAnalyseData",
                                                NodeType::OBJECT);
        root->addNode(oeeEnAnalyseDataNode);

        HB::Utils::Opcua::Node *u4BatchactiveNode = new HB::Utils::Opcua::Node("U4.bBatchactive", "U4.bBatchactive", "OEEenAnalyseData.U4.bBatchactive",
                                                false);
        oeeEnAnalyseDataNode->addNode(u4BatchactiveNode);

        HB::Utils::Opcua::Node *u4DelayedAutoNode = new HB::Utils::Opcua::Node("U4.bDelayedAuto", "U4.bDelayedAuto", "OEEenAnalyseData.U4.bDelayedAuto",
                                                false);
        oeeEnAnalyseDataNode->addNode(u4DelayedAutoNode);

        HB::Utils::Opcua::Node *u4bInCycleStopNode = new HB::Utils::Opcua::Node("U4.bInCycleStop", "U4.bInCycleStop", "'OEEenAnalyseData'.U4.bInCycleStop",
                                                false);
        oeeEnAnalyseDataNode->addNode(u4bInCycleStopNode);

        HB::Utils::Opcua::Node *u4bInStopNode = new HB::Utils::Opcua::Node("U4.bInStop", "U4.bInStop", "OEEenAnalyseData.U4.bInStop",
                                                false);
        oeeEnAnalyseDataNode->addNode(u4bInStopNode);

        HB::Utils::Opcua::Node *u4ResetNecessaryNode = new HB::Utils::Opcua::Node("U4.bResetNecessary", "U4.bResetNecessary", "OEEenAnalyseData.U4.bResetNecessary",
                                                false);
        oeeEnAnalyseDataNode->addNode(u4ResetNecessaryNode);

        HB::Utils::Opcua::Node *iTargetQuantityNode = new HB::Utils::Opcua::Node("iTargetQuantity", "iTargetQuantity", "OEEenAnalyseData.iTargetQuantity",
                                                0);
        oeeEnAnalyseDataNode->addNode(iTargetQuantityNode);

        HB::Utils::Opcua::Node *sWorkOrderIdNode = new HB::Utils::Opcua::Node("sWorkOrderId", "sWorkOrderId", "OEEenAnalyseData.sWorkOrderId",
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

        if (!m_Hostname.empty()) {
            p_Server->setCustomHostname(m_Hostname);//else use the pc's hostname
        }

        p_Server->setApplicationUri("opcua:open62541pp.server.application");
        p_Server->setProductUri("https://open62541pp.github.io");

        opcua::Node<opcua::Server> parentNode = p_Server->getObjectsNode();
        for (auto &node: m_Nodes) {
            addNodeToServer(*node, parentNode);
        }

        for (auto &node: m_Nodes) {
            addNodeToServer(*node, parentNode);
        }

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
            opcua::DataTypeId dataTypeId = node.getDataType();

            auto objectNode = parentNode.addVariable(
                    {1, node.nodeId},
                    node.browserName,
                    opcua::VariableAttributes{
                    }
                            .setDisplayName({OPCUA_LOCALE, node.displayName})
                            .setDescription({OPCUA_LOCALE, node.nodeId})
                            .setDataType(dataTypeId)
                            .setUserAccessLevel(opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite)
                            .setAccessLevel(opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite)
                            .setHistorizing(true)
            );

            for (auto childNode: node.childNodes) {
                addNodeToServer(*childNode, objectNode);
            }
        }
    }


#pragma clang diagnostic pop


} // Opcua
// Utils
// HB