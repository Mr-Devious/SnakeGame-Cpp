#pragma once
#include "raylib.h"
namespace Snake
{
  
  void printScore();
  
  struct Map
  {
  float size_x{500.0f};
  float size_y{500.0f};
  float blocksize = {size_x / 25.0f};
  };
  
  class Apple
  {
private:
    Vector2 m_pos {500, 500};
public:
    void newLocation() {m_pos.x = GetRandomValue(0, GetScreenWidth()); m_pos.y = GetRandomValue(0, GetScreenHeight());};
    void draw(){ DrawCircle(m_pos.x, m_pos.y, 10, RED);}
    Vector2 getPos(){return m_pos;}
  };
    
  class Player
  {
    Vector2 headPosition {250.0f, 250.0f};
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
    Vector2 getPos();
    void init();

    void move();

    void checkCollisions();
  };


  void onCollide(Player& p, Apple& a);
}
