extern "C" {
    #include <tinyPTC/src/tinyptc.h>
}
//#include <X11/Xlib.h>
#include <cstdint>
#include <iostream>
#include <memory>
#include "main.hpp"
#include "sys/render.hpp"

constexpr uint32_t KR { 0x00FF0000 };
constexpr uint32_t KG { 0x0000FF00 };
constexpr uint32_t KB { 0x000000FF };

constexpr uint32_t sprite[8 * 8] = {
    KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG,
    KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG,
    KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG,
    KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG };

constexpr uint32_t KSCREEN_WIDTH { 640 };
constexpr uint32_t KSCREEN_HEIGHT { 360 };


void execute() {

    auto screen = std::make_unique<uint32_t []>(KSCREEN_WIDTH * KSCREEN_HEIGHT);

    //ptc_open("windows", KSCREEN_WIDTH, KSCREEN_HEIGHT);
    ECS::RenderSystem_t Render{KSCREEN_WIDTH , KSCREEN_HEIGHT};

    while (true)
    {
        /* code */
    }
    

    /* while (!ptc_process_events()) {
        for (uint32_t i = 0; i < KSCREEN_WIDTH * KSCREEN_HEIGHT; i++) {
            screen[i] = KR;
        }

        uint32_t* p_screen = screen.get();
        const uint32_t* p_sprite = sprite;
        for (uint32_t i = 0; i < 8; ++i) {
            for (uint32_t j = 0; j < 8; ++j) {
                *p_screen = *p_sprite;
                ++p_screen;
                ++p_sprite;
            }
            //throw "chuchos en vinagre";
            p_screen += 640 - 8;
        }

        ptc_update(screen.get()); 
    }*/
    //ptc_close();
}

int main() {

    try {
        execute();
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    } catch (const char* s) {
        std::cout << "Capturado error: " << s << '\n';
    }


    return 0;
}

//cambios a conservar