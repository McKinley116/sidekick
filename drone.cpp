//
// Created by Brandon McKinley on 4/18/25.
//
#include <iostream>
#include <string>
#include "drone.h"
using namespace std;

// DRONE CLASS IMPLEMENTATION

Drone::Drone(const std::string &string) {
    name = string;
    id = 0;
    battery = 100;
    position_x = 0;
    position_y = 0;
    speed = 0;
}


// Move the drone to a new position with battery validation
void Drone::move(int x, int y) {
    if (battery > 10) {
        battery -= 10; // Movement consumes battery
        position_x = x; // Update x position
        position_y = y; // Update y position
        cout << "Drone " << name << " moved to position " << x << "(x), " << y << "(y).\n";
    } else {
        cout << "Battery too low to move. Please charge.\n";
    }
}

// Scan the area at the current position with battery validation
void Drone::scan(int x, int y) {
    if (battery > 5) {
        cout << "Drone " << name << " is scanning the area at position " << x << "(x), " << y << "(y)...\n";
        battery -= 5; // Scanning consumes battery
    } else {
        cout << "Battery too low to scan. Please charge.\n";
    }
}

// Return the drone to its home position (0, 0) with battery validation
void Drone::return_home() {
    if (battery > 10) {
        position_x = 0; // Reset to home x position
        position_y = 0; // Reset to home y position
        cout << name << " is returning home. Current position: 0(x), 0(y).\n";
        battery -= 10; // Returning home consumes battery
    } else {
        cout << "Battery too low to return home. Please charge.\n";
    }
}

// Display the current status of the drone
void Drone::status() const {
    cout << "Drone Name: " << name << "\n";
    cout << "Drone ID: " << id << "\n";
    cout << "Battery Level: " << battery << "%\n";
    cout << "Current Speed: " << speed << " units\n";
    cout << "Current Position: " << position_x << "(x), " << position_y << "(y)\n";
}

// Display the drone's current battery status
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

// Charge the drone's battery by a fixed amount
void Drone::charge() {
    battery = min(battery + 10, 100); // Prevent overcharging beyond 100%
    cout << "Charging... Battery level is now " << battery << "%.\n";
}

// Getter for the drone's name
std::string Drone::get_name() const {
    return name;
}

// Get the drone's current position
void Drone::get_position() const {
    cout << "Current Position: " << position_x << "(x), " << position_y << "(y)\n";
}

// Set the drone's current position explicitly
void Drone::set_position(int x, int y) {
    position_x = x;
    position_y = y;
}

// Get the drone's current x position
int Drone::get_position_x() const {
    return position_x;
}

// Get the drone's current y position
int Drone::get_position_y() const {
    return position_y;
}