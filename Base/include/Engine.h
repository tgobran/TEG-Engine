#pragma once

#include "Graphics/Window.h"
#include "Input/Input.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int FPS = 60;
const int frameDelay = 1000 / FPS;

class Engine {

public:
	Engine() {};
	~Engine() {};

	void activate();

	void execute(); 

	void deactivate();

private:
	void handleInput(InputCommand input);

	bool active;

	Graphics* graphics;
	Input* input;
};