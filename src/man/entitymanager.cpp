#include "entitymanager.hpp"
#include <algorithm>

namespace ECS {
    EntityManager_t::EntityManager_t() {
        m_Entity.reserve(kNUMINITIALENTITIES);
    }

    void EntityManager_t::createEntity(uint32_t _x, uint32_t _y, uint32_t _w, uint32_t _h, uint32_t color) {

        auto& e = m_Entity.emplace_back("assets/player.png");
        e.x = _x; e.y = _y;
        //std::fill(begin(e.sprite), end(e.sprite), color);

    }


} // namespace EC


