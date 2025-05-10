#ifndef DRONE_H
#define DRONE_H

#include <string>

class drone {
public:
    drone(const std::string& name, int id) 
        : name(name), id(id), battery(100), position_x(0), position_y(0) {}
    
    virtual ~drone() = default;  // Virtual destructor
    //virtual void scan_target(int x, int y) = 0;  // Pure virtual function
    virtual const char* get_drone_type() const = 0;  // Pure virtual function for type identification

    void set_name(const std::string& new_name);
    void set_id(int new_id);
    void set_position(int x, int y);
    std::string get_name() const { return name; }
    int get_id() const { return id; }
    int get_battery() const { return battery; }
    int get_position_x() const { return position_x; }
    int get_position_y() const { return position_y; }
    void move(int x, int y);
    std::pair<int, int> get_position() const;

protected:
    std::string name;
    int id;
    int battery;
    int position_x;
    int position_y;
};

#endif // DRONE_H