//
// Created by Brandon McKinley on 4/18/25.
//

#ifndef MAP_H
#define MAP_H



class map {
public:
  void build_map();
  void reset_map();
  void print_map();
  void populate_map();

private:
  char map[10][10];
};



#endif //MAP_H
