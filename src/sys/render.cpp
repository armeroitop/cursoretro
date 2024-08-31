extern "C" {
    #include <tinyPTC/src/tinyptc.h>
}
#include "render.hpp"
#include <memory>
#include "man/entitymanager.hpp"
#include <algorithm>

namespace ECS {


    RenderSystem_t::RenderSystem_t(uint32_t w, uint32_t h, EntityManager_t& em) :
        m_w { w }, m_h { h },
        m_framebuffer { std::make_unique<uint32_t []>(m_w * m_h) },
        m_em { em } {
        ptc_open("ventana", m_w, m_h);
    }

    RenderSystem_t::~RenderSystem_t() {
        ptc_close();
    }

    /**
    * metodo upda
    */
    bool RenderSystem_t::update() const {
        auto p_screen = m_framebuffer.get();
        const auto size = m_w * m_h;

        std::fill(p_screen, p_screen + size, KG);
        drawAllEntities();

        ptc_update(p_screen);

        return !ptc_process_events();
    }

    void RenderSystem_t::drawAllEntities() const {
        auto& entities { m_em.getEntities() };

        for (auto& e : entities) {
            auto p_screen = m_framebuffer.get();
            p_screen += e.y * m_w + e.x;

            auto sprite_it = begin(e.sprite);
            for (uint32_t y = 0; y < e.h; y++) {
                std::copy(sprite_it, sprite_it + e.w, p_screen);
                sprite_it += e.w;
                p_screen += m_w;
            }
        }
    }

}//fin namespace ECS

