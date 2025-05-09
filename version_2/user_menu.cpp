//
// Created by Brandon McKinley on 5/9/25.
//

#include "user_menu.h"
#include <limits>

void user_menu::display_menu() const {
    std::cout << "\n=== Drone Management System ===\n";
    std::cout << "1. Add new drone\n";
    std::cout << "2. Move drone\n";
    std::cout << "3. Remove drone\n";
    std::cout << "4. Display map\n";
    std::cout << "5. Show drone information\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

void user_menu::clear_input_buffer() const {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void user_menu::handle_add_drone() {
    int x, y;
    std::cout << "Enter X coordinate for drone: ";
    std::cin >> x;
    std::cout << "Enter Y coordinate for drone: ";
    std::cin >> y;

    if (gameMap.add_drone(x, y)) {
        std::cout << "Drone added successfully!\n";
        gameMap.display_map();
    }
}

void user_menu::handle_move_drone() {
    int droneId, newX, newY;
    std::cout << "Enter drone ID to move: ";
    std::cin >> droneId;

    drone* selectedDrone = gameMap.get_drone(droneId);
    if (selectedDrone) {
        std::cout << "Enter new X coordinate: ";
        std::cin >> newX;
        std::cout << "Enter new Y coordinate: ";
        std::cin >> newY;

        // First remove drone from old position
        gameMap.remove_drone(droneId);

        // Try to add drone at new position
        if (gameMap.add_drone(newX, newY)) {
            std::cout << "Drone moved successfully!\n";
            gameMap.display_map();
        } else {
            std::cout << "Failed to move drone - invalid position\n";
        }
    } else {
        std::cout << "Drone not found!\n";
    }
}

void user_menu::handle_remove_drone() {
    int droneId;
    std::cout << "Enter drone ID to remove: ";
    std::cin >> droneId;
    gameMap.remove_drone(droneId);
    gameMap.display_map();
}

void user_menu::handle_show_drone_info() {
    int droneId;
    std::cout << "Enter drone ID: ";
    std::cin >> droneId;

    drone* selectedDrone = gameMap.get_drone(droneId);
    if (selectedDrone) {
        std::cout << "\nDrone Information:\n";
        std::cout << "Name: " << selectedDrone->get_name() << "\n";
        std::cout << "ID: " << selectedDrone->get_id() << "\n";
        std::cout << "Battery: " << selectedDrone->get_battery() << "%\n";
        selectedDrone->get_position();
    } else {
        std::cout << "Drone not found!\n";
    }
}

void user_menu::run_menu() {
    int choice;
    bool running = true;

    while (running) {
        display_menu();
        std::cin >> choice;
        clear_input_buffer();

        switch (choice) {
            case 1:
                handle_add_drone();
                break;

            case 2:
                handle_move_drone();
                break;

            case 3:
                handle_remove_drone();
                break;

            case 4:
                gameMap.display_map();
                break;

            case 5:
                handle_show_drone_info();
                break;

            case 6:
                running = false;
                std::cout << "Exiting program...\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}
