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

      Snake::onCollide(player, apple);
      
      
      BeginDrawing();
      Snake::printScore();
      player.drawBody();
      player.move();
      apple.draw();

      
      

      EndDrawing();
    }
    

  };
}
