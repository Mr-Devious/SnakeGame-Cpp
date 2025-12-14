#include "Application.h"
#include "AppLayer.h"

int main()
{
  Core::Application appspecs {"SnakeSnakeGame!!!", 1080, 1920, 60};
  App::AppLayer snakeGame;
  
  appspecs.pushBack(snakeGame);

  appspecs.run();
}
