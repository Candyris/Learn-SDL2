#include <SDL2/SDL.h>
#include <iostream>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int main(int argc, char* argv[])
{

	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) 
	{
		// if succeeded create Window
		window = SDL_CreateWindow("SDL_window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

		// if the window creation succeeded create the renderer
		if (!window) 
		{
			std::cout << "success!!";
			renderer = SDL_CreateRenderer(window, -1, 0);
		}
		else {
			std::cout << "failed!!";

			return -1; // SDL could not initialize
		}
	}	// if the window and renderer succeeded start drawing

		// Set render with custom using Create Color using render
		
	SDL_SetRenderDrawColor(renderer , 12,34,34,255);

	// Clear the Window using the color which we decided up
	SDL_RenderClear(renderer);

	//show the window // print what we create in renderer until here
	SDL_RenderPresent(renderer);
	
	// set a delay time before quit the window 
	SDL_Delay(5000);

	// clean up SDL
	SDL_Quit();


	return 0;
}
