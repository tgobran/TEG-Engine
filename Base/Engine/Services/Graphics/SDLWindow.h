#pragma once

#include "../Graphics.h"

#include "SDL.h"

class SDLWindow : public Graphics {

public:
	void initialize(const char* name, int xpos, int ypos, int width, int height, bool fullscreen);

	void update();
	
	void cleanup();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

