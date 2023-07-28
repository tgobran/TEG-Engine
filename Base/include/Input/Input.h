#pragma once

#include <utility>

#include "Debug.h"

#define INPUT_DEBUG(X) DEBUG("INPUT",X)

class Input {

public:
	virtual ~Input() {};

	virtual void initialize() = 0;

	virtual bool check() = 0;

	bool isMouseDown() { return mouseDown; }
	bool isMouseHold() { return mouseHold; }
	std::pair<int, int> getMousePos() { return std::make_pair(mouseDownX, mouseDownY);  }
	std::pair<int, int> getMouseDest() { return std::make_pair(mouseUpX, mouseUpY); }

	bool isKeyDown() { return keyDown; }
	bool isKeyHold() { return keyHold; }
	char getKeyDown() { return key; }

protected:
	bool mouseDown;
	bool mouseHold;
	int mouseDownX;
	int mouseDownY;
	int mouseUpX;
	int mouseUpY;

	bool keyDown;
	bool keyHold;
	char key;
};