//
// Created by Brandon McKinley on 4/18/25.
//

#include <iostream>
#include <string> // for string usage in Drone
#include "drone.h"
#include "map.h"

// Function Prototypes
void display_menu();

// MAIN FUNCTION
int main() {
    // Create a 5x5 map
    Map map(5, 5);

    // User command and inputs
    std::string command, drone_name;
    int x, y;

    // Display menu
    display_menu();

    // Command loop
    while (true) {
        std::cout << "Enter a command: ";
        std::cin >> command;

        if (command == "add_drone") {
            std::cin >> drone_name;
            Drone new_drone(drone_name);      // Create a new drone
            if (map.add_drone(new_drone)) {  // Add drone to the map and check if successful
                std::cout << "Drone '" << drone_name << "' added to the map.\n";
            } else {
                std::cout << "Error: Drone with name '" << drone_name << "' already exists.\n";
            }
        } else if (command == "move") {
            std::cin >> drone_name >> x >> y;
            if (map.is_within_bounds(x, y)) { // Check if coordinates are valid
                if (map.move_drone(drone_name, x, y)) {
                    std::cout << "Drone '" << drone_name << "' moved to (" << x << ", " << y << ").\n";
                } else {
                    std::cout << "Error: Drone '" << drone_name << "' not found.\n";
                }
            } else {
                std::cout << "Error: Coordinates (" << x << ", " << y << ") are out of bounds.\n";
            }
        } else if (command == "charge") {
            std::cin >> drone_name;
            if (map.charge_drone(drone_name)) {
                std::cout << "Charging drone '" << drone_name << "'.\n";
            } else {
                std::cout << "Error: Drone '" << drone_name << "' not found.\n";
            }
        } else if (command == "map") {
            map.display_map();  // Display the 2D map with drone locations
        } else if (command == "status") {
            std::cin >> drone_name;
            if (!map.display_drone_status(drone_name)) {
                std::cout << "Error: Drone '" << drone_name << "' not found.\n";
            }
        } else if (command == "exit") {
            std::cout << "Exiting program. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid command. Try again.\n";
        }
    }

    return 0;
}

// Function to display the menu
void display_menu() {
    std::cout << "\n--- Commands ---\n";
    std::cout << "1) add_drone <name>\n";
    std::cout << "2) move <drone_name> <x> <y>\n";
    std::cout << "3) charge <drone_name>\n";
    std::cout << "4) map\n";
    std::cout << "5) status <drone_name>\n";
    std::cout << "6) exit\n";
    std::cout << "----------------\n";
}