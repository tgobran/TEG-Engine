#include <iostream>

#include "Engine.h"

void Engine::initialize(const char* name, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL Initialized" << std::endl;

		window = SDL_CreateWindow(name, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window Initialized" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 10, 255, 10, 255);
			std::cout << "Renderer Initialized" << std::endl;
		}

		isActive = true;
	}
	else {
		isActive = false;
	}
}
 
void Engine::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isActive = false;
		break;
	default:
		break;
	}
}

void Engine::update() {
}

void Engine::render() {
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Engine::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}