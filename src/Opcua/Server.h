//
// Created by Kasper de bruin on 30/03/2024.
//

#ifndef CAMELSNAKEUTIL_SERVER_H
#define CAMELSNAKEUTIL_SERVER_H

#include <iostream>
#include <open62541pp/open62541pp.h>
#include <utility>
#include <vector>

namespace HB::Utils::Opcua {

    enum NodeType {
        OBJECT,
        VARIABLE
    };

    struct Node {
        std::string displayName;
        std::string browserName;
        std::string nodeId;

        std::variant<int, bool, std::string> defaultValue;
        std::vector<Node *> childNodes = {};
        NodeType type = NodeType::OBJECT;

        Node(std::string displayName, std::string browserName, std::string nodeId, NodeType type)
            : displayName(std::move(displayName)), browserName(std::move(browserName)), nodeId(std::move(nodeId)), type(type) {}

        Node(std::string displayName, std::string browserName, std::string nodeId,  std::variant<int, bool, std::string> defaultValue)
                : displayName(std::move(displayName)), browserName(std::move(browserName)), nodeId(std::move(nodeId)), type(NodeType::VARIABLE), defaultValue(std::move(defaultValue)) {}

        Node(std::string displayName, std::string browserName, std::string nodeId,
             const std::variant<int, bool, std::string> &defaultValue, const std::vector<Node *> &childNodes,
             NodeType type
        ) : displayName(std::move(displayName)), browserName(std::move(browserName)),
            nodeId(std::move(nodeId)),
            defaultValue(defaultValue), childNodes(childNodes), type(type) {}


        Node(std::string displayName, std::string browserName, std::string nodeId,
             const std::variant<int, bool, std::string> &defaultValue, NodeType type
        ) : displayName(std::move(displayName)), browserName(std::move(browserName)),
            nodeId(std::move(nodeId)),
            defaultValue(defaultValue), type(type) {}


        void addNode(Node *node) {
            this->childNodes.emplace_back(node);
        }

        [[nodiscard]]int getDataType() const {

            switch (defaultValue.index()) {
                case 0:
                    return UA_TYPES_INT32;
                case 1:
                    return UA_TYPES_BOOLEAN;
                case 2:
                    return UA_TYPES_STRING;
            }
            assert(!defaultValue.index() && "Value type is not set");
            return UA_TYPES_VARIANT;
        }

        ~Node() {
            for (auto &node: childNodes) {
                delete node;
            }
        }
    };

    class Server {
    public:
        Server() : Server("", 4840) {}

        Server(const std::string &hostname, int port) : Server(hostname, port, {}) {}

        Server(const std::string &mHostname, int mPort, const std::vector<Node *> &mNodes);

        ~Server();

        bool isRunning();

        int getPort() const;

        u_long getConnectedClientCount() const;

        std::string getHostname();

    public:
        void addNode(Node *node) {
            m_Nodes.emplace_back(node);
        }

        void startServer();

        void stopServer();

    public:
        std::vector<Node *> getNodes() {
            return m_Nodes;
        }

    private:
        void addNodeToServer(const Node &node, opcua::Node<opcua::Server> &parentNode);


    private:
        std::string m_Hostname = "";
        int m_Port = 4840;

    private:
        opcua::Server *p_Server = nullptr;
        std::vector<Node *> m_Nodes = {};

        std::mutex m_Mutex;             // Mutex to protect shared resources
        std::condition_variable m_Cond; // Condition variable for synchronization
        std::thread m_ServerThread;     // Thread object for the server
        std::atomic<bool> m_RunServer;  // Flag to control the server's running state
        void serverThreadFunction();
    };

} // Opcua
// Utils
// HB

#endif //CAMELSNAKEUTIL_SERVER_H
