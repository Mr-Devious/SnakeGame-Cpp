#pragma once



#include "raylib.h"
namespace SnakeGui
{
  class obj
  {
    Color m_color{};
    Vector2 m_position{};
    int m_size{};
public:
  obj(Vector2 position, Color color, int size) : m_color(color), m_position(position), m_size(size) {}
  ~obj() = default;

    void draw(){};
  };


  class ObjText : obj
  {
  Vector2 m_position{};
  Color m_color{};
  const char text{};
  int m_size{};
public:
  ObjText(Vector2 position, Color color, int size, const char t) : obj(position, color, size), m_color(color), m_size(size), text(t)
  {}

  void draw() { DrawText(&text, m_position.x, m_position.y, m_size, m_color);}

  };

}

