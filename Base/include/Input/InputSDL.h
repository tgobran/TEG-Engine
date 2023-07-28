#pragma once
#include "Input/Input.h"

#include "SDL.h"

class InputSDL : public Input {

public:
	void initialize();
	
	bool check();

private:
	void mouseDownHandler(SDL_MouseButtonEvent* event);
	void mouseUpHandler(SDL_MouseButtonEvent* event);

	void mouseMotionHandler(SDL_MouseMotionEvent* event);

	void keyDownHandler(SDL_KeyboardEvent* event);
	void keyUpHandler(SDL_KeyboardEvent* event);
};