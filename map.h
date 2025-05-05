//
// Created by Brandon McKinley on 5/4/25.
//will store all the functions to generate the map and place drones

#ifndef MAP_H
#define MAP_H

class map {
public:

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
    int map_width;
    int map_height;
    int** map_size;
    int drone_count;
    int object_count;
};



#endif //MAP_H
