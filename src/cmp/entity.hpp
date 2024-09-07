#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <picoPNG/src/picopng.hpp>
#include <fstream

namespace ECS {

    struct Entity_t {
        explicit Entity_t(uint32_t _w, uint32_t _h) :
            w { _w }, h { _h } {
            sprite.resize(w * h);
        }


        explicit Entity_t() {
            std::vector<unsigned char> pixels;
            unsigned long dx { w }, dh { h };
            std::ifstream file(filename);

            decodePNG(pixels, dx, dh, in_png, size_t);

            

            w = dx; h = dh;

            // int decodePNG(std::vector<unsigned char>& out_image, unsigned long& image_width, 
            //    unsigned long& image_height, const unsigned char* in_png, 
            //    std::size_t in_size, bool convert_to_rgba32 = true);
        }





        uint32_t x { 0 }, y { 0 };
        uint32_t w { 0 }, h { 0 };
        std::vector<uint32_t> sprite {};

    };
} // namespace ECS