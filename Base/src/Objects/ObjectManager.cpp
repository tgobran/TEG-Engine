#include "Object/ObjectManager.h"

void ObjectManager::update() {
	for (auto const& e : objectMap)
		e.second->update();
}

void ObjectManager::addEntity(Object* entity) {
	objectMap[nextID] = entity;
	nextID++;
}

void ObjectManager::deleteEntity(int ID) {
	objectMap[ID]->cleanup();
	objectMap.erase(ID);
}

void ObjectManager::cleanup() {
	for (auto const& e : objectMap)
		e.second->cleanup();
	objectMap.clear();
}