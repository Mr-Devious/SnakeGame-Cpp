#include "raylib.h"
#include "AppLayer.h"

#include "snake.h"

#include "logic.h"

namespace App
{
  Snake::Player player = Snake::Player();

  void AppLayer::onCreate(){return;};

  void AppLayer::onRun()
  {
    while(!WindowShouldClose())
    {
      ClearBackground(DARKGREEN);
      BeginDrawing();
      player.move();
      player.drawBody();
      Snake::printScore(); 

      EndDrawing();
    }
    

  };
}
