#include <SDL2/SDL.h> // some people like to do it with <SDL.h> change it

int main(int argc, char *argv[])
{
    // Init SDL2
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        return -1;
    }
    SDL_Window *window = SDL_CreateWindow("Draw Lines", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *ren = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;

    bool running = true;

    // Declaring Line Varible
    int startLineX = NULL;
    int startLineY = NULL;
    int endLineX = NULL;
    int endLineY = NULL;

    // Check if Line should be drawing
    bool isDrawing = false;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case (SDL_QUIT):
                running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    // set the mouse position to Line Properties
                    startLineX = event.motion.x;
                    startLineY = event.motion.y;
                    endLineX = event.motion.x;
                    endLineY = event.motion.y;
                    // set Line Should be Drawn
                    isDrawing = true;
                    break;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT)
                    // After releasing Left Mouse Button Stop Drawing Line
                    isDrawing = false;
                break;
            case SDL_MOUSEMOTION:
                // When mouse is moving Update Position
                if (isDrawing)
                {
                    // Changing endpoint of Line with MousePosition
                    endLineX = event.motion.x;
                    endLineY = event.motion.y;
                }
                break;
            }
        }
        SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
        SDL_RenderClear(ren);
        // drawing object

        // setting Line Color
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        // Drawing Line on Screen
        SDL_RenderDrawLine(ren, startLineX, startLineY, endLineX, endLineY);

        // end of drawing

        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}