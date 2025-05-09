#ifndef USER_MENU_H
#define USER_MENU_H

#include "map.h"
#include "drone.h"  // Removed extra quote
#include <iostream>

class user_menu {
public:
    user_menu(map& gameMap) : gameMap(gameMap) {}
    void run_menu();

private:
    map& gameMap;

    void display_menu() const;
    void handle_add_drone();
    void handle_move_drone();
    void handle_remove_drone();
    void handle_show_drone_info();
    void clear_input_buffer() const;
};

#endif //USER_MENU_H