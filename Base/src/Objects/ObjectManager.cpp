#include "Object/ObjectManager.h"

void ObjectManager::update() {
	for (auto const& e : objectMap)
		e.second->update();
}

void ObjectManager::addObject(Object *object) {
	objectMap[nextID] = object;
	nextID++;
}

void ObjectManager::destroyObject(int ID) {
	objectMap[ID]->cleanup();
	objectMap.erase(ID);
}

void ObjectManager::cleanup() {
	for (auto const& e : objectMap)
		e.second->cleanup();
	objectMap.clear();
}