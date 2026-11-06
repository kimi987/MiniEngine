add_library(MiniRenderer STATIC src/Renderer.cpp)
target_include_directories(MiniRenderer PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(MiniRenderer
    PUBLIC MiniRHI
    PRIVATE MiniCore
)
