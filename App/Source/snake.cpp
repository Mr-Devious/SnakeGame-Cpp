#include "snake.h"

#include "raylib.h"
#include <cstddef>
#include <deque>
#include <string>

namespace Snake
{
  std::deque<Vector2> body (500);
  unsigned int points{};

  
  Map m_map{};
  void printScore()
  {
    std::string text = std::to_string(points);
    const char* t = text.c_str();
    DrawText(t, 500, 500, 300, GREEN);
  }
  
  
  void onCollide(Player& p, Apple& a)
  {
    if(CheckCollisionCircles(p.getPos(), m_map.blocksize / 2, a.getPos(), m_map.blocksize / 2)) {a.newLocation(); points++;}
    for (unsigned int i = 0; i < points; i++) {
      Vector2 bodyIndex = body.at(i);
      
    if (CheckCollisionCircles(Vector2{bodyIndex.x, bodyIndex.y}, ((m_map.blocksize -4 )/ 2), p.getPos(), ((m_map.blocksize -4 ) / 2))){
        points = 0;
    }
    }
  }

  //Player create()
  Player::Player(){};
  void Player::init()
  {
  }
  
  void Player::drawBody()
  {
    for(unsigned int i = 0; i < points && ( i < body.size() ); i++) { DrawCircle(body.at(i).x, body.at(i).y, m_map.blocksize / 2, GREEN);}
    DrawCircle(headPosition.x, headPosition.y, m_map.blocksize / 2, GREEN);
  }

  void Player::move()
  {

    body.emplace_front(Vector2{headPosition.x, headPosition.y}); 
    switch (m_direction) 
    {
    case left:  {headPosition.x -= m_map.blocksize;} break;
    case up:    {headPosition.y -= m_map.blocksize;} break;
    case down:  {headPosition.y += m_map.blocksize;} break;
    case right: {headPosition.x += m_map.blocksize;} break;
    }
  
    if(IsKeyPressed(KEY_A) && (m_direction == up or m_direction == down)) {m_direction = left; return;}
    
    if(IsKeyPressed(KEY_W) && (m_direction == left or m_direction == right)) {m_direction = up; return;}

    if(IsKeyPressed(KEY_S) && (m_direction == left or m_direction == right)) {m_direction = down; return;}

    if(IsKeyPressed(KEY_D) && (m_direction == up or m_direction == down)) {m_direction = right; return;}

  }
  Vector2 Player::getPos()
  {
    return headPosition;
  }

   
}
