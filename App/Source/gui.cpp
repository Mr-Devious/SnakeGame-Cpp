#include "gui.h"
#include "raylib.h"
#include <deque>


using namespace SnakeGui;

std::deque<obj*> objects {};

obj txt_Score{Vector2{100, 500}, GREEN, 50};


void drawObjects(std::deque<obj*> objs)
{
  for(auto i : objs){ i->draw();}
}


