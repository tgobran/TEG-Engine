#include "SDL.h"

#include "Engine.h"

Engine* engine = nullptr;

int main(int argc, char* argv[]) {

	engine = new Engine();
	engine->initialize("TApp", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);
	while (engine->active()) {
		engine->handleEvents();
		engine->update();
		engine->render();
	}
	engine->clean();

	return 0;
}