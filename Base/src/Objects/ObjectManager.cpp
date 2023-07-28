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
	delete objectMap[ID];
	objectMap.erase(ID);
}

void ObjectManager::cleanup() {
	for (auto const& o : objectMap) {
		o.second->cleanup();
		delete o.second;
	}
	objectMap.clear();
}