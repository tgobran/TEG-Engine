#pragma once

#include "Debug.h"

#define TEXTURE_DEBUG(X) DEBUG("TEXTURE",X)

class Texture {

public:
	virtual ~Texture() {};

	virtual void cleanup() = 0;
};