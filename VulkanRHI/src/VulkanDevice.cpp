#include <Mini/VulkanRHI/Factory.h>
#include <Mini/Core/Log.h>
#include <memory>

namespace Mini::VulkanRHI {
namespace {
class VulkanDeviceStub final : public RHI::Device {
public:
    VulkanDeviceStub() { Core::Log("Create VulkanRHI stub device"); }
    ~VulkanDeviceStub() override { Core::Log("Destroy VulkanRHI stub device"); }

    std::string_view BackendName() const noexcept override {
        return "VulkanRHI (stub; no Vulkan calls)";
    }

    void BeginFrame() override { Core::Log("Stub BeginFrame"); }
};
} // namespace

std::unique_ptr<RHI::Device> CreateVulkanDevice() {
    return std::make_unique<VulkanDeviceStub>();
}
} // namespace Mini::VulkanRHI
