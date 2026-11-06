

#include <cstdint>
#pragma once

namespace Mini
{
    struct TextureResource
    {
        std::uint32_t width;
        std::uint32_t height;

        TextureResource(std::uint32_t w, std::uint32_t h) : width(w), height(h) {}
    };


}