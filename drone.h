//
// Created by Brandon McKinley on 4/18/25.
//

#ifndef DRONE_H
#define DRONE_H
#include <string>

class Drone {
public:

    //Drone Constructor to set intial variabls for each drone that is created
    Drone(const std::string &name, int id){
        this->name = name;
        this->id = id;
        this->battery = 100;
        this->position_x = 0;
        this ->position_y = 0;
        this->speed = 0;

    }

    explicit Drone(const std::string & string); // created constructor for new_drone in main.cpp

    void move(int x, int y);
    void scan(int x, int y);
    void return_home();
    void status() const;
    void battery_status() const;
    void charge();
    std::string get_name() const;
    void get_position() const;
    void set_position(int x, int y);
    int get_position_x() const;
    int get_position_y() const;

private:
   std::string name;
    int id;
    int battery;
    int position_x;
    int position_y;
    int speed;

};



#endif //DRONE_H
