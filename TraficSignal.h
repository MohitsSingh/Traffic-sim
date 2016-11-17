/******
WORK IN PROGRESS!!
*******/

#pragma once
#include "Includes.h"
#include "Intersection.h"

class TraficSignal : public Intersection
{
public:
	LIGHTCOLOR curStraightColor[4];			//current straight color
	LIGHTCOLOR curArrowColor[4];			//current turn arrow color
	
private:
	int lightTimes[3];						//straight light color times
	int turnArrowTimes[2][4];				//turn arrow times
	int internalTime;						

	void updateSignal()
	{

	}


	
	
};