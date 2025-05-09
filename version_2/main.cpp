#include <iostream>
#include "map.h"
#include "user_menu.h"
using namespace std;

int main() {
    std::cout << "Starting Drone Management System..." << std::endl;

    map gameMap;
    gameMap.generate_map();
    gameMap.generate_objects();
    gameMap.display_map();

    user_menu menu(gameMap);
    menu.run_menu();

    return 0;
}
