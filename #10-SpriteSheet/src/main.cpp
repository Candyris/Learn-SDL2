#include <SDL2/SDL.h>
#include "Sprite/Sprite.h"
#include <SDL2/SDL_image.h>

int main(int argc, char *argv[])
{
	// initalize SDL2
	if (SDL_Init(SDL_INIT_VIDEO) != 0 &&
		IMG_Init(IMG_INIT_PNG | IMG_INIT_WEBP | IMG_INIT_JPG) != 0)
	{
		return -1; // Failed to initialize SDL2 so, the program
	}

	// initilizing window, renderer and event
	SDL_Window *window = SDL_CreateWindow("SDL2 Rectangle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
	SDL_Renderer *ren = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;

	Sprite player(ren, "Player.png", Vector2i(20, 20), Vector2i(100, 120), Vector2i(200, 200));
	bool running = true;
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		SDL_RenderClear(ren);

		player.render();
		SDL_RenderPresent(ren);
	}

	return 0;
}
