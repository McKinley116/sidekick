//
// Created by Brandon McKinley on 4/18/25.
//
#ifndef MAP_H
#define MAP_H

#include "drone.h"
#include <vector>
#include <string>
#include <cstdlib> // allows map to be a random size
#include <ctime> // allows it to be seeded
#include <unordered_map> // sorts the drones by name
#include <algorithm> // for sorting

// Map class to manage a 2D grid and the drones placed on it
class Map {
private:
  int width;                   // Width of the map
  int height;                  // Height of the map
  // Key : Drone name
  std::unordered_map<std::string, Drone> drones;   // List of drones on the map, updated to an unordered map to organize and search for drones
  std::vector<std::vector<char>> grid;  // 2D grid to display the map

public:
  // Constructor to initialize a map with given dimensions
 Map(int width, int height);
    Map();

  // Check if given coordinates are within the map bounds
 // bool is_within_bounds(int x, int y) const;

  // Add a new drone to the map, return true if successful, false if drone name already exists
  bool add_drone(const Drone& drone);

  // Move a drone to specific coordinates, return true if successful
  bool move_drone(const std::string& name, int x, int y);

  // Charge the battery of a drone, return true if successful
  bool charge_drone(const std::string& name);

  // Display the 2D map with all existing drones
  void display_map() const;

  // Display the status of a specific drone, return true if found
  bool display_drone_status(const std::string& name) const;

  // searches for drones
  bool search_drone(const std::string &name)const;
};// name is const so it does not get changed

//sorts drone on battery level
void sort_drones_by_battery();

// generates objects on the map for the drone to find
void generate_objects(int object_count);

// checks if a position contains an object
bool check_object(int x, int y);



#endif // MAP_H

