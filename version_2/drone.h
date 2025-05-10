#ifndef DRONE_H
#define DRONE_H
#include <string>

class drone {
public:

    enum missle_type // stores the types of missles that the fighter drone has access to
    {
        STANDARD = 0,
        HEAVY = 1,
        BURST = 2,
    };


    //Constructor
    drone(const std::string &name, int id) {
        this->name = name;
        this->id = id;
        this->battery = 100;
        this->position_x = 0;
        this->position_y = 0;
    }

    void move(int x, int y);
    void set_name(const std::string& name);
    void set_id(int id);
    void set_position(int x, int y);
    std::string get_name();
    int get_id();
    int get_battery();
    void get_position();
    
    int get_position_x() const { return position_x; }
    int get_position_y() const { return position_y; }

private:
    std::string name;
    int id;
    int battery;
    int position_x;
    int position_y;
};

#endif //DRONE_H