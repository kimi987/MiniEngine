

#include <cstdint>
#include <vector>
#include <memory>

#pragma once

namespace Mini {
    struct ResourceHandle
    {
        uint32_t index;
        uint32_t generation;
    };

    struct TextureHandle
    {
        ResourceHandle raw;
    };

    template<typename T>
    class ResourcePool
    {
        private:
            struct Slot
            {
                std::unique_ptr<T> resource;
                uint32_t generation = 1;
            };

            std::vector<Slot> slots_;
            std::vector<uint32_t> freeIndices_;

        public:
            ResourcePool() = default;

            ResourcePool(const ResourcePool&) = delete;
            ResourcePool& operator=(const ResourcePool&) = delete;

            template<typename... Args>
            ResourceHandle Create(Args&&... args);

            T* Get(ResourceHandle handle);

            const T* Get(ResourceHandle handle) const;

            bool Destroy(ResourceHandle handle);

            size_t AliveCount() const;
    };

    template<typename T>          // 类的模板参数
template<typename... Args>    // 函数的模板参数
ResourceHandle ResourcePool<T>::Create(Args&&... args)
{
    // 具体实现
    auto obj = std::make_unique<T>(std::forward<Args>(args)...);

    uint32_t index;
    if (!freeIndices_.empty()) {
        index = freeIndices_.back();
        freeIndices_.pop_back();
    } else {
        index = static_cast<uint32_t>(slots_.size());
        slots_.emplace_back();
    }

    Slot& slot = slots_[index];
    slot.resource = std::move(obj);
    return ResourceHandle{ index, slot.generation };
}

template<typename T>          // 类的模板参数
T* ResourcePool<T>::Get(ResourceHandle handle)
{
    if (handle.index >= slots_.size()) {
        return nullptr;
    }

    Slot& slot = slots_[handle.index];
    if (slot.generation != handle.generation) {
        return nullptr;
    }

    return slot.resource.get();
}
template<typename T>    
const T* ResourcePool<T>::Get(ResourceHandle handle) const
{
    if (handle.index >= slots_.size()) {
        return nullptr;
    }

    const Slot& slot = slots_[handle.index];
    if (!slot.resource || slot.generation != handle.generation) {
        return nullptr;
    }

    return slot.resource.get();
}

template<typename T>          // 类的模板参数
bool ResourcePool<T>::Destroy(ResourceHandle handle)
{
    if (handle.index >= slots_.size()) {
        return false;
    }

    Slot& slot = slots_[handle.index];
    if (!slot.resource || slot.generation != handle.generation) {
        return false;
    }
    freeIndices_.reserve(freeIndices_.size() + 1);
    slot.resource.reset();
    slot.generation++;
    freeIndices_.push_back(handle.index);
    return true;
}

template<typename T>          // 类的模板参数
size_t ResourcePool<T>::AliveCount() const
{
    size_t count = 0;
    for (const auto& slot : slots_) {
        if (slot.resource) {
            count++;
        }
    }
    return count;
}

}