add_library(MiniRes STATIC src/ResourcePool.cpp src/TextureManager.cpp)
target_include_directories(MiniRes PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
