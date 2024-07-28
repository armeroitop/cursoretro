extern "C" {
    #include <tinyPTC/src/tinyptc.h>
}

#include <cstdint>

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

uint32_t* screen { nullptr };

int main() {
    screen = new uint32_t[KSCREEN_WIDTH * KSCREEN_HEIGHT];

    ptc_open("windows", KSCREEN_WIDTH, KSCREEN_HEIGHT);

    while (!ptc_process_events()) {
        for (uint32_t i = 0; i < KSCREEN_WIDTH * KSCREEN_HEIGHT; i++) {
            screen[i] = KR;
        }

        uint32_t* p_screen = screen;
        const uint32_t* p_sprite = sprite;
        for (uint32_t i = 0; i < 8; ++i) {
            for (uint32_t j = 0; j < 8; ++j) {
                *p_screen = *p_sprite;
                ++p_screen;
                ++p_sprite;
            }
            p_screen += 640 - 8;
        }

        ptc_update(screen);
    }

    ptc_close();

    delete [] screen;

    return 0;
}