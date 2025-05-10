//
// Created by Brandon McKinley on 5/9/25.
//

#include "fighter.h"
#include "map.h"
#include <iostream>
#include <ostream>

//the scan target allows the fighter drone to scan an object that a scout drone must first determine idetification, then determines what kind of munitions to use; standard, heavy, burst.
void scan_target(int x, int y)// scans the target to determine what type of munititon to use
{
    if (scan_charges <= 0)
    {
        std::cout << "No chargesd left! Please charge drone!" << std::endl;
        break;
    }

    std::cout << "Scanning target at (" << x << ", " << y << ")..." << std::endl;
    std::cout << "Scan charges left: " << scan_charges << std::endl;

    if
}
void fire_missle(int x, int y) {} // allows the user to choose the munititons and fire them
void get_missle_count(int x, int y) {} // shows the user how many missle are left
