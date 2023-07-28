#pragma once

#include <iostream>

#include "Object/Component.h"

#include "Locator.h"

class ClickableComponent : public Component {

public:
	ClickableComponent() {}

	void update(Object* obj) {
		if (Locator::getInput()->isMouseDown()) {
			int mouseX = Locator::getInput()->getMousePos().first;
			int mouseY = Locator::getInput()->getMousePos().second;
			if (!(mouseX >= obj->getX() && mouseX <= obj->getWidth()+obj->getX()))
				return;
			if (!(mouseY >= obj->getY() && mouseY <= obj->getHeight() + obj->getY()))
				return;
			DEBUG("CLICKABLE","CLICK FOUND")
		}
	}
};