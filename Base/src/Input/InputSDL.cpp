#include "Input/InputSDL.h"

void InputSDL::initialize() {
	INPUT_DEBUG("Initialize Started")
	if (SDL_Init(SDL_INIT_EVENTS) == 0) {
		INPUT_DEBUG("SDL Event Initialized")
	}
	INPUT_DEBUG("Initialize Completed")
}

InputCommand InputSDL::check() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		INPUT_DEBUG("Check - Quit")
		return InputCommand::Quit;
	case SDL_KEYDOWN:
		INPUT_DEBUG("KEYDOWN")
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			INPUT_DEBUG("Check - BACK")
			return InputCommand::Quit;
		}
	}
	return InputCommand::NONE;
}