#pragma once
#include <cstdint>
#include <iostream>
#include <vector>
#include "util/typealiases.hpp"
#include "util/gamecontext.hpp"

namespace ECS {
   


    struct EntityManager_t : public GameContext_t {

        using VecEntities_t = std::vector<Entity_t>;

        static constexpr std::size_t kNUMINITIALENTITIES { 1000 };
        explicit EntityManager_t();

        void createEntity(uint32_t _x, uint32_t _y, uint32_t _w, uint32_t _h, uint32_t color);
        
        const VecEntities_t& getEntities() const override final {return m_Entity;}

        private:
        VecEntities_t m_Entity {};

    };


} // namespace ECS
