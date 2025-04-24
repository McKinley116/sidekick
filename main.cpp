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
    std::string drone_name;
    int x, y, command;

    //Command loops
    display_menu();
    while (true ) {

        std::cout << "Enter a Command: " ;
        std::cin >> command;

        switch (command) {

            case '1':
                std::cout << "Enter Drone Name: ";
                std::cin >> drone_name;
                Drone new_drone(drone_name); // created constructor in drone.h
                map.add_drone(new_drone);
                std::cout << "Drone: " << drone_name << " added to the map.\n";
                break;

            case '2':
                std::cout << "Enter Drone Name and position (x) (y): ";
                std::cin >> drone_name >> " " >> x >> " " >> y >> std::endl;
                // looks for drones and moves them  around the map
                for (auto& drone : map.get_drone(drone_name)) {
                    if (drone.get_name() == drone_name) {
                        drone.move(x, y);
                        break;
                    }
                }

            case '3':
                std::cin >> drone_name;
                for (auto& drone : map.get_drone(drone_name)) {
                    if (drone.get_name() == drone_name) {
                        drone.charge();
                        break;
                    }
                }

            case '4':
                map.display_map();
                break;

            case '5':
                std::cin >> drone_name;
                for (auto& drone : map.get_drone(drone_name)) {
                    if (drone.get_name() == drone_name) {
                        drone.status();
                        break;
                    }
                }

            case '6':
                std::cout << "Exiting program... Goodbye!\n";
                break;

            default:
                std::cout << "Invalid command! Try again.\n";
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