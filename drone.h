//
// Created by Brandon McKinley on 4/18/25.
//

#ifndef DRONE_H
#define DRONE_H
#include <string>

class drone {
public:
  void move();
  void scan();
  void return_home();
  void drone_status();

 private:
   std::string name;
   int id;
   int battery;
   int position;
};



#endif //DRONE_H
