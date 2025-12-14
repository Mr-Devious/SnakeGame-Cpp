#include "Application.h"
#include "AppLayer.h"

int main()
{
  Core::Application appspecs {"SnakeGame!!!", 1080, 1920, 120};
  App::AppLayer snakeGame;
  
  appspecs.pushBack(snakeGame);

  appspecs.run();
}
