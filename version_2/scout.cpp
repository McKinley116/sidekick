//
// Created by Brandon McKinley on 5/9/25.
//

#include "scout.h"
#include <random>
#include <iostream>
#include <ostream>
#include "map.h"

// the scan target function allows the scout
// drone to determine what an object is and what kind of minutitons the fighter drones needs to destryo it
void scout::scan_target(int x, int y) {
    if (scan_charges <= 0) {
        std::cout << "No charges left! Please charge drone!" << std::endl;
        return;
    }

    if (!gameMap.is_within_bounds(x, y)) {
        std::cout << "Target coordinates are outside map boundaries!" << std::endl;
        return;
    }

    std::cout << "Scanning target at (" << x << ", " << y << ")..." << std::endl;
    
    if (gameMap.grid[y][x] == map::OBJECT) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 2);
        
        map::object_type detected_type;
        switch (dis(gen)) {
            case 0:
                detected_type = map::ENEMY_DRONE;
                std::cout << "Detected: Enemy Drone!\n";
                break;
            case 1:
                detected_type = map::BUILDING;
                std::cout << "Detected: Building\n";
                break;
            case 2:
                detected_type = map::BLOCKADE;
                std::cout << "Detected: Blockade\n";
                break;
        }
        
        gameMap.set_object_type(x, y, detected_type);
        scan_charges--;
        std::cout << "Scan charges left: " << scan_charges << std::endl;
    }
    else if (gameMap.grid[y][x] == map::EMPTY) {
        std::cout << "This location is empty.\n";
    }
    else if (gameMap.grid[y][x] == map::DRONE) {
        std::cout << "Detected: Friendly Drone\n";
    }
}