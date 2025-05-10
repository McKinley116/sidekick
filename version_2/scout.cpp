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
void scout::scan_target(int x, int y)
{
    if (scan_charges <= 0)
    {
        std::cout << "No chargesd left! Please charge drone!" << std::endl;
        break;
    }

    std:random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);

    std::cout << "Scanning target at (" << x << ", " << y << ")..." << std::endl;
    std::cout << "Scan charges left: " << scan_charges << std::endl;

    if (gameMap.grid[x][y] == map::EMPTY)
    {
        int object_type = dis(gen);

        switch (object_type)
        {
        case 0:
            std::cout << "Detected: Enemy Drone!\n";
            break;
        case 1:
            std::cout << "Detected: Building\n";
            break;
        case 2:
            std::cout << "Detected: Blockade\n";
            break;

        }
    }
    else if (gameMap.grid[y][x] == map::DRONE)
    {
        std::cout << "Detected: Friendly Drone\n";
    }
}