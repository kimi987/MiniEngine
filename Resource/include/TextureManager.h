
#include "ResourcePool.h"
#include "TextureResource.h"
#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>

namespace Mini 
{
    class TextureManager
    {
        public:
            std::optional<TextureHandle> Create(std::uint32_t width, std::uint32_t height);

            TextureResource* Get(TextureHandle handle);

            const TextureResource* Get(TextureHandle handle) const;

            bool Destroy(TextureHandle handle);

            std::size_t AliveCount() const;

        private:
            ResourcePool<TextureResource> texture_pool_;
    };
}