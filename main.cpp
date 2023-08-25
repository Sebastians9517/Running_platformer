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
    int velocity = 0; // This equals to 10px/frame
    // Initializing window
    InitWindow(window_width, window_height, "Dasher Game");

    // Gravity acceleration due to gravity, given in pixels/frame^2
    const int gravity = 1;

    SetTargetFPS(60);
    while (!WindowShouldClose()){
        // Initializing canvas
        BeginDrawing();
        ClearBackground(WHITE);
        // Ensuring we are not already at ground level
        if(position_Y >= window_height - rectangle_height){
            velocity = 0;
        } else {
            velocity += gravity;
        }
        
        if (IsKeyPressed(KEY_SPACE)) {
            // Applying gravity
            velocity -= 9.81;
        } 

        // Updating position
        position_Y += velocity;
        
        DrawRectangle(window_width/2, position_Y, rectangle_width, rectangle_height, BLUE);
        EndDrawing();
    }
    CloseWindow();
    
    
}