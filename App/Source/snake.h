#include "raylib.h"
  
#pragma once

namespace Snake
{
  
  void printScore();
  
  struct Map
  {
  float size_x{500.0f};
  float size_y{500.0f};
  float blocksize = {size_x / 25.0f};
  };
    
  class Player
  {
    Vector2 headPosition {250.0f, 250.0f};
    Map m_map;
    enum Direction{
      up,
      down,
      left,
      right,
    };
  Direction m_direction = right;
  
public:
    Player();
    //Player(Vector2 pos);
    
    void drawBody();

    //void create();

    void init();

    void move();
  };


}
