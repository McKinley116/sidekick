//
// Created by Brandon McKinley on 4/26/25.
// Scount drone focus on scanning and finding objects
//

#ifndef SCOUT_H
#define SCOUT_H
#include "drone.h"


class scout_drone : public Drone {
    public:
      scout_drone(const std::string &string) : Drone(name){}

      void scan(){
        if (battery > 5) {
          std::cout << "Scout Drone " << name << " is scanning the area at position " << position_x << "(x), " << position_y << "(y)...\n";
          battery -= 5; // Scanning consumes battery
        }else{
          std::cout << "Battery too low to scan. Please charge.\n";
        }
      }
};



#endif //SCOUT_H
