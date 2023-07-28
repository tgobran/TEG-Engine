#pragma once

#include <utility>

#include "Debug.h"

#define INPUT_DEBUG(X) DEBUG("INPUT",X)

enum class InputCommand {
	NONE,
	Back,
	Quit,
};

class Input {

public:
	virtual ~Input() {};

	virtual void initialize() = 0;

	virtual InputCommand check() = 0;

	bool isMouseDown() { return mouseDown; }
	std::pair<int, int> getMousePos() { return std::make_pair(mouseX, mouseY);  }

protected:
	bool mouseDown;
	int mouseX;
	int mouseY;
};