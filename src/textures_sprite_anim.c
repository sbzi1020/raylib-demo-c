#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    //--------------------------------------------------------------------------------------
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "raylib [texture] example - sprite anim");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    Texture2D scarfy = LoadTexture("resources/scarfy.png");        // Texture loading

    Rectangle player_rect = { 0.0f, 0.0f, (float)scarfy.width/6, (float)scarfy.height };

    Vector2 player_pos = { (float)screenWidth/2, (float)screenHeight/2 };
    Vector2 tips_text_pos = { 20, 20 };

    // Use for calculating animation frame from loaded texture
    int currentFrame = 0;
    int framesCounter = 0;
    int framesSpeed = 8;            // Number of spritesheet frames shown by second

    // Set our game to run at 60 frames-per-second
    SetTargetFPS(60);               

    //----------------------------------------------------------------------------------
    // Main game loop
    //----------------------------------------------------------------------------------
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //----------------------------------------------------------------------------------
        // Calculate the correct play frame rect from load texture
        //----------------------------------------------------------------------------------
        framesCounter++;

        if (framesCounter >= (60/framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 5) currentFrame = 0;

            player_rect.x = (float)currentFrame*(float)scarfy.width/6;
        }

        //----------------------------------------------------------------------------------
        // Update player position
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT)) player_pos.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) player_pos.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) player_pos.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) player_pos.y += 2.0f;


        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

	    //
	    // Draw tips text
	    //
            DrawText("See that Mikey is moving by my control :)", tips_text_pos.x, tips_text_pos.y, 30, DARKGRAY);

	    //
	    // Draw moving player
	    //
            DrawTextureRec(scarfy, player_rect, player_pos, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(scarfy);       // Texture unloading

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
