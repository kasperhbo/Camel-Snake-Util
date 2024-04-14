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
        using MyVariant = std::variant<uint16_t, bool, std::string>;

        enum class MyVariantType {
            uint16, boolean, string
        };

        template<MyVariantType Type, typename T>
        struct is_variant_type : std::false_type {
        };

        template<>
        struct is_variant_type<MyVariantType::uint16, uint16_t> : std::true_type {
        };
        template<>
        struct is_variant_type<MyVariantType::boolean, bool> : std::true_type {
        };
        template<>
        struct is_variant_type<MyVariantType::string, std::string> : std::true_type {
        };

        template<MyVariantType VT>
        bool check_variant_type(const MyVariant &myvar) const {
            return std::visit([&](const auto &arg) {
                return is_variant_type<VT, std::decay_t<decltype(arg)>>::value;
            }, myvar);
        }

        std::string displayName;
        std::string browserName;
        std::string nodeId;

        MyVariant defaultValue = {};
        std::vector<Node *> childNodes = {};
        NodeType type = NodeType::OBJECT;

        Node(std::string displayName, std::string browserName, std::string nodeId, NodeType type)
                : displayName(std::move(displayName)), browserName(std::move(browserName)), nodeId(std::move(nodeId)),
                  type(type) {}

        Node(std::string displayName, std::string browserName, std::string nodeId, MyVariant defaultValue,
             NodeType type)
                : displayName(std::move(displayName)), browserName(std::move(browserName)), nodeId(std::move(nodeId)),
                  defaultValue(std::move(defaultValue)), type(type) {

        }

        void addNode(Node *node) {
            this->childNodes.emplace_back(node);
        }

        int getDataType() const {
            if (check_variant_type<MyVariantType::uint16>(defaultValue)) {
                return UA_TYPES_UINT16;
            } else if (check_variant_type<MyVariantType::boolean>(defaultValue)) {
                return UA_TYPES_BOOLEAN;
            } else if (check_variant_type<MyVariantType::string>(defaultValue)) {
                return UA_TYPES_STRING;
            } else {
                UA_assert(false && "Value type is not set");
            }
            assert(!defaultValue.index() && "Value type is not set");
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

        Server(std::string mHostname, int mPort, const std::vector<Node *> &mNodes);

        ~Server();

        bool isRunning();

        int getPort() const;

        u_long getConnectedClientCount() const;

        std::string getHostname();

    public:
        void addNode(Node *node) {
            m_Nodes[node->nodeId] = node;
        }

        void startServer();

        void stopServer();

    public:
        std::vector<Node *> getNodes() {
            std::vector<Node *> nodes;
            nodes.reserve(m_Nodes.size());
            for (auto &node: m_Nodes) {
                nodes.push_back(node.second);
            }
            return nodes;
        }

    private:
        void addNodeToServer(const Node &node, opcua::Node<opcua::Server> &parentNode);


    private:
        std::string m_Hostname = "";
        int m_Port = 4840;

    private:
        opcua::Server *p_Server = nullptr;
        std::unordered_map<std::string, Node *> m_Nodes = {};

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
