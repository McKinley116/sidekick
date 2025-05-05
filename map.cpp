//
// Created by Brandon McKinley on 5/4/25.
//

#include "map.h"
#include <random>
#include <iostream>

//generate map function randomly generates the map size and object placement
void generate_map() {

    std::random_device rd; // obtains seed for random engine
    std::mt19937 gen(rd()); // random engine
    std::uniform_int_distribution<> dis(10, 40); // distribution of random numbers, (min, max)
    map_width = dis(gen); // sets width
    map_height = dis(gen); // sets height

    if (map_width < 10 || map_height < 10) {
        std::cout << "Map size must be at least 10x10.\n";
        return;
    }

    grid.clear();
    grid.resize(map_height);
    for (auto& row : grid) {
        row.resize(map_width, EMPTY);
    }

}

//random generates objects for map and places them
void map::generate_objects()
{

}


// gets number on drones on map

// gets number of objects on the map