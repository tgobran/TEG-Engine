#include "Engine.h"

#include "SDL.h"

#include "Locator.h"
#include "Graphics/GraphicsSDL.h"
#include "Input/InputSDL.h"

// TODO Remove for final version
#include "Object/Components/ClickableComponent.h"
void toyOnClick() {
	std::cerr << "CLICKED OBJECT" << std::endl;
}


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
	objects->addObject(new Object(100, 100, 100, 100, { new ClickableComponent(&toyOnClick)}));
}

void Engine::execute() {
	Uint32 frameStart;
	int frameTime;
	while (active) {
		frameStart = SDL_GetTicks();

		active = input->check();
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

	delete objects;
	delete input;
	delete graphics;
}