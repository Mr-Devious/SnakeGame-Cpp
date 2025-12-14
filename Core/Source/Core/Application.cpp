#include <iostream>
#include "Layer.h"
#include "Application.h"
#include "raylib.h"


namespace Core
{
  void Application::pushBack(Layer& applayer)
  {
    m_appLayer.push_back(&applayer);
    std::cout << m_appLayer.size();
  }
    
  
  void Application::run()
  {
    InitWindow(m_width, m_height, m_name.c_str());
    SetTargetFPS(10);
    m_appLayer.at(0)->onCreate();
    m_appLayer.at(0)->onRun();
  }
}

