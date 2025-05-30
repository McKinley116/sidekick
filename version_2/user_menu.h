#ifndef USER_MENU_H
#define USER_MENU_H

#include "map.h"

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
    void handle_drone_commands() const; //allows the user to issues specific commands based on the drone type created
    void handle_sorted_drones();
};

#endif //USER_MENU_H