/******
WORK IN PROGRESS!!
*******/

#pragma once
#include "Includes.h"
#include "Intersection.h"

class TraficSignal : public Intersection
{
public:
	

	TraficSignal();
	void updateSignal();
	LIGHTCOLOR getLightColor(CARDINAL dir);

private:
	int strightTimeCycles[3];						//straight light color times
	int turnArrowTimeCycles[2][4];				//turn arrow times
	int curTime[4];
	LIGHTCOLOR curStraightColor[4];			//current straight color
	LIGHTCOLOR curArrowColor[4];			//current turn arrow color

	
	
};