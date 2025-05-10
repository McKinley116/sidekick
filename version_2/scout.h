//
// Created by Brandon McKinley on 5/9/25.
//

#ifndef SCOUT_H
#define SCOUT_H
#include <string>


// This class inherites from the drone class, and has its own function that allows it to determine what an object that is scaned and gather data on it
class scout : public drone {

    scout (const std::string &name, int id)
    {
        vision_range = 6;
        scan_charges = 10;
    }

    bool scan_target(int x, int y) {} // i want this to determine what type of object it found (drone, building, blockade)
    int get_scan_charges() const {}
    int get_range() const {}

private:
    int vision_range;
    int scan_charges;
};



#endif //SCOUT_H
