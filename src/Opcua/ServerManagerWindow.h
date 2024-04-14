//
// Created by Kasper de bruin on 30/03/2024.
//

#ifndef CAMELSNAKEUTIL_SERVERMANAGERWINDOW_H
#define CAMELSNAKEUTIL_SERVERMANAGERWINDOW_H

#include <HBUI/HBUI.h>
#include "Server.h"

namespace HBUI::Utils::Opcua {
    struct TreeNode {
        std::string name; // Display name of the node/leaf
        std::string path; // The hierarchical path or identifier
        std::string value; // The value if this is a leaf
        bool isSelected; // Whether this item is selected
        std::vector<TreeNode> children; // Children of this node/leaf
        HB::Utils::Opcua::Node *node;

        // Function to determine if this is a leaf (has value)
        bool isLeaf() const {
            return !value.empty();
        }

        // Function to add a child node
        void addChild(const TreeNode &child) {
            children.push_back(child);
        }
    };
    class ServerManagerWindow {
    public:
        ServerManagerWindow();

        ~ServerManagerWindow() = default;

    public:
        void begin();

        void end();

        void startServer();

        void stopServer();

        void addNode(HB::Utils::Opcua::Node *node);

        HB::Utils::Opcua::Node *addVariableNode(std::string name, std::string displayName, std::string description,
                                                std::variant<uint16_t, bool, std::string> defaultValue);

        HB::Utils::Opcua::Node *addObjectNode(std::string name, std::string displayName, std::string description);

        HB::Utils::Opcua::Node *addVariableNode(std::string name, std::string displayName, std::string description,
                                                std::variant<uint16_t, bool, std::string> defaultValue,
                                                HB::Utils::Opcua::Node *parentNode);

    private:
        const std::string label = "Server Manager";
        HB::Utils::Opcua::Server *p_Server = nullptr;
        HB::Utils::Opcua::Node *p_SelectedNode = nullptr;
        //inputs
    private:
        std::string hostname = "localhost";
        int port = 4840;


        HBUI::Utils::Opcua::TreeNode CreateTreeNodeFromServerNode(HB::Utils::Opcua::Node &serverNode);

        void MyComplexTree(HBUI::Utils::Opcua::TreeNode nodes);

        void DrawTreeNode(TreeNode &node);
    };
} // Opcua
// Utils
// HBUI

#endif //CAMELSNAKEUTIL_SERVERMANAGERWINDOW_H
