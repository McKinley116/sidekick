//
// Created by Brandon McKinley on 5/4/25.
//will store all the functions to generate the map and place drones

#ifndef MAP_H
#define MAP_H
#include <vector>

class map {
public:
    //enum used for storing objects in map
    enum grid_content
    {
        EMPTY = 0,
        DRONE = 1,
        OBJECT = 2,
    };

    //Constructor that uses functions to generate the "defaults" of a new map
    map()
    {
        generate_map();
        generate_objects();
    };

    void generate_map(); // generates random map size
    void generate_objects(); // generates random number of objects for placement on map
    void display_map(); // displays map with drones
    void get_drone_count(); // give drone count
    void get_object_count(); // gives object count
    bool is_within_bounds(int x, int y) const; // checks if object or drone in bounds of map for placement
    void sort_drones_by_battery(); // uses bubble sort?

private:
    std::vector<std::vector<grid_content> > map_grid; // works with enumerator to determine what is on grid
    int map_width;
    int map_height;
    int drone_count;
    int object_count;
};



#endif //MAP_H
