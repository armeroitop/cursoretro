#pragma once
#include <cstdint>
#include <iostream>
#include <vector>

#include "man/componentstorage.hpp"
#include "util/gamecontext.hpp"
#include "../util/typealiases.hpp"
#include "cmp/entity.hpp"

namespace ECS {

struct EntityManager_t : public GameContext_t {
  //using Vec_t<Entity_t> = std::vector<Entity_t>;

  static constexpr std::size_t kNUMINITIALENTITIES{1000};
  explicit EntityManager_t();

  void createEntity(uint32_t _x, uint32_t _y, std::string filename);

  const Vec_t<Entity_t>& getEntities() const override final { return m_Entity; }
  Vec_t<Entity_t>& getEntities() override final { return m_Entity; }

  const std::vector<PhysicsComponent_t>& getPhysicsComponents()
      const override final {
    return m_components.getPhysicsComponents();
  }
  std::vector<PhysicsComponent_t>& getPhysicsComponents() override final {
    return m_components.getPhysicsComponents();
  }

 private:
  Vec_t<Entity_t> m_Entity{};
  ComponentStorage_t m_components{kNUMINITIALENTITIES};
};

}  // namespace ECS
