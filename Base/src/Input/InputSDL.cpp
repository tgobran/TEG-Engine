#include "Input/InputSDL.h"

void InputSDL::initialize() {
	INPUT_DEBUG("Initialize Started")
	if (SDL_Init(SDL_INIT_EVENTS) == 0) {
		INPUT_DEBUG("SDL Event Initialized")
	}
	INPUT_DEBUG("Initialize Completed")
}

bool InputSDL::check() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		INPUT_DEBUG("Check - Quit")
			return false;
	case SDL_MOUSEBUTTONDOWN:
		mouseDownHandler(&event.button);
		break;
	case SDL_MOUSEBUTTONUP:
		mouseUpHandler(&event.button);
		break;
	case SDL_MOUSEMOTION:
		mouseMotionHandler(&event.motion);
		break;
	case SDL_KEYDOWN:
		keyDownHandler(&event.key);
		break;
	case SDL_KEYUP:
		keyUpHandler(&event.key);
		break;
	}
	return true;
}

void InputSDL::mouseDownHandler(SDL_MouseButtonEvent* event) {
	mouseDown = true;
	switch (event->button) {
	case SDL_BUTTON_LEFT:
		INPUT_DEBUG("MOUSE DOWN | LEFT   | X = " << event->x << " Y = " << event->y)
		break;
	case SDL_BUTTON_MIDDLE:
		INPUT_DEBUG("MOUSE DOWN | MIDDLE | X = " << event->x << " Y = " << event->y)
		break;
	case SDL_BUTTON_RIGHT:
		INPUT_DEBUG("MOUSE DOWN | RIGHT  | X = " << event->x << " Y = " << event->y)
		break;
	}
	for (MouseListener* l : mouseListeners)
		l->onMouseDown(event->x, event->y);
}

void InputSDL::mouseUpHandler(SDL_MouseButtonEvent* event) {
	mouseDown = false;
	switch (event->button) {
	case SDL_BUTTON_LEFT:
		INPUT_DEBUG("MOUSE UP   | LEFT   | X = " << event->x << " Y = " << event->y)
			break;
	case SDL_BUTTON_MIDDLE:
		INPUT_DEBUG("MOUSE UP   | MIDDLE | X = " << event->x << " Y = " << event->y)
			break;
	case SDL_BUTTON_RIGHT:
		INPUT_DEBUG("MOUSE UP   | RIGHT  | X = " << event->x << " Y = " << event->y)
			break;
	}
	for (MouseListener* l : mouseListeners)
		l->onMouseUp(event->x, event->y);
}

void InputSDL::mouseMotionHandler(SDL_MouseMotionEvent* event) {
	mouseX = event->x;
	mouseY = event->y;
	for (MouseListener* l : mouseListeners)
		l->onMouseMove(event->x, event->y);
}

void InputSDL::keyDownHandler(SDL_KeyboardEvent* event) {
	if (keyDown)
		keyHold = true;
	else
		keyDown = true;
	INPUT_DEBUG("KEY DOWN | " << (char)event->keysym.sym)
	key = event->keysym.sym;
}

void InputSDL::keyUpHandler(SDL_KeyboardEvent* event) {
	keyHold = false;
	keyDown = false;
	INPUT_DEBUG("KEY UP   | " << (char)event->keysym.sym)
}