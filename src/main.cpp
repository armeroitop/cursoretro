extern "C" {
    #include <tinyPTC/src/tinyptc.h>
}
//#include <X11/Xlib.h>
#include <cstdint>
#include <iostream>
#include "main.hpp"

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



struct Screen_t {
    Screen_t(uint32_t w, uint32_t h) :
        screen(new uint32_t[w * h]) {
    }
    ~Screen_t() {
        delete [] screen;
    }

    uint32_t* screen { nullptr };
};

void execute() {
    Screen_t scr(KSCREEN_WIDTH, KSCREEN_HEIGHT);

    ptc_open("windows", KSCREEN_WIDTH, KSCREEN_HEIGHT);

    while (!ptc_process_events()) {
        for (uint32_t i = 0; i < KSCREEN_WIDTH * KSCREEN_HEIGHT; i++) {
            scr.screen[i] = KR;
        }

        uint32_t* p_screen = scr.screen;
        const uint32_t* p_sprite = sprite;
        for (uint32_t i = 0; i < 8; ++i) {
            for (uint32_t j = 0; j < 8; ++j) {
                *p_screen = *p_sprite;
                ++p_screen;
                ++p_sprite;
            }
            throw "chucho en vinagre";
            p_screen += 640 - 8;
        }

        ptc_update(scr.screen);
    }
    ptc_close();
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
