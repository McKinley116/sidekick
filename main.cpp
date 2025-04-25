//
// Created by Brandon McKinley on 4/18/25.
//

#include <iostream>
#include <vector>
#include <string> // for string usage in Drone
#include "drone.h"
#include "map.h"

//Function Prototypes

void display_menu();

// MAIN FUNCTION
int main() {

    // Create a 5x5 map
    Map map(5, 5);

    // User command and imputs
    std::string command, drone_name;
    int x, y;

    //Command loops
    display_menu();
    while (true ) {

        std::cout << "Enter a Command: " ;
        std::cin >> command;

        while (true) {
            std::cout << "\nEnter your command: ";
            std::cin >> command; // Command input

            if (command == "add_drone") {
                std::cin >> drone_name;
                Drone new_drone(drone_name);       // Create a new drone
                map.add_drone(new_drone);        // Add drone to the map
                std::cout << "Drone '" << drone_name << "' added to the map.\n";
            } else if (command == "move") {
                std::cin >> drone_name >> x >> y;
                // Find and move the drone by name
                for (int i = drone.size; i <= map.get_drone(drone_name)) {
                    if (drone.get_name() == drone_name) {
                        drone.move(x, y);
                        break;
                    }
                }
            } else if (command == "charge") {
                std::cin >> drone_name;
                for (auto& drone : map.get_drone(drone_name)) {
                    if (drone.get_name() == drone_name) {
                        drone.charge();
                        break;
                    }
                }
            } else if (command == "map") {
                map.display_map();         // Show the map
            } else if (command == "status") {
                std::cin >> drone_name;
                for (auto& drone : map.get_drone(drone_name)) {
                    if (drone.get_name() == drone_name) {
                        drone.status();
                        break;
                    }
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