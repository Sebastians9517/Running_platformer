#include <raylib.h>

int main (){
    // Window dimensions
    const int window_width = 1280;
    const int window_height = 720;
    // Rectangle dimensions
    const int rectangle_width = 50;
    const int rectangle_height = 80;
    // Position and velocity
    int position_Y = 0;
    int velocity = 10; // This equals to 10px/frame
    // Initializing window
    InitWindow(window_width, window_height, "Dasher Game");

    SetTargetFPS(60);
    while (!WindowShouldClose()){
        // Initializing canvas
        BeginDrawing();
        ClearBackground(WHITE);

        position_Y += velocity;
        EndDrawing();
    }
    CloseWindow();
    
    
}