cmake_minimum_required(VERSION 3.10)

project(sdl_gui VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(sdl_gui_configuration.h.in sdl_gui_configuration.h)

# MathFunctions library
add_subdirectory(${PROJECT_SOURCE_DIR}/include/Mathfunctions)

add_executable(sdl_first_window sdl_first_window.cpp)
add_executable(${PROJECT_NAME} src/sdl_gui.cpp)

message("Project Binary dir: ${PROJECT_BINARY_DIR}")
message("Project Source dir: ${PROJECT_SOURCE_DIR}")

# 3rd party dependencies
include(FetchContent)
# 1. Try system SDL2 package first
find_package(SDL2 QUIET)
if(SDL2_FOUND)
    message(STATUS "Using SDL2 via find_package")
    message(STATUS "sdl2 files can be found in: ${SDL2_INCLUDE_DIRS}")

    target_include_directories(sdl_first_window PRIVATE 
        ${SDL2_INCLUDE_DIR}
    )

    target_include_directories(${PROJECT_NAME} PRIVATE
        ${SDL2_INCLUDE_DIR}
    )
endif()

# 2. Try using a vendored SDL library
if(NOT SDL2_FOUND AND EXISTS "${CMAKE_CURRENT_LIST_DIR}/SDL/CMakeLists.txt")
    add_subdirectory(SDL)
    message(STATUS "Using SDL2 via add_subdirectory")
    set(SDL2_FOUND TRUE)
endif()

# 3. Download SDL, and use that.
if(NOT SDL2_FOUND)
    include(FetchContent)
    set(SDL_SHARED TRUE CACHE BOOL "Build a SDL shared library (if available)")
    message(STATUS "Using SDL via FetchContent")
    set(SDL_STATIC TRUE CACHE BOOL "Build a SDL static library (if available)")
    FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG SDL2  # Replace this with a particular git tag or git hash
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
        )
        FetchContent_MakeAvailable(SDL2)
        set_property(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/_deps/sdl2-src" PROPERTY EXCLUDE_FROM_ALL TRUE)

        target_include_directories(sdl_first_window PRIVATE ${SDL2_SOURCE_DIR}/include)
        target_include_directories(${PROJECT_NAME} PRIVATE
            ${SDL2_SOURCE_DIR}/include
        )
        message("SDL2 source files can be found in: ${SDL2_SOURCE_DIR}")
endif()


# SDL utils library
add_subdirectory(${PROJECT_SOURCE_DIR}/include/MySDLUtils)

# Main file
target_link_libraries(${PROJECT_NAME} PUBLIC Mathfunctions)
target_link_libraries(${PROJECT_NAME} PUBLIC SDLUtils)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)

# Tutorial file
target_link_libraries(sdl_first_window PRIVATE SDL2::SDL2)
target_include_directories(sdl_first_window PUBLIC ${PROJECT_BINARY_DIR})

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/include/Mathfunctions
    ${PROJECT_SOURCE_DIR}/include/MySDLUtils
)

add_custom_command(TARGET ${PROJECT_NAME} 
    POST_BUILD
    COMMAND cp -r ${PROJECT_SOURCE_DIR}/src/assets/* ${CMAKE_BINARY_DIR}
)
