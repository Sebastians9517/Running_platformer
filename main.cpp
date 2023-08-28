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
    double velocity = 0; // This is given in pixels/frame
    const int jump_velocity = -22;
    bool in_the_air{}; // Braced initialization defaults to a false value
    // Initializing window
    InitWindow(window_width, window_height, "Dasher Game");

    // Gravity acceleration due to gravity, given in pixels/frame^2
    const double gravity = 0.981;

    SetTargetFPS(60);
    while (!WindowShouldClose()){
        // Initializing canvas
        BeginDrawing();
        ClearBackground(WHITE);
        // Ensuring we are not already at ground level
        if((position_Y >= window_height - rectangle_height)){
            velocity = 0;
            in_the_air = false;
        } else { 
            //if we are above ground level, gravity will take us back to the ground
            velocity += gravity;
            in_the_air = true;
        }
        
        if (IsKeyPressed(KEY_SPACE) && !in_the_air) {
            // Applying gravity
            velocity += jump_velocity;
        } 

        // Updating position
        position_Y += velocity;
        
        DrawRectangle(window_width/2, position_Y, rectangle_width, rectangle_height, BLUE);
        EndDrawing();
    }
    CloseWindow();
    
    
}