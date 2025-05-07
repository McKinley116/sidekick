//
// Created by Brandon McKinley on 5/4/25.
//

#include "drone.h"
#include "../drone.h"

#include <string>

void drone::set_name(std::string name)
{
    this->name = name;
}

void drone::set_id(int id)
{
    this->id = id;
}

void drone::set_position(int x, int y)
{
    this->position_x = x;
    this->position_y = y;
}

std::string drone::get_name()
{
    return name;
}

int drone::get_id()
{
    return id;
}

int drone::get_battery()
{
    return battery;
}

//void drone::get_position(){}
