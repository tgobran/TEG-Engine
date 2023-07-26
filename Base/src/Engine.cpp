#include "Engine.h"

#include <iostream>

#include "SDL.h"

#include "Graphics/GraphicsSDL.h"
#include "Input/InputSDL.h"

void Engine::activate() {
	graphics = new GraphicsSDL();
	graphics->initialize("Solitaire", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
	input = new InputSDL();
	input->initialize();
	active = true;
}

void Engine::execute() {
	Uint32 frameStart;
	int frameTime;
	while (active) {
		frameStart = SDL_GetTicks();

		handleInput(input->check());
		graphics->update();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
}

void  Engine::deactivate() {
	graphics->cleanup();
	SDL_Quit();
}

void Engine::handleInput(InputCommand input) {
	switch (input) {
	case InputCommand::Quit:
		active = false;
		break;
	default:
		break;
	}
}