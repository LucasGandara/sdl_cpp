#include "SDL.h"
#include "SDLUtils.h"

int main(int argc, char const *argv[])
{
	SDL_Window *gWindow = NULL;
	SDL_Surface *gScreenSurface = NULL;
	SDL_Surface *gHelloWorld = NULL;

	if (!sdlutils::init(gWindow, gScreenSurface))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		// Load media
		if (!sdlutils::loadMedia(gHelloWorld))
		{
			printf("Failed to load media!\n");
		}
		else
		{
			// Apply the image
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

			// Update the surface
			SDL_UpdateWindowSurface(gWindow);

			SDL_Event e;
			bool quit = false;
			while (quit == false)
			{
				while (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT)
						quit = true;
				}
			}
		}
	}

	// Close SDL
	sdlutils::close(gHelloWorld, gWindow);
	return 0;
}
