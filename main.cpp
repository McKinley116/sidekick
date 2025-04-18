//
// Created by Brandon McKinley on 4/18/25.
//

#include <iostream>
#include "drone.h"
//#include "map.h"
using namespace std;

//DRONE FUNCTIONS
void Drone::move() {
    cout << "Moving" << endl;
    battery -= 5;
};

void Drone::scan() {
    cout << "Scanning" << endl;
    battery -= 10;
};

void Drone::return_home() {
    cout << "Returning Home" << endl;
    battery -= 20;
};

void Drone::status() const {
    cout << "Drone: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Battery: " << battery << endl;
};

void Drone::battery_status() const {
    cout << "Battery: " << battery << endl;
}

void Drone::charge() const {
    cout << "Charging" << endl;
    battery += 10;
}

//MAP FUNCTIONS
//void Map::build();
//void Map::reset();
//void Map::print();
//void Map::populate();


int main() {

    Drone testDrone("TestDrone", 1);
    testDrone.status();
    testDrone.move();
    testDrone.scan();
    testDrone.battery_status();
    testDrone.return_home();

    return 0;
}