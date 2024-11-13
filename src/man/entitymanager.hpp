#pragma once
#include <cstdint>
#include <iostream>
#include <vector>
#include "man/componentstorage.hpp"
#include "util/typealiases.hpp"
#include "util/gamecontext.hpp"

namespace ECS {

struct EntityManager_t : public GameContext_t {

    using VecEntities_t = std::vector<Entity_t>;

    static constexpr std::size_t kNUMINITIALENTITIES { 1000 };
    explicit EntityManager_t();

    void createEntity(uint32_t _x, uint32_t _y, std::string filename);

    const VecEntities_t& getEntities() const override final { return m_Entity; }
    VecEntities_t& getEntities() override final { return m_Entity; }

    const std::vector<PhysicsComponent_t>& getPhysicsComponents() const override final { return m_components; }
          std::vector<PhysicsComponent_t>& getPhysicsComponents() override final { return m_components; }

    private:
    VecEntities_t m_Entity {};
    ComponentStorage_t m_components { kNUMINITIALENTITIES };

};


} // namespace ECS
