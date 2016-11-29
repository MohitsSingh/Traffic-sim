#pragma once
#include "Includes.h"

class RightBikeLane : public Right {
private:

	int width;


public:
	RightBikeLane();
	~RightBikeLane();

	void setWidth(int x) {
		width = x;
	}


	int getWidth() {
		return width;
	}

};