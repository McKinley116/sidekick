//
// Created by Brandon McKinley on 4/18/25.
//

#ifndef DRONE_H
#define DRONE_H
#include <string>

class Drone {
public:

    Drone(std::string name, int id){
        this->name = name;
        this->id = id;
        this->battery = 100;
        this->position = 0;
        this->speed = 0;
    }

  void move();
  void scan();
  void return_home();
  void status() const;
    void battery_status() const;
    void charge() const;

 private:
   std::string name;
   int id;
   int battery;
   int position;
   int speed;

};



#endif //DRONE_H
