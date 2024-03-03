#pragma once
#include "SDL.h"

namespace sdlutils
{
    namespace detail
    {
        bool init(SDL_Window *gWindow, SDL_Surface *gScreenSurface);
    }
}