#pragma once
#include "Includes.h"

class bikeLane : public Road {
private:

	int width;


public:
	bikeLane();
	~bikeLane();

	void setWidth(int x) {
		width = x;
	}


	int getWidth() {
		return width;
	}

};
