//
// Created by Brandon McKinley on 5/9/25.
//

#include "fighter.h"

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
void fire_missle(int x, int y) {} // allows the user to choose the munititons and fire them
int get_missle_count(int x, int y)// shows the user how many missle are left
{
    return missle_charges;
}