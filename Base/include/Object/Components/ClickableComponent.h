#pragma once

#include <iostream>

#include "Listener/MouseListener.h"
#include "Object/Component.h"

class ClickableComponent : public Component, MouseListener {

public:
	ClickableComponent(void (*func)());

	void update();
	void onMouseDown(int x, int y);
	void onMouseUp(int x, int y);
	void onMouseMove(int x, int y);

private:
	bool clicked = false;
	bool cDown = false;
	void (*onClick)();
};