//
// Created by Brandon McKinley on 5/4/25.
//

#include "map.h"
#include <random>
#include <ctime>

//generate map function randomly generates the map size and object placement
void generate_map() {
    std::random_device rd; // obtains seed for random engine
    std::mt19937 gen(rd()); // random engine
    std::uniform_int_distribution<> dis(10, 40); // distribution of random numbers, (min, max)
    int map_width = dis(gen);
    int map_height = dis(gen);
}

// gets number on drones on map

// gets number of objects on the map