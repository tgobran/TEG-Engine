#pragma once

#include "Graphics/Graphics.h"
#include "Input/Input.h"

class Locator {

public:
	static void initialize(Graphics* g, Input* i) {
		graphics = g;
		input = i;
	}

	static Graphics* getGraphics() {
		return graphics;
	}

	static Input* getInput() {
		return input;
	}

private:
	static Graphics* graphics;
	static Input* input;
};

Graphics* Locator::graphics = nullptr;
Input* Locator::input = nullptr;