#include <raylib.h>

int main (){
    // Window dimensions
    const int window_width = 1280;
    const int window_height = 720;
    // Rectangle dimensions
    const int rectangle_width = 50;
    const int rectangle_height = 80;
    // Position and velocity
    int position_Y = (window_height - rectangle_height);
    int velocity = -10; // This equals to 10px/frame
    // Initializing window
    InitWindow(window_width, window_height, "Dasher Game");

    SetTargetFPS(60);
    while (!WindowShouldClose()){
        // Initializing canvas
        BeginDrawing();
        ClearBackground(WHITE);
        if (IsKeyPressed(KEY_SPACE)) {
            position_Y += velocity;
        }
        DrawRectangle(window_width/2, position_Y, rectangle_width, rectangle_height, BLUE);
        EndDrawing();
    }
    CloseWindow();
    
    
}