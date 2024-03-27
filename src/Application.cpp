//
// Created by Kasper de bruin on 19/03/2024.
//

#include "Application.h"
#include <HBUI/HBUI.h>

namespace HBUI::Utils::CamelSnake {
    Application::Application() {
        HBUI::initialize("Hello, World!", 1280, 720);

        run();
    }

    void Application::run() {
        while (!HBUI::wantToClose()) {
            render();
        }

    }

    void Application::render() {
        HBUI::startFrame();
        HBUI::beginTaskBar("HorizontalTaskBar", {0, 0});
        HBUI::iconButton(HBUI::getIcon("NF_ICON_snake"));
        HBUI::endTaskBar();
        ImGui::ShowDemoWindow(nullptr);

        ImGui::Begin("Fonts");

        ImGui::Text("Hello, world!");
        ImGui::Text("This is some useful text.");
        ImGui::End();

        HBUI::endFrame();
    }


} // CamelSnake
// Utils
// HBUI