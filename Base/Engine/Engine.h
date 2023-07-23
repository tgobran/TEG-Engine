#pragma once

#include "Services/Graphics.h"
#include "Services/Input.h"

class Engine {

public:
	Engine() {};
	~Engine() {};

	void activate();

	void execute();

	void deactivate();

	bool active() { return isActive; }

private:
	void handleInput(InputCommand input);

	bool isActive;

	Graphics* graphics;
	Input* input;
};