#include <raylib.h>

int main (){
    // Window dimensions
    const int window_width = 1280;
    const int window_height = 720;

    // Downward acceleration due to gravity, given in pixels/second^2
    const double gravity = 981;

    // Position and velocity
    double velocity = 0; // This is given in pixels/second
    const int jump_velocity = -600;
    bool in_the_air{}; // Braced initialization defaults to a false value

    // Initializing window
    InitWindow(window_width, window_height, "Dasher Game");
    // Importing and setting up character sprite hitbox dimensions and position in map
    // We import textures after InitWindow, which creates a conection with the GPU so memory can be accessed
    Texture2D character = LoadTexture("textures/scarfy.png");
    // Setting up the hitbox rectangle size
    Rectangle character_hitbox;
    character_hitbox.width = character.width/6;
    character_hitbox.height = character.height;
    character_hitbox.x = 0;
    character_hitbox.y = 0;
    // Setting up sprite position in regards to the map
    Vector2 character_position;
    character_position.x = window_width/2 - character_hitbox.width/2;
    character_position.y = window_height - character_hitbox.height;

    SetTargetFPS(60);
    while (!WindowShouldClose()){
        // Initializing canvas
        BeginDrawing();
        ClearBackground(WHITE);
        // Delta time (time since last frame), to keep character moving at a set velocity regardless of fps rate
        const float delta_time = (GetFrameTime());
        // Ensuring we are not already at ground level
        if((character_position.y >= window_height - character_hitbox.height)){
            velocity = 0;
            in_the_air = false;
        } else { 
            //if we are above ground level, gravity will take us back to the ground
            velocity += (gravity*delta_time);
            in_the_air = true;
        }
        
        if (IsKeyPressed(KEY_SPACE) && !in_the_air) {
            // Applying gravity
            velocity += jump_velocity;
        } 

        // Updating position
        character_position.y += (velocity*delta_time);
        
        DrawTextureRec(character, character_hitbox, character_position, WHITE);
        EndDrawing();
    }
    UnloadTexture(character);
    CloseWindow();
    
    
}