#include <raylib.h>
#include <stdio.h>

#define RAYLIB_LOADERS_IMPLEMENTATION
#include "../raylib_loaders.h"
#include "../assman.h"

int 
main(void)
{
    printf("Starting main...\n");
    
    InitWindow(800, 600, "Asset Manager Example");
    
    printf("Window initialized...\n");
    // Create asset manager
    AssMan *assman = AssMan_new();
    
    printf("Asset Manager created...\n");
    
    // Register file types
    AssMan_registerFiletype(assman, ".png", raylib_textureLoader, raylib_textureReleaser);
    AssMan_registerFiletype(assman, ".jpg", raylib_textureLoader, raylib_textureReleaser);
    AssMan_registerFiletype(assman, ".obj", raylib_modelLoader,   raylib_modelReleaser);
    AssMan_registerFiletype(assman, ".wav", raylib_soundLoader,   raylib_soundReleaser);
    AssMan_registerFiletype(assman, ".mp3", raylib_musicLoader,   raylib_musicReleaser);
    AssMan_registerFiletype(assman, ".ttf", raylib_fontLoader,    raylib_fontReleaser);
    
    printf("Registered filetypes...\n");
    
    // Load assets
    Texture2D *player_tex = AssMan_load(assman, "res/player.png", "player", NULL, NULL);
    Model *ship_model     = AssMan_load(assman, "res/ship.obj", "ship", NULL, NULL);

    printf("Loaded assets...\n");
    
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            // Use your assets
            DrawTexture(*player_tex, 100, 100, WHITE);
        
        EndDrawing();
    }

    printf("Exiting program...\n");
    
    // Release assets
    AssMan_release(assman, "player");
    AssMan_release(assman, "ship");

    printf("Assets released...\n");
    
    // Cleanup
    AssMan_free(assman);

    printf("Asset Manager freed...\n");
    
    CloseWindow();
    
    return 0;
}
