//
// Created by Brandon McKinley on 5/4/25.
//

#ifndef DRONE_H
#define DRONE_H
#include <string>

class drone
{
    public:
        drone(const std::string &name, int id){
            this->name = name;
            this->id = id;
            this->battery = 100;
            this->position_x = 0;
            this ->position_y = 0;
        }

        void move(int x, int y);
        void set_name();
        void set_id();
        void set_battery();
        void set_position(int x, int y);
        void get_name();
        void get_id();
        void get_battery();
        void get_position();

    private:
        std::string name;
        int id;
        int battery;
        int position_x;
        int position_y;
        int speed;
};

#endif //DRONE_H
