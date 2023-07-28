#pragma once

#include "Object/Object.fwd.h"

#include "Object/Object.h"

class Component {

public:
	void setObject(Object* o) { object = o; }
	virtual void update() = 0;

protected:
	Object* object;
};