#pragma once

class MouseListener {
public:
	virtual void onMouseDown(int x, int y) = 0;
	virtual void onMouseMove(int x, int y) = 0;
	virtual void onMouseUp(int x, int y) = 0;
};