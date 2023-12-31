#pragma once

#include "Object/ObjectManager.h"
#include "Graphics/Graphics.h"
#include "Input/Input.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int FPS = 60;
const int frameDelay = 1000 / FPS;

class Engine {

public:
	Engine() {};
	~Engine() {};

	void activate();

	void execute(); 

	void deactivate();

private:
	bool active = false;

	Graphics* graphics = nullptr;
	Input* input = nullptr;
	ObjectManager* objects = nullptr;
};