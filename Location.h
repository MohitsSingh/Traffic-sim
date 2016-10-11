#pragma once
#include "includes.h"
class Location
{
private:
	int xCoord, yCoord; //distance in meters along x or y axis

public:
	Location();
	Location(int x, int y);
	virtual ~Location();
	void printLocation();

	void setXCoord(int value);
	void setYCoord(int value);
	int getXCoord();
	int getYCoord();
	void move(int distance, double direction)
	{
		xCoord += distance * cos(direction);
		yCoord += distance * sin(direction);
	}
};

//latitude += distance * sin(direction) * 0.001;
//longitude += distance * cos(direction) * 0.001;