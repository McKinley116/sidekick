//
// Created by Brandon McKinley on 4/18/25.
//

#include <iostream>
#include "drone.h"
#include "map.h"
using namespace std;

//DRONE FUNCTIONS
void Drone::move(int x, int y) {
    if (battery > 10) {
        battery -= 10; // Moving consumes battery
        cout << "Drone " << name << " moved to position "<< x << "(x) " << y << "(y)" <<  ".\n";
    } else {
        cout << "Battery too low to move. Please charge.\n";
    }

};

void Drone::scan(int x, int y) {
    if (battery > 5) {
        cout << "Drone " << name << " is scanning the area...\n";
        battery -= 5; // Scanning uses battery
    } else {
        cout << "Battery too low to scan. Please charge.\n";
    }

};

void Drone::return_home() {
    if (battery > 10) {
        cout <<  name << " is returning home. Current position: " << ".\n";
        battery -= 10; // Returning home consumes battery
    } else {
        cout << "Battery too low to return home. Please charge.\n";
    }

};

void Drone::status() const {
    cout << "Drone Name: " << name << "\n";
    cout << "Drone ID: " << id << "\n";
    cout << "Battery Level: " << battery << "%\n";
    cout << "Current Speed: " << speed << "\n";
};

void Drone::battery_status() const {
    cout << "Battery Level: " << battery << "%\n";
    if (battery > 50) {
        cout << "Battery Status: Good\n";
    } else if (battery > 20) {
        cout << "Battery Status: Low\n";
    } else {
        cout << "Battery Status: Critical. Please charge.\n";
    }

}

void Drone::charge() {
    cout << "Charging" << endl;
    battery += 10;
}

std::string Drone::get_name() const {
    return name;
}

//MAP FUNCTIONS
void Map::display_map() const {
    cout << "Map State: " << endl;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i * width + j] << " "; // prints each portion of the map
        }
    }
    cout << endl;
}

void Map::add_drone(Drone &drone) {
    if (static_cast<size_t>(width * height) <= drone.size())
        cout << "The map is full, cannot add." << endl;
    drone.push_back(drone);
    cout << "Drone added to map." << endl;
}


int main() {

    Drone testDrone("Alpha", 2342);
    Map map(10, 10);
    map.add_drone(testDrone);
    map.display_map();

    return 0;
}