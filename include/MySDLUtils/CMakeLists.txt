add_library(SDLUtils STATIC
    SDLUtils.cpp
    init.cpp 
    loadMedia.cpp
    close.cpp
)

target_link_libraries(SDLUtils PRIVATE SDL2::SDL2)

target_include_directories(SDLUtils PUBLIC ${PROJECT_BINARY_DIR})

message(STATUS "Including SDLUtils")