#pragma once
#include "Includes.h"

class RightLane : public Right{
private:

	int width;


public:
	RightLane();
	~RightLane();

	void setWidth(int x) {
		width = x;
	}


	int getWidth() {
		return width;
	}

};
