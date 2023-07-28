#include "Engine.h"

#include "SDL.h"

#include "Locator.h"
#include "Graphics/GraphicsSDL.h"
#include "Input/InputSDL.h"

// TODO Remove for final version
#include "Object/Components/ClickableComponent.h"

void Engine::activate() {
	graphics = new GraphicsSDL();
	graphics->initialize("Solitaire", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
	input = new InputSDL();
	input->initialize();
	objects = new ObjectManager();
	int i = 10;
	Locator::initialize(graphics, input);
	active = true;

	// TODO REMOVE AFTER TESTING
	objects->addObject(new Object(100, 100, 100, 100, { new ClickableComponent()}));
}

void Engine::execute() {
	Uint32 frameStart;
	int frameTime;
	while (active) {
		frameStart = SDL_GetTicks();

		handleInput(input->check());
		objects->update();
		graphics->update();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
}

void  Engine::deactivate() {
	objects->cleanup();
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