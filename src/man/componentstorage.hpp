#pragma once
#include <vector>

#include "cmp/physics.hpp"
#include "util/typealiases.hpp"

namespace ECS {
struct ComponentStorage_t {
  // quitamos el constructor por defecto
  ComponentStorage_t() = delete;

  // creamos un nuevo constructor con tipos explicitos
  explicit ComponentStorage_t(std::size_t initialsize) {
    m_physicsComponent.reserve(initialsize);
  };

  // Le quitamos la posiblidad de crear copias y la creación por asignacion a
  // variables
  ComponentStorage_t(const ComponentStorage_t&) = delete;
  ComponentStorage_t(ComponentStorage_t&&) = delete;
  ComponentStorage_t operator=(const ComponentStorage_t&) = delete;
  ComponentStorage_t operator=(ComponentStorage_t&&) = delete;

  PhysicsComponent_t& createPhysicsComponent(EntityID_t eid);

  const std::vector<PhysicsComponent_t>& getPhysicsComponents() const {
    return m_physicsComponent;
  }
  std::vector<PhysicsComponent_t>& getPhysicsComponents() {
    return m_physicsComponent;
  }

 private:
  std::vector<PhysicsComponent_t> m_physicsComponent{};
};

}  // namespace ECS
