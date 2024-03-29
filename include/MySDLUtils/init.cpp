#include "init.h"
#include "SDL.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

namespace sdlutils
{
    namespace detail
    {
        bool init(SDL_Window *gWindow, SDL_Surface *gScreenSurface)
        {
            bool success = true;

            // Initialize SDL
            if (SDL_Init(SDL_INIT_VIDEO) < 0)
            {
                printf("SDL could not initialize!  SDL_Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                // Create window
            }

            gWindow = SDL_CreateWindow(
                "SDL Tutorial",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH,
                SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN);

            if (gWindow == NULL)
            {
                printf("Window could not be created!  SDL_Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                // Get Window surface
                gScreenSurface = SDL_GetWindowSurface(gWindow);
            }

            return success;
        }
    }
}