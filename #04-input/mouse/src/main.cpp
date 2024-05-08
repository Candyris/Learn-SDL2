// Make a Box move using Keyboard input

#include <SDL2/SDL.h> // also if <SDL.h> so change into it.

#define BOXPOSITIONX 40
#define BOXPOSITIONY 40
#define BOXORGINOFFSET 25
int main(int argc, char** argv) {

	// init
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return -1; // Failed to initialize SDL2
	}
	SDL_Window* window = SDL_CreateWindow("INPUT KEYBOARD",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event* event = new SDL_Event;

	// BOX
	SDL_Rect BOX = {40,40,50,50};

	//reset BOX position and set mouse position to box  
	bool isResetBox = false ;
	bool SetMouseToBox = false;

	// is Running 
	bool running = true;

	// Game Loop
	while (running)
	{
		SDL_SetRenderDrawColor(renderer,255,45,56,255); // set background
		SDL_RenderClear(renderer); // clear the screen

		while (SDL_PollEvent(event))
		{
			if (SDL_QUIT == event->type)
				running = false;
			// When you pressed down a button on Mouse 
			if (event->type == SDL_MOUSEBUTTONDOWN)
			{
				// SDL_GetKeyName funciton return the string accornding to Code
				switch (event->button.button) // for get match mouse input
				{
				case SDL_BUTTON_LEFT:
					SetMouseToBox = true;
					break;
				case SDL_BUTTON_RIGHT:
					isResetBox = true;

					break;

				}
			}
			// When you pressed release a button on Mouse 
			else if (event->type == SDL_MOUSEBUTTONUP)
			{
				switch (event->button.button) // get button match mouse input
				{
				case SDL_BUTTON_LEFT:
					SetMouseToBox = false;
					break;
				case SDL_BUTTON_RIGHT:
					SDL_Log("Reset Box Position !! \n");
					break;
				}
			}
		}
		// resetting the box back to default
		if (isResetBox)
		{
			isResetBox = false;
			BOX.x = BOXPOSITIONX;
			BOX.y = BOXPOSITIONY;
		}
		if (SetMouseToBox) 
		{
			SDL_GetMouseState(&BOX.x, &BOX.y);
			BOX.x -= BOXORGINOFFSET; // make it so box select at middle 
			BOX.y -= BOXORGINOFFSET;
			
		}

		SDL_SetRenderDrawColor(renderer, 255,255,255, 255);
		// rendering Objects 
		SDL_RenderFillRect(renderer,&BOX); // set Color for BOX
		SDL_RenderPresent(renderer); // Displaying rendered Objects 
	}
	// free event and destroy windwo and renderer
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	delete event;
	SDL_Quit();
	return 0;
}
