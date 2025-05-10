# Sets minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Defines project name, version, and languages used
project(sidekick VERSION 1.0 LANGUAGES CXX)

# Sets C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Specifies the executable name and source files
add_executable(sidekick
       main.cpp
        map.cpp
        drone.cpp
        user_menu.cpp
        scout.cpp
        fighter.cpp

)

# Adds compiler warnings based on compiler type
if(MSVC)
    target_compile_options(sidekick PRIVATE /W4)
else()
    target_compile_options(sidekick PRIVATE -Wall -Wextra)
endif()

# Sets include directories
target_include_directories(sidekick PRIVATE ..)