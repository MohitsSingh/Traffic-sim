#pragma once
#include "Includes.h"

class Lane : public Road{
private:

	int width;


public:
	Lane();
	~Lane();

	void setWidth(int x) {
		width = x;
	}


	int getWidth() {
		return width;
	}

};
