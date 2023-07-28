#include "Object/Object.h"

void Object::addComponent(Component* c) {
	components.push_back(c);
}

void Object::update() {
	for (auto const& c : components)
		c->update(this);
}

void Object::cleanup() {
	// TODO Cleanup Function
}
