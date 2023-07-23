#include <iostream>

#include "Engine.h"

#include "Services/Graphics/SDLWindow.h"
#include "Services/Input/SDLInput.h"

void Engine::activate() {
	graphics = new SDLWindow();
	graphics->initialize("TApp", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);
	input = new SDLInput();
	input->initialize();
	isActive = true;
}

void Engine::execute() {
	handleInput(input->check());
	graphics->update();
}

void  Engine::deactivate() {
	graphics->cleanup();
}

void Engine::handleInput(InputCommand input) {
	switch (input) {
	case InputCommand::Exit:
		isActive = false;
		break;
	default:
		break;
	}
}