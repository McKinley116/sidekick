//
// Created by Brandon McKinley on 5/9/25.
//

#include "user_menu.h"
#include "scout.h"
#include "fighter.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>


void user_menu::display_menu() const {
    std::cout << "\n=== Drone Management System ===\n";
    std::cout << "1. Add new drone\n";
    std::cout << "2. Move drone\n";
    std::cout << "3. Remove drone\n";
    std::cout << "4. Display map\n";
    std::cout << "5. Show drone information\n";
    std::cout << "6. Issue drone commands\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

void user_menu::clear_input_buffer() const {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void user_menu::handle_add_drone() {
    std::string name;
    int id, x, y, type;
    
    // Get drone name
    std::cout << "Enter drone name: ";
    clear_input_buffer();
    std::getline(std::cin, name);
    
    // Get drone ID and validate it
    std::cout << "Enter drone ID: ";
    std::cin >> id;
    
    // Keep asking for a new ID if the current one is taken
    while (gameMap.is_id_taken(id)) {
        std::cout << "ID " << id << " is already taken. Please enter a different ID: ";
        std::cin >> id;
    }
    
    // Get coordinates
    std::cout << "Enter X coordinate for drone: ";
    std::cin >> x;
    std::cout << "Enter Y coordinate for drone: ";
    std::cin >> y;

    // Get drone type
    std::cout << "\nSelect drone type:\n";
    std::cout << "1. Scout Drone\n";
    std::cout << "2. Fighter Drone\n";
    std::cout << "Enter your choice (1-2): ";
    std::cin >> type;

    // Create new drone with user-provided name and ID
    drone* new_drone = nullptr;
    switch(type) {
    case 1:
        new_drone = new scout(name, id, gameMap);
        break;
    case 2:
        new_drone = new fighter(name, id, gameMap);
        break;
    default:
        std::cout << "Invalid drone type\n";
        return;
    }

    if (gameMap.add_drone(x, y, new_drone)) {
        std::cout << "Drone added successfully!\n";
        gameMap.display_map();
    } else {
        delete new_drone;
        std::cout << "Failed to add drone. Please try again.\n";
    }


}

void user_menu::handle_drone_commands() const
{
    if (gameMap.get_drone_count() == 0)
    {
        std::cout << "No drones avaliable!\n";
    }

    std::cout << "\n Avaliable Drones:\n";
    for (int i = 0; i < gameMap.get_drone_count(); i++)
    {
        drone* drone = gameMap.get_drone(i);
        if (drone)
        {
            std::cout << "ID: " << drone->get_id()
                       << " | Name: " << drone->get_name()
                       << " | Position: (" << drone->get_position_x()
                       << "," << drone->get_position_y() << ")\n";

        }
    }

    // Get drone selection
    int drone_id;
    std::cout << "\nEnter drone ID: ";
    std::cin >> drone_id;

    drone* selected_drone = gameMap.get_drone(drone_id);
    if (!selected_drone) {
        std::cout << "Drone not found!\n";
    }

    std::cout << "\nDrone Type: " << selected_drone->get_drone_type() << "\n";
    std::cout << "Available Commands:\n";

    int choice, x, y;
    if (strcmp(selected_drone->get_drone_type(), "Scout") == 0) {
        auto* scout_drone = static_cast<scout*>(selected_drone);
        std::cout << "\nScout Drone Commands:\n";
        std::cout << "1. Scan target\n";
        std::cout << "2. Check scan charges\n";
        std::cout << "3. Back to main menu\n";
        std::cout << "Enter command: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter X coordinate: ";
            std::cin >> x;
            std::cout << "Enter Y coordinate: ";
            std::cin >> y;
            scout_drone->scan_target(x, y);
            break;
        case 2:
            std::cout << "Scan charges remaining: " << scout_drone->get_scan_charges() << "\n";
            break;
        case 3:
            return;
        default:
            std::cout << "Invalid command!\n";
            break;
        }
    }

    else if (strcmp(selected_drone->get_drone_type(), "Fighter") == 0) {
        auto* fighter_drone = static_cast<fighter*>(selected_drone);
        std::cout << "\nFighter Drone Commands:\n";
        std::cout << "1. Scan target\n";
        std::cout << "2. Fire missile\n";
        std::cout << "3. Check missile count\n";
        std::cout << "4. Back to main menu\n";
        std::cout << "Enter command: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter X coordinate: ";
            std::cin >> x;
            std::cout << "Enter Y coordinate: ";
            std::cin >> y;
            fighter_drone->scan_target(x, y);
            break;
        case 2:
            std::cout << "Enter X coordinate: ";
            std::cin >> x;
            std::cout << "Enter Y coordinate: ";
            std::cin >> y;
            fighter_drone->fire_missle(x, y);
            break;
        case 3:
            fighter_drone->get_missle_count(x, y);
            break;
        case 4:
            return;
        default:
            std::cout << "Invalid command!\n";
            break;
        }
    }
    else {
        std::cout << "Unknown drone type!\n";
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
        
        // Store properties of the existing drone
        std::string droneName = selectedDrone->get_name();
        int droneID = selectedDrone->get_id();
        const char* droneType = selectedDrone->get_drone_type();
        
        // Remove drone from old position
        gameMap.remove_drone(droneId);
        
        // Create new drone with same properties
        drone* movedDrone = nullptr;
        if (strcmp(droneType, "Scout") == 0) {
            movedDrone = new scout(droneName, droneID, gameMap);
        } else if (strcmp(droneType, "Fighter") == 0) {
            movedDrone = new fighter(droneName, droneID, gameMap);
        }

        if (movedDrone) {
            movedDrone->set_position(newX, newY);
            if (gameMap.add_drone(newX, newY, movedDrone)) {
                std::cout << "Drone moved successfully!\n";
                gameMap.display_map();
            } else {
                std::cout << "Failed to move drone - invalid position\n";
                delete movedDrone;
            }
        } else {
            std::cout << "Unknown drone type!\n";
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
                handle_drone_commands();
                break;

            case 7:
                running = false;
                std::cout << "Exiting program...\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}