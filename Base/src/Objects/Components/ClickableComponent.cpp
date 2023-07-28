#include "Object/Components/ClickableComponent.h"

#include "Locator.h"

ClickableComponent::ClickableComponent(void (*func)()) : onClick(func) {
	Locator::getInput()->addMouseListener(this);
}

void ClickableComponent::update() {
	if (clicked) {
		onClick();
		clicked = false;
	}
}

void ClickableComponent::onMouseDown(int x, int y) {
	cDown = false;
	if (!(x >= object->getX() && x <= object->getWidth() + object->getX()))
		return;
	if (!(x >= object->getY() && x <= object->getHeight() + object->getY()))
		return;
	cDown = true;
}

void ClickableComponent::onMouseUp(int x, int y) {
	if (cDown) {
		if (!(x >= object->getX() && x <= object->getWidth() + object->getX()))
			return;
		if (!(x >= object->getY() && x <= object->getHeight() + object->getY()))
			return;
		clicked = true;
		cDown = false;
	}
}

void ClickableComponent::onMouseMove(int x, int y) {}