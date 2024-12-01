#include "componentstorage.hpp"

namespace ECS {

    PhysicsComponent_t& ComponentStorage_t::createPhysicsComponent(EntityID_t eid) {
        return m_physicsComponent.emplace_back(eid);

    }
} // namespace ECS
