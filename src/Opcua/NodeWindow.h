//
// Created by Kasper de bruin on 30/03/2024.
//

#ifndef CAMELSNAKEUTIL_NODEWINDOW_H
#define CAMELSNAKEUTIL_NODEWINDOW_H

#include "Server.h"


namespace HBUI::Utils::Opcua {

    class NodeWindow {
    public:
        void begin(HB::Utils::Opcua::Server* server);
        void end();

        void addToServer();
    private:
        HB::Utils::Opcua::Server *p_Server = nullptr;
    };

} // Opcua
// Utils
// HBUI

#endif //CAMELSNAKEUTIL_NODEWINDOW_H
