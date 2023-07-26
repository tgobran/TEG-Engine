#include "Engine.h"

#include <iostream>

#include "SDL.h"

#include "Graphics/WindowSDL.h"
#include "Input/InputSDL.h"

void Engine::activate() {
	graphics = new WindowSDL();
	graphics->initialize("TApp", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
	input = new InputSDL();
	input->initialize();
	active = true;
}

void Engine::execute() {
	while (active) {
		handleInput(input->check());
		graphics->update();
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