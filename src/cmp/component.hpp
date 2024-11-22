#pragma once
#include <cstdint>

#include "util/typealiases.hpp"

namespace ECS {
struct Component_t {
  explicit Component_t(EntityID_t eid)
      : entityID{eid} {

        };

  std::size_t componentID{++nextID};
  EntityID_t entityID{0};

 private:
  inline static std::size_t nextID{0};
};

}  // namespace ECS
