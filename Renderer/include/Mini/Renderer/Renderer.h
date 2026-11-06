#pragma once

namespace Mini::RHI {
class Device;
}
namespace Mini::Core {
    class FrameTimer;
}

namespace Mini::Renderer {
class Renderer final {
public:
    explicit Renderer(RHI::Device& device) noexcept;
    ~Renderer();
    void DrawFrame();

private:
    RHI::Device& device_; // non-owning; Application must keep Device alive
    Mini::Core::FrameTimer* frame_timer_; // non-owning; Application must keep FrameTimer alive
};
}
