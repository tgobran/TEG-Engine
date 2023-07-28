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
	int getX() { return xpos; }
	void setY(int newY) { ypos = newY; }
	int getY() { return ypos; }

	int getWidth() { return width; }
	int getHeight() { return height; }

private:
	unsigned int ID;
	std::vector<Component*> components;

	int xpos;
	int ypos;
	int width;
	int height;
};