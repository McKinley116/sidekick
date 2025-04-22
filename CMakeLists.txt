cmake_minimum_required(VERSION 3.30)
project(sidekick)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(sidekick
    drone.cpp
    drone.h
    main.cpp
    map.cpp
    map.h)
