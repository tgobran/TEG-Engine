#pragma once

#include "Object/Component.h"

#include "Locator.h"

class ClickableComponent : public Component {

public:
	ClickableComponent() {}

	void update(Object* entity) {
		if (Locator::getInput()->isMouseDown()) {
			if (Locator::getInput()->getMousePos().first) {
			}
			DEBUG("CLICKABLE","CLICK FOUND")
		}
	}
};