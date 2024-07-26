extern "C" {
#include <tinyPTC/src/tinyptc.h>
}
#define COLOR_ROJO 0x00FF0000;
#define COLOR_AZUL 0x000000FF;
#include <cstdint>

int main() {
  uint32_t screen[640 * 360];
  uint32_t sprite[60 * 40];

  ptc_open("windows", 640, 360);

  for (;;) {
    for (uint32_t i = 0; i < 360 * 640; i++) {
      screen[i] = COLOR_ROJO;
    }

    for (uint32_t i = 0; i < (0 + 60); ++i) {
      for (uint32_t j = 0; j < (0 + 40); ++j) {
        sprite[(i * 40) + j] = COLOR_AZUL;
      }
    }

    uint32_t* p_screen = screen;
    uint32_t* p_sprite = sprite;
    for (uint32_t i = 0; i < (0 + 60); ++i) {
      for (uint32_t j = 0; j < (0 + 40); ++j) {
        *p_screen = *p_sprite;
        ++p_screen;
        ++p_sprite;
      }
      p_screen += 640 - 40;
    }

    ptc_update(screen);
  }

  ptc_close();

  return 0;
}