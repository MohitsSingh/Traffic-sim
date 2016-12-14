
#pragma once
#include "Includes.h"

class LeftLane : public Left {
private:

	int width;


public:
	LeftLane();
	~LeftLane();

	void setWidth(int x) {
		width = x;
	}


	int getWidth() {
		return width;
	}

};
