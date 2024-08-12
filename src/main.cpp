extern "C" {
    #include <tinyPTC/src/tinyptc.h>
}
//#include <X11/Xlib.h>
#include <cstdint>
#include <iostream>
#include <memory>
#include "main.hpp"
#include "sys/render.hpp"
#include "man/entitymanager.hpp"


int main() {

    try {
        //execute();
        ECS::EntityManager_t EntitiyMan;
        EntitiyMan.createEntity(16,16, 0x0000FF00);
        const ECS::RenderSystem_t Render { 640 , 360 , EntitiyMan};

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