//
// Created by Brandon McKinley on 5/9/25.
//

#include "scout.h"

#include <iostream>
#include <ostream>

#include "map.h"

// the scan target function allows the scout
// drone to determine what an object is and what kind of minutitons the fighter drones needs to destryo it
void scout::scan_target(int x, int y)
{
    if (gid[x][y] == EMPTY)
    {
        cout << "This gird coordinate is empty" << endl;
    } else if (grid[x][y] == OBJECT)
    {
        cout << "This gird coordinate is an object" << endl;

    } else if (grid[x][y] == DRONE)
    {
        cout << "This gird coordinate is a drone" << endl;
    } else
        cout << "coordinates do not exsist within the map" << endl;
}