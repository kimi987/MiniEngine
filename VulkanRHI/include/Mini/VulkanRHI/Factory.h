#pragma once
#include <memory>
#include <Mini/RHI/Device.h>

namespace Mini::VulkanRHI {
std::unique_ptr<RHI::Device> CreateVulkanDevice();
}
