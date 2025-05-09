#include <iostream>
#include "map.h"
#include "drone.h"
using namespace std;

int main() {
    cout << "Starting program..." << endl;

    map gameMap;
    gameMap.generate_map();
    gameMap.generate_objects();
    gameMap.display_map();


    return 0;
}
