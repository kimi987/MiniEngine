#include <Mini/Renderer/Renderer.h>
#include <Mini/RHI/Device.h>
#include <Mini/Core/Log.h>
#include <Mini/Core/FrameTimer.h>

namespace Mini::Renderer {
Renderer::Renderer(RHI::Device& device) noexcept : device_(device) {
    frame_timer_ = new Mini::Core::FrameTimer();
}

Renderer::~Renderer() {
    Core::Log("Renderer destroyed");
    delete frame_timer_;
}

void Renderer::DrawFrame() {
    Core::Log(device_.BackendName());
    device_.BeginFrame();
}
}
