#include "Object/Object.h"

Object::Object(int x, int y, int w, int h, std::initializer_list<Component*> c) : xpos(x), ypos(y), width(w), height(h) {
	for (Component* component : c) {
		component->setObject(this);
		components.push_back(component);
	}
};

void Object::addComponent(Component* c) {
	c->setObject(this);
	components.push_back(c);
}

void Object::update() {
	for (Component* c : components)
		c->update();
}

void Object::cleanup() {
	for (Component* c : components)
		delete c;
	components.clear();
}
