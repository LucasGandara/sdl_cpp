#include "SDLUtils.h"
#include "init.h"
#include "loadMedia.h"
#include "close.h"
#include "SDL.h"

namespace sdlutils
{
    bool init(SDL_Window *gWindow, SDL_Surface *gScreenSurface)
    {
        return sdlutils::detail::init(gWindow, gScreenSurface);
    }
    bool loadMedia(SDL_Surface *gScreenSurface)
    {
        return sdlutils::detail::loadMedia(gScreenSurface);
    }
    void close(SDL_Surface *gHelloWorld, SDL_Window *gWindow)
    {
        sdlutils::detail::close(gHelloWorld, gWindow);
    }
}