#pragma once

#include <algorithm>

namespace ECS {


    struct GameContext_t {
        virtual ~GameContext_t() = default;

        virtual const VecEntities_t& getEntities() const = 0;
        virtual VecEntities_t& getEntities() = 0;

    };

}//namespace ECS