//
// Created by Brandon McKinley on 5/4/25.
//will store all the functions to generate the map and place drones

#ifndef MAP_H
#define MAP_H

class map {

   private:
    int map_width;
    int map_height;
    int drone_count;
    int object_count;
    void generate_map();
    void generate_objects();
    void get_drone_count();
    void get_object_count();
};



#endif //MAP_H
