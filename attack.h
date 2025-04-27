//
// Created by Brandon McKinley on 4/26/25.
// Attack Drone focus on attacking other drones or objects that might block pathways
//

#ifndef ATTACK_H
#define ATTACK_H
#include "drone.h"

class attack_drone : public Drone {
    public:
      attack_drone(const std::string &string) : Drone(string){}

      void attack_target(int x, int y) {
        if (battery_status() > 20) {
          std::cout << "Attack Drone" << get_name() << " is attacking target at position " << x << "(x), " << y << "(y)...\n";
          //Remove target from map
         // Map::remove_target(x, y);
        }else{
          std::cout << "Battery too low to attack. Please charge." << std::endl;
        }
      }
};



#endif //ATTACK_H
