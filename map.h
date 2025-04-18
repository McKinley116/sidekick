//
// Created by Brandon McKinley on 4/18/25.
//

#ifndef MAP_H
#define MAP_H



class Map {
public:
  void build();
  void reset();
  void print();
  void populate();

private:
  char map[10][10];
};



#endif //MAP_H
