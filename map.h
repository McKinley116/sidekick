//
// Created by Brandon McKinley on 4/18/25.
//

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include "drone.h"

class Map {

public:
  Map(int width, int height) : width(width), height(height) {
    grid.resize(width * height, "-");
  } // defines size of map
  void add_drone(Drone &drone); // references drone object from drone class
  void display_map() const; // displays map

private:
  int width;
  int height;
  std::vector<std::string> grid; // used as a 2d grid to represent the map
  std::vector<Drone *> drones; // list of drone on the map using a pointer
};



#endif //MAP_H
