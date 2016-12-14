
#pragma once
#include "Includes.h"

class LeftBikeLane : public Left {
private:

	int width;


public:
	LeftBikeLane();
	~LeftBikeLane();

	void setWidth(int x) {
		width = x;
	}


	int getWidth() {
		return width;
	}

};