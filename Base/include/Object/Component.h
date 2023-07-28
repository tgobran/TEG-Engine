#pragma once

#include "Object/Object.fwd.h"

#include "Object/Object.h"

class Component {

public:
	virtual void update(Object* object) = 0;
};