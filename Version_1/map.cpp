//
// Created by Brandon McKinley on 4/18/25.
//
#include "map.h"
#include <random>
#include <iomanip>

// Constructor for the Map class
Map::Map() {
    //seeds the random number generator
    std::srand(std::time(nullptr));
    width = std::rand() % 10 + 1;
    height = std::rand() % 10 + 1;
}

void map::generate_map() {
    std::cout << "Generating map..." << std::endl;  // Debug print
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10, 40);
    
    this->map_width = dis(gen);
    this->map_height = dis(gen);

    std::cout << "Generated dimensions: " << map_width << "x" << map_height << std::endl;  // Debug print

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

void map::generate_objects() {
    std::cout << "Generating objects..." << std::endl;  // Debug print
    // ... rest of the function ...
}

// Check if coordinates are within map bounds
// bool Map::is_within_bounds(int x, int y) const {
    //return x >= 0 && x < width && y >= 0 && y < height;
//}

// Add a drone to the map
bool Map::add_drone(const Drone& drone) {
   if (drones.find(drone.get_name()) == drones.end()) {
       return false;
   }
    drones [drone.get_name()] = drone;
    return true;
}

// Move a drone to the specified coordinates using an unordered map
bool Map::move_drone(const std::string& name, int x, int y) {
    return true;
}

// Charge a drone by name
bool Map::charge_drone(const std::string &name) {

}

void map::display_map() {
    std::cout << "Displaying map..." << std::endl;  // Debug print
    // ... rest of the function ...
}

// Display the status of a specific drone
/*
bool Map::display_drone_status(const std::string& name) const {
    Drone* drone = search_drone(name);
    if (drone != nullptr) {
        drone->status();
        return true;
    }
    return false;
}
*/

//Search for drone by name using a pointer
/*
bool Map::search_drone(const std::string& name) const {
    auto it = drones.find(name);
    if (it != drones.end()) {
        return &it->second; // return a pointer to the drone
    }
    return nullptr;
}
 */


// Sort drones by battery level