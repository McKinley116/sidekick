//
// Created by Brandon McKinley on 5/9/25.
//

#ifndef USER_MENU_H
#define USER_MENU_H



class user_menu {
public:
    // Constructor that takes a reference to the map
    user_menu(map& gameMap) : gameMap(gameMap) {}

    // Main menu loop
    void run_menu();

private:
    map& gameMap;  // Reference to the game map

    // Menu helper functions
    void display_menu() const;
    void handle_add_drone();
    void handle_move_drone();
    void handle_remove_drone();
    void handle_show_drone_info();
    void clear_input_buffer() const;
};

};



#endif //USER_MENU_H
