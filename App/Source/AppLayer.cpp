#include "raylib.h"
#include "AppLayer.h"

#include "snake.h"


namespace App
{
  Snake::Player player = Snake::Player();
  Snake::Apple apple = {};

  void AppLayer::onCreate(){return;};

  void AppLayer::onRun()
  {
    while(!WindowShouldClose())
    {
      ClearBackground(DARKGREEN);
      BeginDrawing();

      player.drawBody();
      Snake::printScore();
      Snake::onCollide(player, apple);
      
      player.move();
      apple.draw();

      
      

      EndDrawing();
    }
    

  };
}
