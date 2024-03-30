//
// Created by Kasper de bruin on 30/03/2024.
//

#ifndef CAMELSNAKEUTIL_SERVERMANAGERWINDOW_H
#define CAMELSNAKEUTIL_SERVERMANAGERWINDOW_H

#include <HBUI/HBUI.h>
#include "Server.h"

namespace HBUI::Utils::Opcua {

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
                                                std::variant<int, bool, std::string> defaultValue);

        HB::Utils::Opcua::Node *addObjectNode(std::string name, std::string displayName, std::string description);

        HB::Utils::Opcua::Node *addVariableNode(std::string name, std::string displayName, std::string description,
                                                std::variant<int, bool, std::string> defaultValue,
                                                HB::Utils::Opcua::Node *parentNode);

    private:
        const std::string label = "Server Manager";
        HB::Utils::Opcua::Server *p_Server = nullptr;
        //inputs
    private:
        std::string hostname = "localhost";
        int port = 4840;


    };

} // Opcua
// Utils
// HBUI

#endif //CAMELSNAKEUTIL_SERVERMANAGERWINDOW_H
