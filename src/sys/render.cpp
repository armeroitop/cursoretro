extern "C" {
    #include <tinyPTC/src/tinyptc.h>
}
#include "render.hpp"
#include <memory>

namespace ECS {


    RenderSystem_t::RenderSystem_t(uint32_t w, uint32_t h) :
        m_w { w }, m_h { h },
        m_framebuffer { std::make_unique<uint32_t []>(m_w * m_h) } {
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
        for (uint32_t i = 0; i < m_w * m_h; ++i) {
            p_screen[i] = KR;
        }
        //pintaSprites(p_screen);
        ptc_update(p_screen);

        return !ptc_process_events();

    }

    //void RenderSystem_t::pintaSprites(uint32_t*& p_screen) const {
    //    const uint32_t* p_sprite = sprite;
    //    for (uint32_t i = 0; i < 8; ++i) {
    //        for (uint32_t j = 0; j < 8; ++j) {
    //            *p_screen = *p_sprite;
    //            ++p_screen;
    //            ++p_sprite;
    //        }
    //        //throw "chuchos en vinagre";
    //        p_screen += 640 - 8;
    //    }
    //}

}//fin namespace

