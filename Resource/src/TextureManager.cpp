#include "TextureManager.h"


using namespace Mini;

std::optional<TextureHandle> TextureManager::Create(std::uint32_t width, std::uint32_t height)
{
   if(width == 0 || height == 0)
   {
        return std::nullopt; // Return an empty optional if width or height is zero
   }

   ResourceHandle raw = texture_pool_.Create(width, height);
   return TextureHandle{ raw };
}

TextureResource* TextureManager::Get(TextureHandle handle)
{
    return texture_pool_.Get(handle.raw);
}

const TextureResource* TextureManager::Get(TextureHandle handle) const
{
    return texture_pool_.Get(handle.raw);
}

bool TextureManager::Destroy(TextureHandle handle)
{
    return texture_pool_.Destroy(handle.raw);
}

std::size_t TextureManager::AliveCount() const
{
    return texture_pool_.AliveCount();
}