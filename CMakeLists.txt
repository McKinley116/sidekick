# Minimum CMake version
cmake_minimum_required(VERSION 3.15)

# Project name and configurations
project(sidekick VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Executable target
add_executable(sidekick
        main.cpp
        drone.cpp
        map.cpp
)

# Include header directory
include_directories(${CMAKE_SOURCE_DIR})