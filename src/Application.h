//
// Created by Kasper de bruin on 19/03/2024.
//

#ifndef CAMELSNAKEUTIL_APPLICATION_H
#define CAMELSNAKEUTIL_APPLICATION_H

#include <HBUI/HBUI.h>


namespace HB::Utils {

    class Application {
    public:
        Application();
        ~Application() = default;
    private:
        void run();
        void render();

        void startOpcuaServer();
    };

} // CamelSnake
// Utils
// HBUI

#endif //CAMELSNAKEUTIL_APPLICATION_H
