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

    object_types.resize(map_height);
    scanned_objects.resize(map_height);
    for (int i = 0; i < map_height; i++) {
        object_types[i].resize(map_width);
        scanned_objects[i].resize(map_width, false);
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


bool map::add_drone(int x, int y, drone* new_drone) {
    // Check if position is within bounds
    if (!is_within_bounds(x, y)) {
        std::cout << "Error: Position (" << x << ", " << y << ") is outside map bounds.\n";
        return false;
    }

    // Check if position is occupied
    if (grid[y][x] == OBJECT || grid[y][x] == DRONE) {
        std::cout << "Error: Position (" << x << ", " << y << ") is occupied.\n";
        return false;
    }

    // Place the drone on the grid
    grid[y][x] = DRONE;
    
    // Update drone's position and add to drones vector
    new_drone->set_position(x, y);
    drones.push_back(new_drone);
    drone_count++;
    
    std::cout << "Drone \"" << new_drone->get_name() << "\" (ID: " << new_drone->get_id() 
              << ") successfully placed at position (" << x << ", " << y << ")\n";
              
    return true;
}

void map::remove_drone(int drone_id) {
    for (size_t i = 0; i < drones.size(); i++) {
        if (drones[i]->get_id() == drone_id) {
            // Clear the grid position
            int x, y;
            x = drones[i]->get_position_x();  // Add these getter methods to drone class
            y = drones[i]->get_position_y();
            grid[y][x] = EMPTY;
            
            // Remove from vector
            delete drones[i];
            drones.erase(drones.begin() + i);
            drone_count--;
            std::cout << "Drone " << drone_id << " removed from the map.\n";
            return;
        }
    }
    std::cout << "Error: Drone with ID " << drone_id << " not found.\n";
}

void map::remove_object(int x, int y)
{
    // Check if coordinates are within bounds
    if (!is_within_bounds(x, y)) {
        std::cout << "Error: Position (" << x << ", " << y << ") is outside map bounds.\n";
        return;
    }

    // Check if there's actually an object at this position
    if (grid[y][x] != OBJECT) {
        std::cout << "Error: No object at position (" << x << ", " << y << ").\n";
        return;
    }

    // Clear the grid position
    grid[y][x] = EMPTY;

    // Clear the object type and scanned status
    if (y < object_types.size() && x < object_types[y].size()) {
        object_types[y][x] = ENEMY_DRONE; // Reset to default
    }
    if (y < scanned_objects.size() && x < scanned_objects[y].size()) {
        scanned_objects[y][x] = false;
    }

    // Decrease object count
    object_count--;

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
void map::display_map() const {
    // Print top border
    std::cout << "Map Size: " << map_width << "x" << map_height << "\n";
    std::cout << "Drones: " << drone_count << " Objects: " << object_count << "\n";
    std::cout << "Legend: D=Drone, O=Unknown Object, E=Enemy Drone, B=Building, X=Blockade\n\n";

    // Print column numbers
    std::cout << "   ";
    for (int x = 0; x < map_width; x++) {
        std::cout << std::setw(2) << x << " ";
    }
    std::cout << "\n";

    // Print top border
    std::cout << "   ";
    for (int x = 0; x < map_width; x++) {
        std::cout << "---";
    }
    std::cout << "\n";

    // Print grid with row numbers
    for (int y = 0; y < map_height; y++) {
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
                    if (is_object_scanned(x, y)) {
                        switch (get_object_type(x, y)) {
                            case ENEMY_DRONE:
                                symbol = 'E';
                                break;
                            case BUILDING:
                                symbol = 'B';
                                break;
                            case BLOCKADE:
                                symbol = 'X';
                                break;
                        }
                    } else {
                        symbol = 'O';
                    }
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

bool map::is_id_taken(int id) const {
    for (const auto& d : drones) {
        if (d->get_id() == id) {
            return true;
        }
    }
    return false;
}

// Add these implementations to map.cpp

void map::set_object_type(int x, int y, object_type type) {
    if (!is_within_bounds(x, y)) {
        return;
    }
    
    // Resize object_types vector if needed
    if (object_types.size() <= y) {
        object_types.resize(y + 1);
    }
    if (object_types[y].size() <= x) {
        object_types[y].resize(x + 1);
    }
    
    object_types[y][x] = type;
    
    // Mark object as scanned
    if (scanned_objects.size() <= y) {
        scanned_objects.resize(y + 1);
    }
    if (scanned_objects[y].size() <= x) {
        scanned_objects[y].resize(x + 1);
    }
    scanned_objects[y][x] = true;
}

map::object_type map::get_object_type(int x, int y) const {
    if (!is_within_bounds(x, y) || 
        y >= object_types.size() || 
        x >= object_types[y].size()) {
        return ENEMY_DRONE; // Default return value
    }
    return object_types[y][x];
}

bool map::is_object_scanned(int x, int y) const {
    if (!is_within_bounds(x, y) || 
        y >= scanned_objects.size() || 
        x >= scanned_objects[y].size()) {
        return false;
    }
    return scanned_objects[y][x];
}

void map::bubble_sort() {
    int n = drones.size();
    std::vector<drone*> sorted_drones = drones;  // Create a copy

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sorted_drones[j]->get_battery() > sorted_drones[j + 1]->get_battery()) {
                drone* temp = sorted_drones[j];
                sorted_drones[j] = sorted_drones[j + 1];
                sorted_drones[j + 1] = temp;
            }
        }
    }

    drones = sorted_drones;  // Replace original with sorted copy
}

void map::display_sorted_drones() const {
    std::cout << "\nDrone List (Sorted by Battery Level):\n";
    std::cout << "--------------------------------\n";
    std::cout << "Name\t\tID\tType\t\tBattery\tPosition\n";
    std::cout << "--------------------------------\n";

    for (const auto& drone : drones) {
        std::cout << std::left << std::setw(16) << drone->get_name()
                 << std::setw(8) << drone->get_id()
                 << std::setw(16) << drone->get_drone_type()
                 << std::setw(8) << drone->get_battery() << "% "
                 << "(" << drone->get_position_x() << ", "
                 << drone->get_position_y() << ")\n";
    }
    std::cout << "--------------------------------\n";
}
