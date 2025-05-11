#include "drone.h"
#include <string>
#include <iostream>

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
    int distance = std::abs(x - position_x) + std::abs(y - position_y);
    int battery_cost = distance * 5;  // 5% battery per unit of distance

    if (!has_enough_battery(battery_cost)) {
        std::cout << "Not enough battery power to move this far!" << std::endl;
        return;
    }

    position_x = x;
    position_y = y;
    decrease_battery(battery_cost);
    std::cout << "Moved to (" << x << ", " << y << ")" << std::endl;
    std::cout << "Battery level: " << battery << "%" << std::endl;
}

std::pair<int, int> drone::get_position() const {
    return std::make_pair(position_x, position_y);
}

void drone::decrease_battery(int amount) {
    battery = std::max(0, battery - amount);
}

void drone::charge_battery() {
    battery = 100;
    std::cout << "Battery charged to 100%" << std::endl;
}

bool drone::has_enough_battery(int required) const {
    return battery >= required;
}