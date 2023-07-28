#pragma once

#include <map>

#include "Object.h"

class ObjectManager {

public:
	void update();

	void addEntity(Object* entity);

	void deleteEntity(int ID);

	void cleanup();

private:
	int nextID = 0;

	std::map<int, Object*> objectMap;
};