#include <raylib.h>

int main (){
    // Declaring window dimensions
    const int window_width = 1280;
    const int window_height = 720;
    // Initializing window
    InitWindow(window_width, window_height, "Dasher Game");

    SetTargetFPS(60);
    while (!WindowShouldClose()){
        // Initializing canvas
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
    CloseWindow();
    
    
}