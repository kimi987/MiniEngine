#pragma once
#include <string_view>

namespace Mini::RHI {
class Device {
public:
    Device() = default;
    virtual ~Device() = default;

    Device(const Device&) = delete;
    Device& operator=(const Device&) = delete;

    virtual std::string_view BackendName() const noexcept = 0;
    virtual void BeginFrame() = 0;
};
}
