#pragma once

#include "Debug.h"

#define WINDOW_DEBUG(X) DEBUG("WINDOW",X)

class Window {

public:
	virtual ~Window() {};

	virtual void initialize(const char* name, int xpos, int ypos, int width, int height, bool fullscreen) = 0;

	virtual void update() = 0;

	virtual void cleanup() = 0;

	virtual int loadTexture(std::string path) = 0;
	virtual void renderTexture(unsigned int id) = 0;
};