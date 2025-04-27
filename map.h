//
// Created by Brandon McKinley on 4/18/25.
//
#ifndef MAP_H
#define MAP_H

#include "drone.h"
#include <vector>
#include <string>

// Map class to manage a 2D grid and the drones placed on it
class Map {
private:
  int width;                   // Width of the map
  int height;                  // Height of the map
  std::vector<Drone> drones;   // List of drones on the map

public:
  // Constructor to initialize a map with given dimensions
  Map(int width, int height);

  // Check if given coordinates are within the map bounds
  bool is_within_bounds(int x, int y) const;

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
};




#endif // MAP_H

