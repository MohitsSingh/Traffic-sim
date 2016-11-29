
#pragma once
#include "Includes.h"

class LeftTurnLane : public Left {
private:

	int width;


public:
	LeftTurnLane();
	~LeftTurnLane();

	void setWidth(int x) {
		width = x;
	}


	int getWidth() {
		return width;
	}

};