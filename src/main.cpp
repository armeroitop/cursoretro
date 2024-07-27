extern "C" {
#include <tinyPTC/src/tinyptc.h>
}
#define COLOR_ROJO 0x00FF0000;
#define COLOR_AZUL 0x000000FF;
#include <cstdint>

constexpr uint32_t KR = 0x00FF0000;
constexpr uint32_t KG = 0x0000FF00;
constexpr uint32_t KB = 0x000000FF;

constexpr uint32_t sprite[8 * 8] = {
    KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG,
    KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG,
    KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG,
    KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG, KG};

int main() {
  uint32_t screen[640 * 360];

  ptc_open("windows", 640, 360);

  while (!ptc_process_events()) {
    for (uint32_t i = 0; i < 360 * 640; i++) {
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

  return 0;
}