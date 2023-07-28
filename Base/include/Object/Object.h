#pragma once

#include <vector>

#include "Component.h"

class Object {

public:
	Object(unsigned int id) : ID(id) {};
	
	~Object() {};

	void addComponent(Component* c);

	void update();

	void cleanup();

private:
	unsigned int ID;

	std::vector<Component*> components;
};