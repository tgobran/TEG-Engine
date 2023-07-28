#pragma once

#include <vector>

#include "Debug.h"

#include "Listener/MouseListener.h"

#define INPUT_DEBUG(X) DEBUG("INPUT",X)

class Input {

public:
	virtual ~Input() {};

	virtual void initialize() = 0;

	virtual bool check() = 0;

	void addMouseListener(MouseListener* listener) { mouseListeners.push_back(listener); }

	bool isKeyDown() { return keyDown; }
	bool isKeyHold() { return keyHold; }
	char getKeyDown() { return key; }

protected:
	bool mouseDown;
	int mouseX;
	int mouseY;

	bool keyDown;
	bool keyHold;
	char key;

	std::vector<MouseListener*> mouseListeners;
};