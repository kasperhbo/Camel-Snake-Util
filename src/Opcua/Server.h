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
        std::string name;
        std::string displayName;
        std::string description;

        std::variant<int, bool, std::string> defaultValue;
        std::vector<Node *> childNodes = {};
        NodeType type = NodeType::OBJECT;


        Node(std::string name, std::string displayName, std::string description,
             NodeType type) : Node(std::move(name), std::move(displayName), std::move(description),
                                   std::variant<int, bool, std::string>{}, {}, type) {

        }


        Node(std::string name, std::string displayName, std::string description,
             const std::variant<int, bool, std::string> &defaultValue, const std::vector<Node *> &childNodes,
             NodeType type
        ) : name(std::move(name)), displayName(std::move(displayName)),
            description(std::move(description)),
            defaultValue(defaultValue), childNodes(childNodes), type(type) {}

        void addNode(Node *node) {
            this->childNodes.emplace_back(node);
        }

        [[nodiscard]]opcua::DataTypeId getDataType() const {

            switch (defaultValue.index()) {
                case 0:
                    return opcua::DataTypeId::Int32;
                case 1:
                    return opcua::DataTypeId::Boolean;
                case 2:
                    return opcua::DataTypeId::String;
            }
            assert(!defaultValue.index() && "Value type is not set");
            return opcua::DataTypeId::Int32;
        }

        ~Node() {
            for (auto &node: childNodes) {
                delete node;
            }
        }
    };

    class Server {
    public:
        Server(const std::string &hostname, int port);

        ~Server();

        [[maybe_unused]]void startServer() {
            if (p_Server != nullptr) {
                if (p_Server->isRunning()) {
                    std::cout << "Server is already running" << std::endl;
                    return;
                } else {
                    delete p_Server;
                }
            }

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

            p_Server->run();
        }

        void addNode(Node *node) {
            m_Nodes.emplace_back(node);
        }

        [[nodiscard]] std::string getHostname() const {
            return m_Hostname;
        }

        [[nodiscard]] int getPort() const {
            return m_Port;
        }

    private:
        void addNodeToServer(const Node &node, opcua::Node<opcua::Server> &parentNode);

    private:
        std::string m_Hostname = "";
        int m_Port = 4840;

    private:
        opcua::Server *p_Server = nullptr;
        std::vector<Node *> m_Nodes = {};
    };

} // Opcua
// Utils
// HB

#endif //CAMELSNAKEUTIL_SERVER_H
