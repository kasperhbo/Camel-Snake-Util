//
// Created by Kasper de bruin on 19/03/2024.
//

#include "Application.h"
#include <HBUI/HBUI.h>
#include <iostream>


namespace HB::Utils {
    Application::Application() : serverManagerWindow() {
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

        serverManagerWindow.begin();
        serverManagerWindow.end();

//        HBUI::showLogWindow(&logWindowOpen);

        HBUI::endFrame();
    }
    void Application::startOpcuaServer() {

    }


} // CamelSnake
// Utils
// HBUI