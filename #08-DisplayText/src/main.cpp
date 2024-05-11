#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
int main(int argc, char *argv[])
{
    // Initialize SDL
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Text on Screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *ren = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;

    // open a font which You want to add path of file
    TTF_Font *font = TTF_OpenFont("Atop.ttf", 20);

    // set the color of the font
    SDL_Color fontColor = {255, .255, 255, 255};
    // text created on the surface

    SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Hello", fontColor);
    // surface loaded on the GPU for using the Text to Display.

    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(ren, textSurface);
    ;
    // Initialize running to true
    SDL_Rect sizefont = {0, 0, textSurface->w, textSurface->h};

    bool running = true;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            }
        }
        SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
        SDL_RenderClear(ren);
        // copy the texture to the renderer to display
        SDL_RenderCopy(ren, textTexture, NULL, &sizefont);
        SDL_RenderPresent(ren);
    }
    // Then close the Font
    TTF_CloseFont(font);
    // freeing the surface of text
    SDL_FreeSurface(textSurface);
    // Exiting tff feature
    TTF_Quit();
    // Exiting SDL feature
    SDL_Quit();
    return 0;
}
