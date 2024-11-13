#include <sys/physic.hpp>
#include <util/gamecontext.hpp>

namespace ECS {
    bool PhysicSystem_t::update(GameContext_t& g) {
        for (auto& e : g.getEntities()) {
            if (e.phy) {
                e.phy->x += e.phy->vx;
                e.phy->y += e.phy->vy;
            }
        }

        return true;
    }

    
} // namespace ECS