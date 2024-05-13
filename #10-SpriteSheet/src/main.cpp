#include <SDL2/SDL.h>
#include "SpriteSheet/SpriteSheet.h"

int main(int argc, char ** argv) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Sprite Sheet Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Load a sprite sheet
    SpriteSheet spriteSheet(renderer, "player.png", Vector2i(20, 20), Vector2i(120, 120), 1, 4); // 2 rows, 2 columns
    spriteSheet.setDrawSize(Vector2i(300, 300));
    // Main loop
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        // Update sprite sheet
        spriteSheet.update(300); // Assuming 60 FPS, so the delta time is approximately 16 milliseconds

        // Clear the screen
        SDL_RenderClear(renderer);

        // Render the sprite sheet
        spriteSheet.render();

        // Present the renderer
        SDL_RenderPresent(renderer);

        // Delay to achieve approximately 60 FPS
        SDL_Delay(300);
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
