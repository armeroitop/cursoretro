extern "C" {
    #include <tinyPTC/src/tinyptc.h>
}
//#include <X11/Xlib.h>
#include <cstdint>
#include <iostream>
#include <memory>
#include "main.hpp"
#include <sys/physic.hpp>
#include <sys/collision.hpp>
#include <man/entitymanager.hpp>

#include <sys/render.hpp>


int main() {

    try {
        //execute();
        ECS::EntityManager_t EntitiyMan;
        ECS::PhysicSystem_t physic;
        ECS::CollisionSystem_t collision;

        EntitiyMan.createEntity(20, 40, "assets/player.png");
        const ECS::RenderSystem_t Render { 640 , 360 };

        while (Render.update(EntitiyMan)) {
            physic.update(EntitiyMan);
            collision.update(EntitiyMan);

        }


    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    } catch (const char* s) {
        std::cout << "Capturado error: " << s << '\n';
    }


    return 0;
}

//cambios a conservar