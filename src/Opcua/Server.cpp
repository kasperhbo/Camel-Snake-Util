//
// Created by Kasper de bruin on 30/03/2024.
//

#include "Server.h"

#define OPCUA_LOCALE "en-US"

namespace HB::Utils::Opcua {
    Server::Server(const std::string &hostname, int port) {
        m_Hostname = hostname;
        m_Port = port;
    }

    Server::~Server() {
        if (p_Server != nullptr) {
            if (p_Server->isRunning()) {
                p_Server->stop();
            }

            delete p_Server;
        }

        for (auto &node: m_Nodes) {
            delete node;
        }
    }


#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
    void Server::addNodeToServer(const HB::Utils::Opcua::Node &node, opcua::Node<opcua::Server> &parentNode) {
        if (p_Server == nullptr) {
            std::cout << "Server is nullptr" << std::endl;
            return;
        }
        if (node.type == NodeType::OBJECT) {
            auto objectNode = parentNode.addObject(
                    {1, node.name},
                    node.displayName,
                    opcua::ObjectAttributes{}
                            .setDisplayName({OPCUA_LOCALE, node.displayName})
                            .setDescription({OPCUA_LOCALE, node.description})
            );
            for (auto childNode: node.childNodes) {
                addNodeToServer(*childNode, objectNode);
            }
        } else if (node.type == NodeType::VARIABLE) {
            opcua::DataTypeId dataTypeId = node.getDataType();

            auto objectNode = parentNode.addVariable(
                    {1, node.name},
                    node.displayName,
                    opcua::VariableAttributes{}
                            .setDisplayName({OPCUA_LOCALE, node.displayName})
                            .setDescription({OPCUA_LOCALE, node.description})
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