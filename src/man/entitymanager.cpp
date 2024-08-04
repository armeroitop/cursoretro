#include "entitymanager.hpp"
#include <algorithm>

namespace ECS {
    EntityManager_t::EntityManager_t() {
        m_Entity.reserve(kNUMINITIALENTITIES);
    }

    void EntityManager_t::createEntity(uint32_t _w, uint32_t _h, uint32_t color) {

        auto& e = m_Entity.emplace_back(_w, _h);
        std::fill(begin(e.sprite), end(e.sprite), color);
    }


} // namespace EC


