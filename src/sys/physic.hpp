#pragma once

#include <util/typealiases.hpp>

namespace ECS {

    //Forward declarations
    struct GameContext_t;

    struct PhysicSystem_t {
        explicit PhysicSystem_t() = default;

        bool update(GameContext_t& g);

    };
} // namespace ECS


