cmake_minimum_required(VERSION 3.10)

project(drone_map VERSION 1.0 LANGUAGES CXX)

# Set C++ standard to C++11 (needed for random)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add executable with all source files
add_executable(drone_map
        main.cpp
        map.cpp
        map.h
)

# Compiler warnings
if(MSVC)
    target_compile_options(drone_map PRIVATE /W4)
else()
    target_compile_options(drone_map PRIVATE -Wall -Wextra)
endif()

# Include directories
target_include_directories(drone_map PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})