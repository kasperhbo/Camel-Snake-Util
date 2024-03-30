//
// Created by Kasper de bruin on 30/03/2024.
//

#include "NodeWindow.h"
#include <HBUI/HBUI.h>

namespace HBUI::Utils::Opcua {
    void NodeWindow::begin(HB::Utils::Opcua::Server *server) {
        if (server == nullptr) {
            return;
        }

        p_Server = server;

        ImGui::BeginChildFrame(1, ImVec2(200, 200));
    }

    void NodeWindow::end() {

    }


    void NodeWindow::addToServer() {

    }


} // Opcua
// Utils
// HBUI