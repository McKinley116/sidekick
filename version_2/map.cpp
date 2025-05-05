//
// Created by Brandon McKinley on 5/4/25.
//Version 2

#include "map.h"
#include <vector>
#include <random>
#include <iostream>
#include <iomanip>

//generate map function randomly generates the map size and object placement
void map::generate_map() {

    std::cout << "Generating map..." << std::endl;
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
    std::cout << "Map grid initialized" << std::endl;  // Debug print

}

//random generates objects for map and places them
void map::generate_objects()
{
    std::cout << "Generating objects..." << std::endl;  // Debug print

    std::random_device rd; // obtains seed for random engine
    std::mt19937 gen(rd()); // random engine

    int total_cells = map_width * map_height; // helps divide up the map so that the entire map is not only objects
    object_count = total_cells / 10; // sets number of objects to be 10% of total cells

    std::uniform_int_distribution<> width_distribution(0, map_width - 1); // distribution of random numbers, (min, max)  for width
    std::uniform_int_distribution<> height_distribution(0, map_height -1 ); // distribution of random numbers, (min, max) for height

    int placed_objects = 0; // keeps track of how many objects have been placed
    int max_attempts = total_cells * 2; // sets max attempts to avoid inf loops
    int attempts = 0; // keeps track of attempts

    while (placed_objects < object_count && attempts < max_attempts) {
        int x = width_distribution(gen); // gets random x coordinate
        int y = height_distribution(gen); // gets random y coordinate

        // checks if a cell is empty, pulls from enumerator
        if (grid[y][x] == EMPTY) {
            grid[y][x] = OBJECT;
            placed_objects++;
        }
        attempts++;
    }

    object_count = placed_objects; // sets number of objects to be the number of objects placed
}

//display map with objects, D = drone, OB = objects, X = empty
void map::display_map()
{

    // Print top border
    std::cout << "Map Size: " << map_width << "x" << map_height << "\n";
    std::cout << "Drones: " << drone_count << " Objects: " << object_count << "\n\n";

    // Print column numbers
    std::cout << "   ";  // Space for row numbers
    for (int x = 1; x < map_width; x++) {
        std::cout << std::setw(2) << x << " ";
    }
    std::cout << "\n";


    // Print top border
    std::cout << "   ";
    for (int x = 1; x < map_width; x++) {
        std::cout << "---";
    }
    std::cout << "\n";

    // Print grid with row numbers
    for (int y = 1; y < map_height; y++) {
        std::cout << std::setw(2) << y << "|";
        for (int x = 0; x < map_width; x++) {
            char symbol;
            switch (grid[y][x]) {
            case EMPTY:
                symbol = '.';
                break;
            case DRONE:
                symbol = 'D';
                break;
            case OBJECT:
                symbol = 'O';
                break;
            default:
                symbol = '?';
            }
            std::cout << " " << symbol << " ";
        }
        std::cout << "|\n";
    }

    // Print bottom border
    std::cout << "   ";
    for (int x = 0; x < map_width; x++) {
        std::cout << "---";
    }
    std::cout << "\n";

}

// gets number on drones on map
int map::get_drone_count() const
{
    return drone_count;
}

// gets number of objects on the map
int map::get_object_count() const
{
    return object_count;
}