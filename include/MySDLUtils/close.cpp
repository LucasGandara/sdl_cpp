#include "close.h"
#include "SDL.h"

namespace sdlutils
{
    namespace detail
    {
        void close(SDL_Surface *gHelloWorld, SDL_Window *gWindow)
        {
            // Deallocate surface
            SDL_FreeSurface(gHelloWorld);

            // Destroy window
            SDL_DestroyWindow(gWindow);
            gWindow = NULL;

            // Quit subsystems
            SDL_Quit();
        }
    }
}