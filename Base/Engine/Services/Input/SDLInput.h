#pragma once

#include "../Input.h"

#include "SDL.h"

class SDLInput : public Input {

public:
	void initialize();
	
	InputCommand check();
};