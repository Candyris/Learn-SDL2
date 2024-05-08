// Make a Box move using Keyboard input

#include <SDL2/SDL.h> // also if <SDL.h> so change into it.

#define SPEED 10.5f

int main(int argc, char** argv) {

	// init
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return -1; // Failed to initialize SDL2
	}
	SDL_Window* window = SDL_CreateWindow("INPUT KEYBOARD",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event* event = new SDL_Event;

	// BOX
	SDL_FRect BOX = {300.0f,220.0f,50.0f,50.0f};

	// is Running 
	bool running = true;

	// Game Loop
	while (running)
	{
		SDL_SetRenderDrawColor(renderer,255,45,56,255);
		SDL_RenderClear(renderer);

		while (SDL_PollEvent(event))
		{
			if (SDL_QUIT == event->type)
				running = false;
			// When you pressed down a button on keyboard
			if (event->type == SDL_KEYDOWN)
			{
				// SDL_GetKeyName funciton return the string accornding to Code
				SDL_Log("[SDL_KEYDOWN] Key Code : %d , Key %s \n", event->key.keysym.sym, SDL_GetKeyName(event->key.keysym.sym));
				switch (event->key.keysym.sym) // for get match keyboard input
				{
				case SDLK_d:
					BOX.x += SPEED;
					break;
				case SDLK_a:
					BOX.x -= SPEED;
					break;
				case SDLK_w:
					BOX.y -= SPEED;
					break;
				case SDLK_s:
					BOX.y += SPEED;
					break;
				}
			}
			// When you pressed release a button on keyboard
			else if (event->type == SDL_KEYUP)
			{
				SDL_Log("[SDL_KEYUP] Key Code : %d , Key %s \n", event->key.keysym.sym, SDL_GetKeyName(event->key.keysym.sym));
				switch (event->key.keysym.sym)
				{
				case SDLK_d:
					break;
				case SDLK_a:
					break;
				}
			}
		}

		SDL_SetRenderDrawColor(renderer, 255,255,255, 255);
		// rendering Objects 
		SDL_RenderFillRectF(renderer,&BOX); // set Color for BOX
		SDL_RenderPresent(renderer); // Displaying rendered Objects 
	}
	// free event and destroy windwo and renderer
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	delete event;
	SDL_Quit();
	return 0;
}
