#include <SDL2/SDL.h> // also if <SDL.h> so change into it.
#include <SDL2/SDL_image.h> // also if <SDL_image.h> so change into it.

int main(int argc, char** args)
{
	// initalize SDL2
	if (SDL_Init(SDL_INIT_VIDEO) < 0 && 
		IMG_Init(IMG_INIT_PNG | IMG_INIT_WEBP | IMG_INIT_JPG))
	{
		return -1; // Failed to initialize SDL2 so, the program 
	}

	// initilizing window, renderer and event  
	SDL_Window* window = SDL_CreateWindow("SDL2 Rectangle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;

	//set the exit for window
	bool running = true;

	SDL_Surface* image = IMG_Load("Images/CuteDog.jpg"); 
	SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer,image);
	SDL_FreeSurface(image);

	// destination image properties
	SDL_Rect destImg = {};
	destImg.x = 45;
	destImg.y = 45;
	destImg.w = 200;
	destImg.h = 150;

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
		// set the color of the window background (green)
		SDL_SetRenderDrawColor(renderer, 0, 0,255, 255);
		// clear the window with the background
		SDL_RenderClear(renderer);
		
		// Draw Object 
		SDL_RenderCopy(renderer,imageTexture,NULL,&destImg); 
		// set last argument to destImg which store Size and Position to display on window or screen 
	
		// Present the renderer to display the content.
		SDL_RenderPresent(renderer);
	}
	// uninitalize the SDL2 and destoring window and renderer
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
 IMG_Quit();

	return 0;

}
