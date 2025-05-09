//
// Created by Brandon McKinley on 5/4/25.
//Version 2

#include "map.h"
#include "drone.h"
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

bool map::is_within_bounds(int x, int y) const
{
    return (x >= 0 && x < map_width && y >= 0 && y < map_height);
}


bool map::add_drone(int x, int y)
{
    // needs to check map for where objects are and make sure drone can be place within bounds
    if (!is_within_bounds(x, y)) {
        std::cout << "Error: Position (" << x << ", " << y << ") is outside map bounds.\n";
        return false;
    }

    if (grid[x][y] == OBJECT)
    {
        std::cout << "Error: Position (" << x << ", " << y << ") is occupied by an OBJECT.\n";
        return false;
    }

    if (grid[x][y] == DRONE)
    {
        std::cout << "Error: Position (" << x << ", " << y << ") is occupied by an DRONE.\n";
        return false;
    }

    grid[x][y] = DRONE;

    //store drone pointer and update position
    drone* new_drone = new drone("Drone_" + std::to_string(drone_count), drone_count);
    new_drone->set_position(x,y);
    drones.push_back(new_drone);
    drone_count++;
    std::cout << "Drone " << new_drone->get_name() << " (ID: " << new_drone->get_id()
               << ") successfully placed at position (" << x << ", " << y << ")\n";

    return true;
}

void map::remove_drone(int drone_id)
{
    for (int i = 0; i < drones.size(); i++)
    {
        if (drones[i]->get_id() == drone_id)
        {
            drones.erase(drones.begin() + i);
            drone_count--;
            std::cout << "Drone " << drone_id << " removed from the map.\n";
            return;
        }
    }

    std::cout << "Error: Drone with ID " << drone_id << " not found.\n";
}

drone* map::get_drone(int id)
{
    for (int i = 0; i < drones.size(); i++)
    {
        if (drones[i]->get_id() == id)
        {
            return drones[i];
        }
    }

    return nullptr;
}

//display map with objects, D = drone, OB = objects, X = empty
void map::display_map() const
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

// gets number of drones on map
int map::get_drone_count() const
{
    return drone_count;
}

// gets number of objects on the map
int map::get_object_count() const
{
    return object_count;
}