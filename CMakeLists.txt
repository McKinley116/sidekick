# Sets minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Defines project name, version, and languages used
project(sidekick VERSION 1.0 LANGUAGES CXX)

# Sets C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Specifies the executable name and source files
add_executable(drone_map
        main.cpp
        map.cpp
        map.h
)

# Adds compiler warnings based on compiler type
if(MSVC)
    target_compile_options(drone_map PRIVATE /W4)
else()
    target_compile_options(drone_map PRIVATE -Wall -Wextra)
endif()

# Sets include directories
target_include_directories(drone_map PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})