//
// Created by Kasper de bruin on 30/03/2024.
//

#include "ServerManagerWindow.h"
#include <HBUI/HBUI.h>

namespace HBUI {
    namespace Utils {
        namespace Opcua {
            void drawNodeData(TreeNode &node) {
                ImGui::TableNextColumn();
                ImGui::TextUnformatted(node.path.c_str());
                ImGui::TableNextColumn();
                ImGui::TextUnformatted(node.value.c_str());
                ImGui::TableNextColumn();
            }
            // A struct to represent a leaf or a node
            void ServerManagerWindow::DrawTreeNode(TreeNode &node) {

                ImGui::TableNextRow();
                ImGui::TableSetColumnIndex(0);

                if (node.isLeaf() && node.children.empty()) {
                    // It's a leaf node
                    if (ImGui::Selectable(node.name.c_str(), node.isSelected, ImGuiSelectableFlags_SpanAllColumns)) {
                        node.isSelected = true;
                        p_SelectedNode = node.node;
                    }
                    drawNodeData(node);
                } else {
                    // It's a parent node
                    ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick
                                                | ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_SpanFullWidth | ImGuiTreeNodeFlags_SpanAllColumns;
                    if(p_SelectedNode == node.node) {
                        flags |= ImGuiTreeNodeFlags_Selected;
                    }

                    bool node_open = ImGui::TreeNodeEx(node.name.c_str(), flags);
                    if (ImGui::IsItemClicked()) {
                        node.isSelected = true;
                        p_SelectedNode = node.node;
                    }
                    if (node_open) {
                        drawNodeData(node);
                        for (auto &child: node.children) {
                            DrawTreeNode(child);
                        }
                        ImGui::TreePop();
                    } else {
                        // The node is collapsed, but you can still draw other relevant data here
                        // This is optional, depending on your use case
                        drawNodeData(node);
                    }
//                    if (ImGui::TreeNodeEx(node.name.c_str(),flags)) {
//                        if (ImGui::IsItemClicked())
//                        {
//                            node.isSelected = true;
//                            p_SelectedNode = node.node;
//                        }
//                        drawNodeData(node);
//                        for (auto &child: node.children) {
//                            DrawTreeNode(child);
//                        }
//                        ImGui::TreePop();
//                    } else {
//                        drawNodeData(node);
//                    }
                }
            }

            // Main function to create the tree view
            void ServerManagerWindow::MyComplexTree(TreeNode nodes) {

                if (ImGui::BeginTable("table", 3,
                                      ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable | ImGuiTableFlags_ScrollY |
                                      ImGuiTableFlags_ScrollX)) {
                    ImGui::TableSetupColumn("Name");
                    ImGui::TableSetupColumn("Path");
                    ImGui::TableSetupColumn("Value");
                    ImGui::TableHeadersRow();

                    DrawTreeNode(nodes);
                    ImGui::EndTable();
                }
            }

            TreeNode ServerManagerWindow::CreateTreeNodeFromServerNode(HB::Utils::Opcua::Node &serverNode) {
                TreeNode rootNode;
                rootNode.name = serverNode.displayName;
                rootNode.path = serverNode.nodeId;
                rootNode.value =
                        serverNode.defaultValue.index() == 0 ? std::to_string(std::get<int>(serverNode.defaultValue)) :
                        serverNode.defaultValue.index() == 1 ? std::to_string(std::get<bool>(serverNode.defaultValue)) :
                        std::get<std::string>(serverNode.defaultValue);
                rootNode.node = &serverNode;

                rootNode.isSelected = false;

                for (auto &childNode: serverNode.childNodes) {
                    TreeNode childTreeNode = CreateTreeNodeFromServerNode(*childNode);
                    rootNode.addChild(childTreeNode);
                }

                return rootNode;
            }

            ServerManagerWindow::ServerManagerWindow() {
                p_Server = new HB::Utils::Opcua::Server();
                std::vector<HB::Utils::Opcua::Node *> m_Nodes;
                HB::Utils::Opcua::Node *root = new HB::Utils::Opcua::Node("DatablocksGlobal", "DatablocksGlobal",
                                                                          "DatablocksGlobal",
                                                                          HB::Utils::Opcua::NodeType::OBJECT);
                m_Nodes.push_back(root);

                HB::Utils::Opcua::Node *oeeEnAnalyseDataNode = new HB::Utils::Opcua::Node("OEEenAnalyseData",
                                                                                          "OEEenAnalyseData",
                                                                                          "OEEenAnalyseData",
                                                                                          HB::Utils::Opcua::NodeType::OBJECT);
                root->addNode(oeeEnAnalyseDataNode);

                HB::Utils::Opcua::Node *u4BatchactiveNode = new HB::Utils::Opcua::Node("U4.bBatchactive",
                                                                                       "U4.bBatchactive",
                                                                                       "OEEenAnalyseData.U4.bBatchactive",
                                                                                       false);
                oeeEnAnalyseDataNode->addNode(u4BatchactiveNode);

                HB::Utils::Opcua::Node *u4DelayedAutoNode = new HB::Utils::Opcua::Node("U4.bDelayedAuto",
                                                                                       "U4.bDelayedAuto",
                                                                                       "OEEenAnalyseData.U4.bDelayedAuto",
                                                                                       false);
                oeeEnAnalyseDataNode->addNode(u4DelayedAutoNode);

                HB::Utils::Opcua::Node *u4bInCycleStopNode = new HB::Utils::Opcua::Node("U4.bInCycleStop",
                                                                                        "U4.bInCycleStop",
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

                HB::Utils::Opcua::Node *iTargetQuantityNode = new HB::Utils::Opcua::Node("iTargetQuantity",
                                                                                         "iTargetQuantity",
                                                                                         "OEEenAnalyseData.iTargetQuantity",
                                                                                         0);
                oeeEnAnalyseDataNode->addNode(iTargetQuantityNode);

                HB::Utils::Opcua::Node *sWorkOrderIdNode = new HB::Utils::Opcua::Node("sWorkOrderId", "sWorkOrderId",
                                                                                      "OEEenAnalyseData.sWorkOrderId",
                                                                                      "Unset");
                oeeEnAnalyseDataNode->addNode(sWorkOrderIdNode);

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
                    ImGui::Columns(2, "Server Info"); // 2-ways split
                    ImGui::Text("Hostname: ");
                    ImGui::NextColumn();
                    ImGui::InputText("##Hostname", const_cast<char *>(p_Server->getHostname().c_str()), 256);
                    ImGui::NextColumn();
                    ImGui::Text(" Status: ");
                    ImGui::NextColumn();
                    ImGui::Text(p_Server->isRunning() ? "Running" : "Stopped");
                    ImGui::NextColumn();
                    ImGui::Text(" Port:");
                    ImGui::NextColumn();
                    ImGui::Text("%d", p_Server->getPort());
                    ImGui::NextColumn();
                    ImGui::Text(" Nodes:");
                    ImGui::NextColumn();
                    ImGui::Text("%zu", p_Server->getNodes().size());
                    ImGui::NextColumn();
                    ImGui::Text(" Clients:");
                    ImGui::NextColumn();
                    ImGui::Text("%lu", p_Server->getConnectedClientCount());
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
                if (p_SelectedNode != nullptr) {
                    ImGui::Text("Name: %s", p_SelectedNode->displayName.c_str());
                    ImGui::Text("Path: %s", p_SelectedNode->nodeId.c_str());
                    switch (p_SelectedNode->getDataType()) {
                        case UA_TYPES_INT32:
                            if(ImGui::InputInt("Value", &std::get<int>(p_SelectedNode->defaultValue))){
                                std::cout << "Int changed" << std::endl;
                                p_SelectedNode->defaultValue = std::get<int>(p_SelectedNode->defaultValue);
                            }
                            break;
                        case UA_TYPES_BOOLEAN:

                            if(ImGui::Checkbox("Value", &std::get<bool>(p_SelectedNode->defaultValue))){
                                std::cout << "Checkbox changed" << std::endl;
                            }
                            break;
                        case UA_TYPES_STRING:
                            char buffer[256];
                            strcpy(buffer, std::get<std::string>(p_SelectedNode->defaultValue).c_str());
                            ImGui::InputText("Value", buffer, 256);
                            p_SelectedNode->defaultValue = std::string(buffer);
                            break;

                    }
                }

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
//                for (auto &node: p_Server->getNodes()) {
//                    delete node;
//                }
//                p_Server->getNodes().clear();
//                for (auto &node: p_Server->getNodes()) {
//                    delete node;
//                }
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