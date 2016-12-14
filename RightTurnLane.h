#pragma once

#include "Includes.h"

class RightTurnLane : public Right {
private:

	int width;


public:
	RightTurnLane();
	~RightTurnLane();

	void setWidth(int x) {
		width = x;
	}


	int getWidth() {
		return width;
	}

};