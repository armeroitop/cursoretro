extern "C" {
    #include <tinyPTC/src/tinyptc.h>
}
#include "render.hpp"
#include <memory>

namespace ECS {


    RenderSystem_t::RenderSystem_t(uint32_t w, uint32_t h) :
        m_w { w }, m_h { h } {
        ptc_open("ventana", m_w, m_h);
    }

    RenderSystem_t::~RenderSystem_t() {
        ptc_close();
    }

}//fin namespace

