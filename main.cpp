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