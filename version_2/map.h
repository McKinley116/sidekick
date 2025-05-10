//
// Created by Brandon McKinley on 5/4/25.
//will store all the functions to generate the map and place drones

#ifndef MAP_H
#define MAP_H
#include <vector>

#include "drone.h"

class map
{
public:
    //enum used for storing objects in map
    enum grid_content
    {
        EMPTY = 0,
        DRONE = 1,
        OBJECT = 2,
    };
// added to allow scout drone to determine object type
    enum object_type
    {
        ENEMY_DRONE = 0,
        BUILDING = 1,
        BLOCKADE = 2,
    };

    //constructor
    map() : map_width(0), map_height(0), drone_count(0), object_count(0) {
    }

    void generate_map(); // generates random map size
    void generate_objects(); // generates random number of objects for placement on map
    void display_map() const; // displays map with drones
    int get_drone_count() const; // give drone count
    int get_object_count() const; // gives object count
    bool is_within_bounds(int x, int y) const; // checks if object or drone in bounds of map for placement
    void sort_drones_by_battery(); // uses bubble sort? works with drone vector or array?
    bool add_drone(int x, int y, drone* new_drone); // Modified to accept drone pointer
    void remove_drone(int drone_id); // removes drone based on id, which is specific
    drone* get_drone(int id); // gives drone id through reference without changing anything
    bool is_id_taken(int id) const;

private:
    std::vector<std::vector<grid_content> > grid; // works with enumerator to determine what is on grid
    std::vector<drone*> drones; // stores drones to keep track of them
    std::vector<std::vector<object_type>> object_type;
    int map_width;
    int map_height;
    int drone_count;
    int object_count;
};


#endif //MAP_H