add_library(MiniCore STATIC 
        src/Log.cpp
        src/FrameTimer.cpp
)

target_include_directories(MiniCore PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
