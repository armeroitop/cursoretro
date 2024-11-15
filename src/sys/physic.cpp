#include <sys/physic.hpp>
#include <util/gamecontext.hpp>

namespace ECS {
bool PhysicSystem_t::update(GameContext_t& g) {
  for (auto& phy : g.getPhysicsComponents()) {
    {
      phy.x += phy.vx;
      phy.y += phy.vy;
    }
  }

  return true;
}

}  // namespace ECS