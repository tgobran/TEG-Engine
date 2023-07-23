#pragma once

#include "SDL.h"

class Engine {

public:
	Engine() {};
	~Engine() {};

	void initialize(const char* name, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();

	void clean();

	bool active() { return isActive; }

private:
	bool isActive;
	SDL_Window* window;
	SDL_Renderer* renderer;
};