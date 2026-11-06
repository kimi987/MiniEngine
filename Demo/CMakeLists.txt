add_executable(MiniDemo main.cpp)
target_link_libraries(MiniDemo PRIVATE
    MiniCore
    MiniRenderer
    MiniVulkanRHI
    MiniRes
)

if(BUILD_TESTING)
    add_test(NAME MiniEngine_Smoke COMMAND MiniDemo)
endif()
