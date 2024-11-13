#pragma once
#include <cstdint>

namespace ECS {

struct PhysicsComponent_t {
  explicit PhysicsComponent_t() = default;
  uint32_t x{0}, y{0};
  uint32_t vx{1}, vy{0};
};

}  // namespace ECS
