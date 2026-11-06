# MiniEngine — Day 28 Starter

本工程是可编译的模块边界练习骨架，不是真实 Vulkan 实现。
`VulkanRHI` 中的 `VulkanDeviceStub` 只验证依赖方向、接口分离、链接和对象生命周期。

## 构建

```bash
cmake -S . -B build
cmake --build build --config Debug
ctest --test-dir build -C Debug --output-on-failure
```

## 核心依赖

- `MiniRenderer` -> `MiniRHI`, `MiniCore`（不依赖 `MiniVulkanRHI`）
- `MiniVulkanRHI` -> `MiniRHI`, `MiniCore`
- `MiniDemo` -> `MiniRenderer`, `MiniVulkanRHI`, `MiniCore`
- `MiniRHI` 目前是纯头文件 interface library

## Day 28 留给你的练习

1. 解释每一条 `PUBLIC/PRIVATE/INTERFACE` 的原因。
2. 删掉 `Demo` 对 `MiniVulkanRHI` 的依赖，构建一次并解释 linker 报错。
3. 尝试只在 `Renderer` 头文件中使用 `RHI::Device*`，验证前向声明是否足够。
4. 尝试让 `Renderer` 直接包含 `<Mini/VulkanRHI/Factory.h>`，说明为何违背模块边界。
5. 在不让 Renderer 依赖 VulkanRHI 的情况下设计一个 Device factory 注入方案。
