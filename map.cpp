//
// Created by Brandon McKinley on 4/18/25.
//

#include "map.h"
using namespace std;

// MAP CLASS IMPLEMENTATION

// Display the current state of the map
void Map::display_map() const {
    cout << "Map State:\n";
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            // Check if a drone occupies the current position
            bool drone_found = false;
            for (const Drone *drone : drones) {
                if (drone->get_position_x() == j && drone->get_position_y() == i) {
                    cout << "D "; // 'D' represents a drone
                    drone_found = true;
                    break;
                }
            }
            if (!drone_found) {
                cout << "- "; // Empty cell
            }
        }
        cout << "\n";
    }
}

// Add a drone to the map if there is space
void Map::add_drone(Drone &drone) {
    if (static_cast<size_t>(width * height) <= drones.size()) {
        cout << "The map is full, cannot add more drones.\n";
        return;
    }
    drones.push_back(&drone);
    cout << "Drone " << drone.get_name() << " added to the map.\n";
}