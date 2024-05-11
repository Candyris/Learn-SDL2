#include <SDL2/SDL.h> // some people like to do it with <SDL.h> change it
#include <List>

struct Line
{
    int x1, y1, x2, y2;
};

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
    std::list<Line> Lines = {};

    // Check if Line should be drawing
    bool isDrawing = false;

    Line currentLine = {0, 0, 0, 0};

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
                    currentLine.x1 = event.motion.x;
                    currentLine.y1 = event.motion.y;
                    currentLine.x2 = event.motion.x;
                    currentLine.y2 = event.motion.y;
                    // set Line Should be Drawn
                    isDrawing = true;
                    break;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT)
                    // After releasing Left Mouse Button Stop Drawing Line
                    Lines.push_back(currentLine);
                isDrawing = false;
                break;
            case SDL_MOUSEMOTION:
                // When mouse is moving Update Position
                if (isDrawing)
                {
                    // Changing endpoint of Line with MousePosition
                    currentLine.x2 = event.motion.x;
                    currentLine.y2 = event.motion.y;
                }
                break;
            }
        }
        SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
        SDL_RenderClear(ren);
        // drawing object

        // setting Color for all Lines
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);

        for (std::list<Line>::iterator it = Lines.begin(); it != Lines.end(); it++) // you also can use for each loop
        {
            SDL_RenderDrawLine(ren, it->x1, it->y1, it->x2, it->y2);
        }

        // Drawing Line on Screen
        SDL_RenderDrawLine(ren, currentLine.x1, currentLine.y1, currentLine.x2, currentLine.y2);

        // end of drawing

        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}