//
// Created by Brandon McKinley on 4/18/25.
//
#include "map.h"
#include <iostream>
#include <random>
#include <iomanip>

// Constructor for the Map class
Map::Map() {
    //seeds the random number generator
    std::srand(std::time(nullptr));
    width = std::rand() % 10 + 1;
    height = std::rand() % 10 + 1;
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

}

// Charge a drone by name
bool Map::charge_drone(const std::string& name) {

}

// Display the map with drones
void Map::display_map() const {

}

// Display the status of a specific drone
bool Map::display_drone_status(const std::string& name) const {
    Drone* drone;
    drone = search_drone(name);
    if (drone != nullptr) {
        drone->status();
        return true;
    }
    return false;
}

//Search for drone by name using a pointer
Drone* Map::search_drone(const std::string& name) {
    auto it = drones.find(name);
    if (it != drones.end()) {
        return &it->second; // return a pointer to the drone
    }
    return nullptr;
}

// Sort drones by battery level



