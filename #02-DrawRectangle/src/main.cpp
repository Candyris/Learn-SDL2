#include <SDL2/SDL.h> // also if <SDL.h> so change into it.


int main(int argc, char** args)
{
	// initalize SDL2
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return -1; // Failed to initialize SDL2 so, the program 
	}

	// initilizing window, renderer and event  
	SDL_Window* window = SDL_CreateWindow("SDL2 Rectangle", 
                                         SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                         500, 500,
                                         SDL_WINDOW_SHOWN);
  
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;

	//set the exit for window
	bool running = true;

	//Create Rectangle
	SDL_Rect rectangle;
	//Set rectangle values
	rectangle.x = 35;
	rectangle.y = 35;
	rectangle.w = 35;
	rectangle.h = 35;

	// Our application loop 
	while (running)
	{
		while (SDL_PollEvent(&event)) {
		// handling quit operation
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		} 

		// In SDL2 the color is r-b-g-a(RGBA) which is 
		// red   = 0 to 255
		// blue  = 0 to 255
		// green = 0 to 255
		// alpha = 0 to 255 or transparent
		// but you can also use hexdecimal i am not covering this 
		
		 
		// set the color of the window background (green)
		SDL_SetRenderDrawColor(renderer, 0, 0,255, 255);
		// clear the window with the background
		SDL_RenderClear(renderer);
		
		// set the color for the filledrectangle (grey)
		SDL_SetRenderDrawColor(renderer,125,125,125,255);
		// filled the rectangle with upper color
		SDL_RenderFillRect(renderer, &rectangle);
		
		// set the color for the outline of shape (white)
		SDL_SetRenderDrawColor(renderer,255,255,255,255); 
		// drawing the rectangle outline  
		SDL_RenderDrawRect(renderer, &rectangle);


		// Present the renderer to display the content.
		SDL_RenderPresent(renderer);
	}
	// uninitalize the SDL2 and destoring window and renderer
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;

}
