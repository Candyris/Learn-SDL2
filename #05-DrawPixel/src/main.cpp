#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char** argv) {

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return -1; // Failed to initialize SDL2
    }

    SDL_Window* window = SDL_CreateWindow("SDL2 Pixel Draw", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Event event;

    // Create an array of pixels to draw on
    Uint32* pixels = new Uint32[640 * 480];

    // Create a texture to store the pixels
    SDL_Texture* rawTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, 640, 480);

    // Initialize running and leftMouseButtonDown to true
    bool running = true;
    bool leftMouseButtonDown = false;

    // Set all pixels to white
    memset(pixels, 255, 640 * 480 * sizeof(Uint32));

    // Game Loop
    while (running)
    {
        // Set the render color to red and clear the renderer
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Handle events
        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
                running = false;

            switch (event.type)
            {
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT)
                    leftMouseButtonDown = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                    leftMouseButtonDown = true;
                break;
            case SDL_MOUSEMOTION:
                if (leftMouseButtonDown)
                {
                    int mouseX = event.motion.x;
                    int mouseY = event.motion.y;
                    pixels[mouseY * 640 + mouseX] = 0; // Set the pixel at the mouse position to black
                }
                break;
            }
        }

        // Update the texture with the new pixel data
        SDL_UpdateTexture(rawTexture, NULL, pixels, 640 * sizeof(Uint32));

        // Copy the texture to the renderer
        SDL_RenderCopy(renderer, rawTexture, NULL, NULL);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Free the pixel array and destroy the texture, renderer, and window
    delete[] pixels;
    SDL_DestroyTexture(rawTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Quit SDL
    SDL_Quit();

    return 0;
}
