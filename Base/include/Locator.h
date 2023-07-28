#pragma once

//#include "Object/ObjectManager.fwd.h"

#include "Graphics/Graphics.h"
#include "Input/Input.h"
#include "Object/ObjectManager.h"

class Locator {

public:
	static void initialize(Graphics* g, Input* i, ObjectManager* o) {
		graphics = g;
		input = i;
		objects = o;
	}

	static Graphics* getGraphics() {
		return graphics;
	}

	static Input* getInput() {
		return input;
	}

	static ObjectManager* getObjectManager() {
		return objects;
	}

private:
	static ObjectManager* objects;
	static Graphics* graphics;
	static Input* input;

};