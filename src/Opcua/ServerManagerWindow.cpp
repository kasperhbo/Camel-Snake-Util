//
// Created by Kasper de bruin on 30/03/2024.
//

#include "ServerManagerWindow.h"
#include <HBUI/HBUI.h>

namespace HBUI {
    namespace Utils {
        namespace Opcua {
            // A struct to represent a leaf or a node
            struct TreeNode {
                std::string name; // Display name of the node/leaf
                std::string path; // The hierarchical path or identifier
                std::string value; // The value if this is a leaf
                bool isSelected; // Whether this item is selected
                std::vector<TreeNode> children; // Children of this node/leaf

                // Constructor for a node
                TreeNode() : name(""), path(""), value(""), isSelected(false) {}

                TreeNode(const std::string &nodeName, const std::string &nodePath)
                        : name(nodeName), path(nodePath), value(""), isSelected(false) {}

                // Constructor for a leaf
                TreeNode(const std::string &leafName, const std::string &leafPath, const std::string &leafValue)
                        : name(leafName), path(leafPath), value(leafValue), isSelected(false) {}

                // Function to determine if this is a leaf (has value)
                bool isLeaf() const {
                    return !value.empty();
                }

                // Function to add a child node
                void addChild(const TreeNode &child) {
                    children.push_back(child);
                }
            };


// Recursively draw the tree
            void DrawTreeNode(TreeNode &node) {
                if (node.isLeaf() && node.children.empty()) {
                    // It's a leaf node
                    ImGui::Selectable(node.name.c_str(), &node.isSelected);
                    ImGui::NextColumn();
                    ImGui::TextUnformatted(node.path.c_str());
                    ImGui::NextColumn();
                    ImGui::TextUnformatted(node.value.c_str());
                    ImGui::NextColumn();
                } else {
                    // It's a parent node
                    if (ImGui::TreeNode(node.name.c_str())) {
                        ImGui::NextColumn();
                        ImGui::TextUnformatted(node.path.c_str());
                        ImGui::NextColumn();
                        ImGui::TextUnformatted(node.value.c_str());
                        ImGui::NextColumn();
                        for (auto &child: node.children) {
                            DrawTreeNode(child);
                        }
                        ImGui::TreePop();
                    } else {
                        ImGui::NextColumn();
                        ImGui::NextColumn();
                        ImGui::NextColumn();
                    }
                }
            }


            // Main function to create the tree view
            void MyComplexTree(TreeNode nodes) {
                // Set headers for columns
                ImGui::Columns(3, "mycolumns"); // 3 columns
                ImGui::Text("Name");
                ImGui::NextColumn();
                ImGui::Text("Path");
                ImGui::NextColumn();
                ImGui::Text("Value");
                ImGui::NextColumn();

                DrawTreeNode(nodes);
            }

            TreeNode CreateTreeNodeFromServerNode(HB::Utils::Opcua::Node &serverNode) {
                TreeNode rootNode;
                rootNode.name = serverNode.displayName;
                rootNode.path = serverNode.nodeId   ;
                rootNode.value =
                        serverNode.defaultValue.index() == 0 ? std::to_string(std::get<int>(serverNode.defaultValue)) :
                        serverNode.defaultValue.index() == 1 ? std::to_string(std::get<bool>(serverNode.defaultValue)) :
                        std::get<std::string>(serverNode.defaultValue);

                rootNode.isSelected = false;

                for (auto &childNode: serverNode.childNodes) {
                    TreeNode childTreeNode = CreateTreeNodeFromServerNode(*childNode);
                    rootNode.addChild(childTreeNode);
                }

                return rootNode;
            }

            ServerManagerWindow::ServerManagerWindow() {
                p_Server = new HB::Utils::Opcua::Server();
            }

            void ServerManagerWindow::begin() {
                ImGui::Begin("Server Dashboard");

                // Set up the styling
                ImGui::StyleColorsDark(); // Or custom style configuration

                // Sidebar
                ImGui::BeginChild("left pane", ImVec2(150, 0), ImGuiChildFlags_Border | ImGuiChildFlags_ResizeX);
                { // Server navigation and status indicators
                    if (ImGui::Button("Start Server")) {
                        startServer();
                    }
                    if (ImGui::Button("Stop Server")) {
                        stopServer();
                    }
                    if (ImGui::Button("Add Variable Node")) {
                        addVariableNode("VariableNode", "Variable Node", "A variable node", 0);
                    }
                    if (ImGui::Button("Add Object Node")) {
                        addObjectNode("ObjectNode", "Object Node", "An object node");
                    }
                }
                ImGui::EndChild();
                ImGui::SameLine();

                ImGui::BeginChild("item view",
                                  ImVec2(0, -ImGui::GetFrameHeightWithSpacing())); // Leave room for 1 line below us
                {
                    // Top Bar
                    ImGui::Text("Server IP: %s", "localhost");

                    ImGui::Columns(2, "Server Info"); // 2-ways split
                    ImGui::Text(" Status: ");
                    ImGui::NextColumn();
                    ImGui::Text("Running");
                    ImGui::NextColumn();
                    ImGui::Text(" Port:");
                    ImGui::NextColumn();
                    ImGui::Text("4840");
                    ImGui::NextColumn();
                    ImGui::Text(" Nodes:");
                    ImGui::NextColumn();
                    ImGui::Text("0");
                    ImGui::NextColumn();
                    ImGui::Text(" Clients:");
                    ImGui::NextColumn();
                    ImGui::Text("0");
                    ImGui::NextColumn();
                    ImGui::Text(" Uptime:");
                    ImGui::NextColumn();
                    ImGui::Text("00:00:00");
                    ImGui::NextColumn();
                    ImGui::Columns(1);

                    ImGui::Separator();
                }


                ImGui::Text("Nodes");
                ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {0, 0});
                ImGui::BeginChild("###Nodes", ImVec2(0, ImGui::GetContentRegionAvail().y / 3),
                                  ImGuiChildFlags_Border | ImGuiChildFlags_ResizeY);
                ImGui::PopStyleVar();

                ImGui::BeginChild("##NodeList", ImVec2(ImGui::GetContentRegionAvail().x / 2, 0), true);
                ImGui::Text("Node List");

                for (auto &node: p_Server->getNodes()) {
                    TreeNode nodeTree = CreateTreeNodeFromServerNode(*node);
                    MyComplexTree(nodeTree);
                }

                ImGui::EndChild();

                ImGui::SameLine(0, 0);


                ImGui::BeginChild("NodeProperties", ImVec2(0, 0), true);
                ImGui::Text("Node Properties");

                ImGui::EndChild();


                ImGui::EndChild();

                //Log
                ImGui::Text("Log");
                ImGui::BeginChild("Log", ImVec2(0, ImGui::GetContentRegionAvail().y), true);
                ImGui::Text("Log");
                ImGui::EndChild();

                ImGui::EndChild();
                ImGui::End();
            }

            void ServerManagerWindow::end() {

            }

            void ServerManagerWindow::startServer() {
                p_Server->startServer();
            }

            void ServerManagerWindow::stopServer() {
                p_Server->stopServer();
            }

            void ServerManagerWindow::addNode(HB::Utils::Opcua::Node *node) {
                p_Server->addNode(node);
            }

            HB::Utils::Opcua::Node *
            ServerManagerWindow::addVariableNode(std::string name, std::string displayName, std::string description,
                                                 std::variant<int, bool, std::string> defaultValue,
                                                 HB::Utils::Opcua::Node *parentNode) {
                HB::Utils::Opcua::Node *node = new HB::Utils::Opcua::Node(name, displayName, description, defaultValue,
                                                                          {}, HB::Utils::Opcua::NodeType::VARIABLE);
                parentNode->addNode(node);

                return node;
            }

            HB::Utils::Opcua::Node *
            ServerManagerWindow::addVariableNode(std::string name, std::string displayName, std::string description,
                                                 std::variant<int, bool, std::string> defaultValue) {

                HB::Utils::Opcua::Node *node = new HB::Utils::Opcua::Node(name, displayName, description, defaultValue,
                                                                          {}, HB::Utils::Opcua::NodeType::VARIABLE);
                addNode(node);
                return node;
            }

            HB::Utils::Opcua::Node *
            ServerManagerWindow::addObjectNode(std::string name, std::string displayName, std::string description) {
                auto *node = new HB::Utils::Opcua::Node(name, displayName, description,
                                                        HB::Utils::Opcua::NodeType::OBJECT);
                addNode(node);
                return node;
            }
        } // Opcua
    } // Utils
} // HBUI