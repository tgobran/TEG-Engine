#pragma once

#include "../Debug.h"

#define GRAPHICS_DEBUG(X) DEBUG("GRAPHICS",X)

class Graphics {

public:
	virtual ~Graphics() {};

	virtual void initialize(const char* name, int xpos, int ypos, int width, int height, bool fullscreen) = 0;

	virtual void update() = 0;

	virtual void cleanup() = 0;
};