//
// Created by Brandon McKinley on 5/9/25.
//

#ifndef FIGHTER_H
#define FIGHTER_H
#include <string>
#include "drone.h"


// This class inherites from the drone class, and has its own function that allows it to remove/ destroy objects that block a gridd coordinate
class fighter : public drone {

    fighter(const std::string &name, int id, map& gameMap) : drone(name, id), gameMap(gameMap)
    {
        vision_range = 3;
        missle_charges = 5;
        scan_charges = 5;
    }

    void scan_target(int x, int y) {}
    void fire_missle(int x, int y) {}
    void get_missle_count(int x, int y) {}

private:
    int vision_range;
    int missle_charges;
    map& gameMap;

};



#endif //FIGHTER_H
