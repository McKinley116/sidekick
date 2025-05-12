//
// Created by Brandon McKinley on 5/9/25.
//

#include "fighter.h"
#include "map.h"
#include <iostream>

//the scan target allows the fighter drone to scan an object that a scout drone must first determine idetification, then determines what kind of munitions to use; standard, heavy, burst.
void fighter::scan_target(int x, int y) {
    if (missle_charges <= 0) {
        std::cout << "No missiles left! Please rearm drone!" << std::endl;
        return;
    }

    if (!gameMap.is_within_bounds(x, y)) {
        std::cout << "Target coordinates are outside map boundaries!" << std::endl;
        return;
    }

    std::cout << "Analyzing target at (" << x << ", " << y << ")..." << std::endl;
    
    if (gameMap.grid[y][x] == map::OBJECT) {
        map::object_type target_type = gameMap.get_object_type(x, y);
        
        switch (target_type) {
            case map::ENEMY_DRONE:
                std::cout << "Enemy Drone detected. Recommended munition: Standard missile\n";
                break;
            case map::BUILDING:
                std::cout << "Building detected. Recommended munition: Heavy missile\n";
                break;
            case map::BLOCKADE:
                std::cout << "Blockade detected. Recommended munition: Burst missile\n";
                break;
            default:
                std::cout << "Target not yet identified by scout drone. Request scout scan first.\n";
                break;
        }
    }
    else if (gameMap.grid[y][x] == map::EMPTY) {
        std::cout << "No valid target at this location.\n";
    }
    else if (gameMap.grid[y][x] == map::DRONE) {
        std::cout << "WARNING: Friendly drone detected! Do not engage!\n";
    }
}
void fighter::fire_missle(int x, int y) {
    if (missle_charges <= 0) {
        std::cout << "No missiles left! Please rearm drone!" << std::endl;
        return;
    }

    if (!has_enough_battery(15)) {  // Firing costs 15% battery
        std::cout << "Not enough battery power! Please charge drone!" << std::endl;
        return;
    }

    if (!gameMap.is_within_bounds(x, y)) {
        std::cout << "Target coordinates are outside map boundaries!" << std::endl;
        return;
    }

    if (gameMap.grid[y][x] != map::OBJECT) {
        std::cout << "No valid target at this location!" << std::endl;
        return;
    }

    map::object_type target_type = gameMap.get_object_type(x, y);
    
    // Display munition options
    std::cout << "\nSelect munition type:" << std::endl;
    std::cout << "1. Standard missile (Best for Enemy Drones)" << std::endl;
    std::cout << "2. Heavy missile (Best for Buildings)" << std::endl;
    std::cout << "3. Burst missile (Best for Blockades)" << std::endl;
    std::cout << "4. Cancel attack" << std::endl;

    int choice;
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;

    bool hit_successful = false;
    switch (choice) {
        case 1: // Standard missile
            if (target_type == map::ENEMY_DRONE) {
                std::cout << "Direct hit with Standard missile! Enemy drone destroyed!" << std::endl;
                hit_successful = true;
            } else {
                std::cout << "Standard missile had limited effect on this target type." << std::endl;
                hit_successful = true;
            }
            break;

        case 2: // Heavy missile
            if (target_type == map::BUILDING) {
                std::cout << "Direct hit with Heavy missile! Building destroyed!" << std::endl;
                hit_successful = true;
            } else {
                std::cout << "Heavy missile had limited effect on this target type." << std::endl;
                hit_successful = true;
            }
            break;

        case 3: // Burst missile
            if (target_type == map::BLOCKADE) {
                std::cout << "Direct hit with Burst missile! Blockade destroyed!" << std::endl;
                hit_successful = true;
            } else {
                std::cout << "Burst missile had limited effect on this target type." << std::endl;
                hit_successful = true;
            }
            break;

        case 4:
            std::cout << "Attack cancelled." << std::endl;
            return;

        default:
            std::cout << "Invalid choice. Attack cancelled." << std::endl;
            return;
    }

    if (hit_successful) {
        decrease_battery(15);  // Decrease battery by 15%
        missle_charges--;
        gameMap.remove_object(x, y);
        std::cout << "Battery level: " << get_battery() << "%" << std::endl;
        std::cout << "Missiles remaining: " << missle_charges << std::endl;

    }
}
void fighter::get_missle_count(int x, int y) {
    std::cout << "Missiles remaining: " << missle_charges << std::endl;
}

void fighter::rearm_missiles() {
    missle_charges = 5;
    std::cout << "Missiles rearmed. Charges: " << missle_charges << std::endl;
}