#include <SDL2/SDL.h>
#include <iostream>

bool isRunning = false; 

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

bool init(const char* title, int Xpos, int Ypos, int width, int height, int flags)
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create Window
		window = SDL_CreateWindow(title,Xpos,Ypos, width , height , flags);

		// if the window creation succeeded create the renderer
		if (window)
		{
			renderer = SDL_CreateRenderer(window, -1, 0);
		}
		else 
		{
			return false; // SDL could not initialize
		}
	}return true;
}

void render() 
{
	// Set render with custom using Create Color using render	
	SDL_SetRenderDrawColor(renderer, 12, 34, 34, 255); // color coordinate lies between 0 - 255 and last arg is opicity

	// Clear the Window using the color which we decided up
	SDL_RenderClear(renderer);

	//show the window // print what we create in renderer until here
	SDL_RenderPresent(renderer);

	// set a delay time before quit the window 
	SDL_Delay(5000);
}

int main(int argc, char* argv[])
{

	if (init("Setting up SDL",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480, SDL_WINDOW_SHOWN))
	{
		isRunning = true;
	}
	else
	{
		return 1; // something's wrong
	}
	// if the window and renderer succeeded start drawing

	while (isRunning) {
		render();
	}

	// clean up SDL
	SDL_Quit();


	return 0;
}