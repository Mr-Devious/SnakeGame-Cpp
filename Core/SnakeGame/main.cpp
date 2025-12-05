#include <iostream>
#include "raylib.h"


int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib start example");
       
  std::cout << "HELLO\n"; 
  //--------------------------------------------------------------------------------------

    while (!WindowShouldClose())  
    {
 



    BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first raylib window!", 100, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and unload OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
