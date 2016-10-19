#pragma once
#include "Includes.h"

class turnLane : public Road {
private:

	int width;


public:
	turnLane();
	~turnLane();

	void setWidth(int x) {
		width = x;
	}


	int getWidth() {
		return width;
	}

};
