//Sidekick
// Created by Brandon McKinley on 5/4/25.
//Version 2

#include <iostream>
#include "drone.h"
#include "map.h"
using namespace std;

int main() {
    map map;

    map.generate_map();
    map.generate_objects();
    map.display_map();

    return 0;
}