add_library(MiniVulkanRHI STATIC src/VulkanDevice.cpp)
target_include_directories(MiniVulkanRHI PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(MiniVulkanRHI
    PUBLIC MiniRHI
    PRIVATE MiniCore
)
