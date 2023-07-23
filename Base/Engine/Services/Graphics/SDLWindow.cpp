#include "SDLWindow.h"

void SDLWindow::initialize(const char* name, int xpos, int ypos, int width, int height, bool fullscreen) {
	GRAPHICS_DEBUG("WINDOW | Initialize Started")
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		GRAPHICS_DEBUG("WINDOW | SDL Video Initialized")

		window = SDL_CreateWindow(name, xpos, ypos, width, height, flags);
		if (window) {
			GRAPHICS_DEBUG("WINDOW | Window Initialized")
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 10, 255, 10, 255);
			GRAPHICS_DEBUG("WINDOW | Renderer Initialized")
		}
	}
	GRAPHICS_DEBUG("WINDOW | Initialize Complete")
}

void SDLWindow::update() {
	GRAPHICS_DEBUG("WINDOW | Update Started")
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	GRAPHICS_DEBUG("WINDOW | Update Complete")
}

void SDLWindow::cleanup() {
	GRAPHICS_DEBUG("WINDOW | Cleanup Started")
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	GRAPHICS_DEBUG("WINDOW | Cleanup Complete")
}