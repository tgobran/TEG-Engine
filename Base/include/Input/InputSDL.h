#pragma once
#include "Input/Input.h"

#include "SDL.h"

class InputSDL : public Input {

public:
	void initialize();
	
	InputCommand check();
};