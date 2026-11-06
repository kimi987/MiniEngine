cmake_minimum_required(VERSION 3.20)
project(MiniEngine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_subdirectory(Core)
add_subdirectory(Resource)
add_subdirectory(RHI)
add_subdirectory(VulkanRHI)
add_subdirectory(Renderer)
add_subdirectory(Demo)
