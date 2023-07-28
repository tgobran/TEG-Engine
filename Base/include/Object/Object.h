#pragma once

#include <vector>

#include "Component.h"

class Object {

public:
	Object(int x, int y, int w, int h, std::initializer_list<Component*> c) : xpos(x), ypos(y), width(w), height(h) {
		for (auto component : c) {
			addComponent(component);
		}
	};
	
	~Object() {};

	void addComponent(Component* c);

	void update();

	void cleanup();

	void setX(int newX) { xpos = newX; }
	void setY(int newY) { ypos = newY; }

private:
	unsigned int ID;
	std::vector<Component*> components;

	int xpos;
	int ypos;
	int width;
	int height;
};