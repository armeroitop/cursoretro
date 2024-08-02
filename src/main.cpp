extern "C" {
    #include <tinyPTC/src/tinyptc.h>
}
//#include <X11/Xlib.h>
#include <cstdint>
#include <iostream>
#include <memory>
#include "main.hpp"
#include "sys/render.hpp"


int main() {

    try {
        //execute();
        const ECS::RenderSystem_t Render { 640 , 360 };

        while (Render.update()) {

        }


    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    } catch (const char* s) {
        std::cout << "Capturado error: " << s << '\n';
    }


    return 0;
}

//cambios a conservar