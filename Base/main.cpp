#include "SDL.h"

#include "Engine/Engine.h"

Engine* engine = nullptr;

int main(int argc, char* argv[]) {

	engine = new Engine();

	engine->activate();
	while (engine->active())
		engine->execute();
	engine->deactivate();

	return 0;
}