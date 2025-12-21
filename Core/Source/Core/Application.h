#pragma once
#include <string>
#include <vector>

#include "Layer.h"

namespace Core
{
  struct ApplicationSpecification
  {
    const char* name;
    int height;
    int width;
  };

  class Application
  {
private:
  //specifying
  std::string m_name{};
  int m_height{};
  int m_width{};
  int m_fps{};
  //
  
  std::vector<Layer*> m_appLayer{};  // make better system later maybe  
public:
  Application(std::string name, int height, int width, int fps) : m_name(name), m_height(height), m_width(width), m_fps(fps) {}
  ~Application()
  {
    for (Layer* n : m_appLayer){ delete n;}
  };
  
  
  void pushBack(Layer& applayer);
  
  
  void run();

  };
}
