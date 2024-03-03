#include "loadMedia.h"
#include "SDL.h"

namespace sdlutils
{
    namespace detail
    {
        bool loadMedia(SDL_Surface *gHelloWorld)
        {
            // Loading success flag
            bool success = true;

            // Load splash image
            gHelloWorld = SDL_LoadBMP("hello_world.bmp");
            if (gHelloWorld == NULL)
            {
                printf("Unable to load image %s ! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
                success = false;
            }
            return success;
        }
    }
}