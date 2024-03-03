#pragma once
#include "SDL.h"

namespace sdlutils
{
    bool init(SDL_Window *gWindow, SDL_Surface *gScreenSurface);
    bool loadMedia(SDL_Surface *gHelloWorld);
    void close(SDL_Surface *gHelloWorld, SDL_Window *gWindow);
}