#include "snake.h"

#include "raylib.h"
#include <deque>
#include <string>

namespace Snake
{
  std::deque<Vector2> body {};
  unsigned int points{67};

  
  void printScore()
  {
    std::string text = std::to_string(points);
    const char* t = text.c_str();
    DrawText(t, 500, 500, 300, GREEN);
  }

  

  //Player create()
  Player::Player(){};
  void Player::init()
  {
  }
  
  void Player::drawBody()
  {
    body.emplace_front(Vector2{this->headPosition.x, this->headPosition.y}); 
    for(unsigned int i = 0; i <= points && ( i < body.size() ); i++) { DrawCircle(body.at(i).x, body.at(i).y, m_map.blocksize, GREEN);}
    DrawCircle(headPosition.x, headPosition.y, m_map.blocksize, GREEN);
  }

  void Player::move()
  {
    if(IsKeyPressed(KEY_A) && (m_direction == up or m_direction == down)) {m_direction = left;}
    if(IsKeyPressed(KEY_W) && (m_direction == left or m_direction == right)) {m_direction = up;}
    if(IsKeyPressed(KEY_S) && (m_direction == left or m_direction == right)) {m_direction = down;}
    if(IsKeyPressed(KEY_D) && (m_direction == up or m_direction == down)) {m_direction = right;}
    switch (m_direction) 
    {
    case left:  {headPosition.x -= m_map.blocksize;} break;
    case up:    {headPosition.y -= m_map.blocksize;} break;
    case down:  {headPosition.y += m_map.blocksize;} break;
    case right: {headPosition.x += m_map.blocksize;} break;
    }
  
  }

  
}
