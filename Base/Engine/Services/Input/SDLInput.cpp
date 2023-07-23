#include "SDLInput.h"

void SDLInput::initialize() {
	INPUT_DEBUG("Initialize Started")
	if (SDL_Init(SDL_INIT_EVENTS) == 0) {
		INPUT_DEBUG("SDL Event Initialized")
	}
	INPUT_DEBUG("Initialize Completed")
}

InputCommand SDLInput::check() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		INPUT_DEBUG("Check - Quit")
		return InputCommand::Exit;
	}
	return InputCommand::NONE;
}