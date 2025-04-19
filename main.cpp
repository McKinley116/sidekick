//
// Created by Brandon McKinley on 4/18/25.
//

#include <iostream>
#include "drone.h"
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

int Drone::getPositionX() const {
    return position_x;
}

//MAP FUNCTIONS
//void Map::build();
//void Map::reset();
//void Map::print();
//void Map::populate();


int main() {

    Drone testDrone("TestDrone", 1);
    testDrone.status();
    testDrone.move(10, 2);
    testDrone.scan(10, 2);
    testDrone.battery_status();
    testDrone.return_home();

    return 0;
}