//
// Created by Brandon McKinley on 4/18/25.
//

#include <iostream>
#include <vector>
#include <string> // for string usage in Drone
#include "drone.h"
#include "map.h"

using namespace std;

// MAIN FUNCTION
int main() {

    // Create a 5x5 map
    Map map(5, 5);

    // Create a drone and add it to the map
    Drone drone1("Alpha", 1);
    map.add_drone(drone1);
    drone1.status();

    // Move the drone and display its progress
    drone1.move(2, 3);

    // Charge the drone
    drone1.charge();
    drone1.battery_status();

    // Display the map
    map.display_map();

    drone1.move(3, 3);
    map.display_map();
    drone1.status();

    return 0;
}