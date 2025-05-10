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

void drone::move(int x, int y) {
    // Implementation needed
    position_x = x;
    position_y = y;
}

std::pair<int, int> drone::get_position() const {
    return std::make_pair(position_x, position_y);
}