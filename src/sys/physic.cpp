#include <sys/physic.hpp>
#include <util/gamecontext.hpp>

namespace ECS {
    bool PhysicSystem_t::update(GameContext_t& g)  {
        for (auto& e : g.getEntities()) {
            e.x += e.vx;
            e.y += e.vy;
        }

        return true;
    }
} // namespace ECS