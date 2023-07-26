#include "SDL.h"

#include "Engine.h"

Engine* engine = nullptr;

int main(int argc, char* argv[]) {

	engine = new Engine();

	engine->activate();
	engine->execute();
	engine->deactivate();

	return 0;
}