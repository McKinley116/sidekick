#include "drone.h"
#include <string>

void drone::set_name(const std::string& new_name) {
    name = new_name;
}

void drone::set_id(int new_id) {
    id = new_id;
}

void drone::set_position(int x, int y) {
    position_x = x;
    position_y = y;
}

std::string drone::get_name() {
    return name;
}

int drone::get_id() {
    return id;
}

int drone::get_battery() {
    return battery;
}

void drone::get_position() {
    // Implementation needed
    // You might want to modify this to return or output the position
}

void drone::move(int x, int y) {
    // Implementation needed
    position_x = x;
    position_y = y;
}