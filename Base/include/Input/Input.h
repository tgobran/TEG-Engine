#pragma once

#include "Debug.h"

#define INPUT_DEBUG(X) DEBUG("INPUT",X)

enum class InputCommand {
	NONE,
	Back,
	Quit,
};

class Input {

public:
	virtual ~Input() {};

	virtual void initialize() = 0;

	virtual InputCommand check() = 0;
};