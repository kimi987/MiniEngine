#include <Mini/Core/Log.h>
#include <Mini/VulkanRHI/Factory.h>
#include <Mini/Renderer/Renderer.h>
#include <ResourcePool.h>
#include <Texture.h>
#include <TextureManager.h>
#include <DeferredDeletionQueue.h>
#include <cassert>
#include <iostream>

// int main() {
//     auto device = Mini::VulkanRHI::CreateVulkanDevice();
//     {
//         Mini::Renderer::Renderer renderer(*device);
//         renderer.DrawFrame();
//     } // Renderer is destroyed before device

//     Mini::Core::Log("Renderer destroyed; device is still alive");
//     device.reset();
//     return 0;
// }

// int main() {
//     Mini::TextureHandleManager handle_manager;
//     auto a = handle_manager.Create();

//     assert(a.value == 0);
//     assert(a.generation == 1);
//     assert(handle_manager.IsAlive(a));

//     auto aCopy = a;

//     assert(handle_manager.IsAlive(aCopy));

//     assert(handle_manager.Destroy(a));

//     assert(!handle_manager.IsAlive(a));
//     assert(!handle_manager.IsAlive(aCopy));

//     assert(!handle_manager.Destroy(a));

//     auto b = handle_manager.Create();

//     assert(b.value == a.value);
//     assert(b.generation != a.generation);

//     assert(handle_manager.IsAlive(b));
//     assert(!handle_manager.IsAlive(a));

//     assert(!handle_manager.Destroy(a));
//     assert(handle_manager.IsAlive(b));

//     Mini::TextureHandle invalidHandle;

//     assert(invalidHandle.IsNull());
//     assert(!handle_manager.IsAlive(invalidHandle));
//     assert(!handle_manager.Destroy(invalidHandle));

//     Mini::TextureHandle invalidHandle2{ b.value, b.generation + 1 };

//     assert(!handle_manager.IsAlive(invalidHandle2));

//     assert(handle_manager.Destroy(b));

//     auto c = handle_manager.Create();

//     assert(c.value == 0);
//     assert(c.generation == 3);
//     assert(handle_manager.IsAlive(c));
    
//     std::cout << "Handle A: value = " << a.value << ", generation = " << a.generation << std::endl;
//     std::cout << "Handle B: value = " << b.value << ", generation = " << b.generation << std::endl;
//     std::cout << "Handle C: value = " << c.value << ", generation = " << c.generation << std::endl;

//     std::cout << "All tests passed!" << std::endl;
//     return 0;
// }

// int main() {
//     Mini::ResourcePool<Mini::Texture> texturePool;

//     auto a = texturePool.Create("TextureA");
//     auto b = texturePool.Create("TextureB");

//     assert(texturePool.Get(a) != nullptr);
//     assert(texturePool.Get(b) != nullptr);

//     bool destroyedA = texturePool.Destroy(a);
//     assert(destroyedA);
//     assert(texturePool.Get(a) == nullptr);

//     auto c = texturePool.Create("TextureC");
//     assert(c.index == a.index);
//     assert(c.generation != a.generation);

//     assert(texturePool.Get(a) == nullptr);
//     assert(texturePool.Get(c) != nullptr);

//     assert(!texturePool.Destroy(a));

//     std::cout << "All ResourcePool tests passed!" << std::endl;
//     return 0;
// }

// int main() {
//     using namespace Mini;
//     TextureManager textureManager;

//     auto result = textureManager.Create(1024, 1024);

//     assert(result.has_value());

//     TextureHandle handle = *result;

//     auto* texture = textureManager.Get(handle);

//     assert(texture != nullptr);
//     assert(texture->width == 1024);
//     assert(textureManager.AliveCount() == 1);

//     bool destroyed = textureManager.Destroy(handle);

//     assert(destroyed);
//     assert(textureManager.Get(handle) == nullptr);
//     assert(textureManager.AliveCount() == 0);

//     assert(!textureManager.Destroy(handle));

//     std::cout << "All TextureManager tests passed!" << std::endl;

// }


struct MockGpuTexture
{
    int id;

    explicit MockGpuTexture(int value) : id(value)
    {
        std::cout << "Create Texture " << id << '\n';
    }

    ~MockGpuTexture()
    {
        std::cout << "Release Texture " << id << '\n';
    }

    MockGpuTexture(const MockGpuTexture&) = delete;
    MockGpuTexture& operator=(const MockGpuTexture&) = delete;
};

int main()
{
    using namespace Mini;
    FrameDeletionQueue<MockGpuTexture> queue;

    queue.Retire(5, std::make_unique<MockGpuTexture>(101));

    queue.Retire(3, std::make_unique<MockGpuTexture>(102));

    queue.Collect(2);

    queue.Collect(3);

    queue.Collect(5);
}