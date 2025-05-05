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

    void generate_map();
    void generate_objects();
    void get_drone_count();
    void get_object_count();

private:
    std::vector<std::vector<grid_content>> map_grid;
    int map_width;
    int map_height;
    int drone_count;
    int object_count;
};



#endif //MAP_H
