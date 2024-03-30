//
// Created by Kasper de bruin on 19/03/2024.
//

#include "Application.h"
#include <HBUI/HBUI.h>
#include "Certificates/Windows/CertificateGeneratorWindow.h"
#include "Opcua/Server.h"
#include <iostream>


namespace HB::Utils {
    Application::Application() {
        HBUI::addDefaultIcon("NF_ICON_snake", NF_ICON_snake);
        HBUI::addDefaultIcon("NF_ICON_certificate1", NF_ICON_certificate1);
        HBUI::initialize("Hello, World!", 1280, 720);

        run();
    }

    void Application::run() {
        startOpcuaServer();
        while (!HBUI::wantToClose()) {
            render();
        }

    }

    void Application::render() {
        HBUI::startFrame();
        HBUI::beginTaskBar("HorizontalTaskBar", {0, 0});
        HBUI::iconButton(HBUI::getIcon("NF_ICON_snake"));
        auto btn = HBUI::iconButton(HBUI::getIcon("NF_ICON_certificate1"));
        if (btn == HBButtonState_Clicked) {
            std::cout << "Hovered" << std::endl;
        }
        HBUI::endTaskBar();
        ImGui::ShowDemoWindow(nullptr);

        ImGui::Begin("Fonts");

        ImGui::Text("Hello, world!");
        ImGui::Text("This is some useful text.");
        ImGui::End();

        HBUI::endFrame();
    }

//    auto dataBlocksGeneralNode = parentNode.addObject(
//            {1, "DataBlocksGeneral"},
//            "DataBlocksGeneral",
//            opcua::ObjectAttributes{}
//                    .setDisplayName({"en-US", "DataBlocksGeneral"})
//                    .setDescription({"en-US", "DataBlocksGeneral"})
//    );
//
//    auto oeeEnAnalyseDataNode = dataBlocksGeneralNode.addObject(
//            {1, "OEEenAnalyseData"},
//            "OEEenAnalyseData",
//            opcua::ObjectAttributes{}
//                    .setDisplayName({"en-US", "OEEenAnalyseData"})
//                    .setDescription({"en-US", "OEEenAnalyseData"})
//    );
//
//    auto generalBatchactiveNode = oeeEnAnalyseDataNode.addVariable(
//            {1, "General.bBatchActive"},
//            "General.bBatchactive",
//            opcua::VariableAttributes{}
//                    .setDisplayName({"en-US", "General.bBatchActive"})
//                    .setDescription({"en-US", "General.bBatchActive"})
//                    .setDataType<UA_Boolean>()
//    );
//    generalBatchactiveNode.writeValueScalar(false);
//    generalBatchactiveNode.writeAccessLevel(
//            opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
//    );
//
//    opcua::Node<opcua::Server> u4BatchactiveNode = oeeEnAnalyseDataNode.addVariable(
//            {1, "U4.bBatchactive"},
//            "U4.bBatchactive",
//            opcua::VariableAttributes{}
//                    .setDisplayName({"en-US", "U4.bBatchactive"})
//                    .setDescription({"en-US", "U4.bBatchactive"})
//                    .setDataType<UA_Boolean>()
//    );
//    u4BatchactiveNode.writeValueScalar(false);
//    u4BatchactiveNode.writeAccessLevel(
//            opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
//    );
//
//    auto u4DelayedAutoNode = oeeEnAnalyseDataNode.addVariable(
//            {1, "U4.bDelayedAuto"},
//            "U4.bDelayedAuto",
//            opcua::VariableAttributes{}
//                    .setDisplayName({"en-US", "U4.bDelayedAuto"})
//                    .setDescription({"en-US", "U4.bDelayedAuto"})
//                    .setDataType<UA_Boolean>()
//    );
//
//    u4DelayedAutoNode.writeValueScalar(false);
//    u4DelayedAutoNode.writeAccessLevel(
//            opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
//    );
//
//    auto u4bInCycleStopNode = oeeEnAnalyseDataNode.addVariable(
//            {1, "U4.bInCycleStop"},
//            "U4.bInCycleStop",
//            opcua::VariableAttributes{}
//                    .setDisplayName({"en-US", "U4.bInCycleStop"})
//                    .setDescription({"en-US", "U4.bInCycleStop"})
//                    .setDataType<UA_Boolean>()
//    );
//
//    u4bInCycleStopNode.writeValueScalar(false);
//    u4bInCycleStopNode.writeAccessLevel(
//            opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
//    );
//
//    auto u4bInStopNode = oeeEnAnalyseDataNode.addVariable(
//            {1, "U4.bInStop"},
//            "U4.bInStop",
//            opcua::VariableAttributes{}
//                    .setDisplayName({"en-US", "U4.bInStop"})
//                    .setDescription({"en-US", "U4.bInStop"})
//                    .setDataType<UA_Boolean>()
//    );
//
//    u4bInStopNode.writeValueScalar(false);
//    u4bInStopNode.writeAccessLevel(
//            opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
//    );
//
//    auto u4ResetNecessaryNode = oeeEnAnalyseDataNode.addVariable(
//            {1, "U4.bResetNecessary"},
//            "U4.bResetNecessary",
//            opcua::VariableAttributes{}
//                    .setDisplayName({"en-US", "U4.bResetNecessary"})
//                    .setDescription({"en-US", "U4.bResetNecessary"})
//                    .setDataType<UA_Boolean>()
//    );
//
//    u4ResetNecessaryNode.writeValueScalar(false);
//    u4ResetNecessaryNode.writeAccessLevel(
//            opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
//    );
//
//    auto iTargetQuantityNode = oeeEnAnalyseDataNode.addVariable(
//            {1, "iTargetQuantity"},
//            "iTargetQuantity",
//            opcua::VariableAttributes{}
//                    .setDisplayName({"en-US", "iTargetQuantity"})
//                    .setDescription({"en-US", "iTargetQuantity"})
//                    .setDataType<int>()
//    );
//
//    iTargetQuantityNode.writeValueScalar(0);
//    iTargetQuantityNode.writeAccessLevel(
//            opcua::AccessLevel::CurrentRead | opcua::AccessLevel::CurrentWrite
//    );
//
//    opcua::Node sWorkOrderIdNode = oeeEnAnalyseDataNode.addVariable(
//            {1, "sWorkOrderId"},
//            "sWorkOrderId",
//            opcua::VariableAttributes{}
//                    .setDisplayName({"en-US", "Work Order ID"})
//                    .setDescription({"en-US", "The identifier for the work order"})
//                    .setDataType<opcua::String>() // This might need to be changed based on the type converter
//    );


    void Application::startOpcuaServer() {
        auto server = new Opcua::Server("localhost", 4840);

        Opcua::Node* dataBlocksGeneralNode = new Opcua::Node("DataBlocksGeneral", "DataBlocksGeneral", "DataBlocksGeneral", Opcua::NodeType::OBJECT);
        Opcua::Node* oeeEnAnalyseDataNode = new Opcua::Node("OEEenAnalyseData", "OEEenAnalyseData", "OEEenAnalyseData", Opcua::NodeType::OBJECT);
        Opcua::Node* generalBatchactiveNode = new Opcua::Node("General.bBatchActive", "General.bBatchActive", "General.bBatchActive", false, {}, Opcua::NodeType::VARIABLE);
        Opcua::Node* u4BatchactiveNode = new Opcua::Node("U4.bBatchactive", "U4.bBatchactive", "U4.bBatchactive", false, {}, Opcua::NodeType::VARIABLE);
        Opcua::Node* u4DelayedAutoNode = new Opcua::Node("U4.bDelayedAuto", "U4.bDelayedAuto", "U4.bDelayedAuto", false, {}, Opcua::NodeType::VARIABLE);
        Opcua::Node* u4bInCycleStopNode = new Opcua::Node("U4.bInCycleStop", "U4.bInCycleStop", "U4.bInCycleStop", false, {}, Opcua::NodeType::VARIABLE);
        Opcua::Node* u4bInStopNode = new Opcua::Node("U4.bInStop", "U4.bInStop", "U4.bInStop", false, {}, Opcua::NodeType::VARIABLE);
        Opcua::Node* u4ResetNecessaryNode = new Opcua::Node("U4.bResetNecessary", "U4.bResetNecessary", "U4.bResetNecessary", false, {}, Opcua::NodeType::VARIABLE);
        Opcua::Node* iTargetQuantityNode = new Opcua::Node("iTargetQuantity", "iTargetQuantity", "iTargetQuantity", 0, {}, Opcua::NodeType::VARIABLE);
        Opcua::Node* sWorkOrderIdNode = new Opcua::Node("sWorkOrderId", "sWorkOrderId", "sWorkOrderId", "empty", {}, Opcua::NodeType::VARIABLE);

        server->addNode(dataBlocksGeneralNode);
        dataBlocksGeneralNode->addNode(oeeEnAnalyseDataNode);
        oeeEnAnalyseDataNode->addNode(generalBatchactiveNode);
        oeeEnAnalyseDataNode->addNode(u4BatchactiveNode);
        oeeEnAnalyseDataNode->addNode(u4DelayedAutoNode);
        oeeEnAnalyseDataNode->addNode(u4bInCycleStopNode);
        oeeEnAnalyseDataNode->addNode(u4bInStopNode);
        oeeEnAnalyseDataNode->addNode(u4ResetNecessaryNode);
        oeeEnAnalyseDataNode->addNode(iTargetQuantityNode);
        oeeEnAnalyseDataNode->addNode(sWorkOrderIdNode);

        server->startServer();


        delete server;
    }


} // CamelSnake
// Utils
// HBUI