/******
@author Wesley Stutzman
This is the class declaration for all the functions that a Trafic Signal is able to do
*******/

#pragma once
#include "Includes.h"

class TraficSignal : public Intersection
{
public:
	TraficSignal(int inputIntersectionID, int nbLanes, int ebLanes, int sbLanes, int wbLanes);
	void setLightCycle(DIRECTION inputDirection, LIGHTCOLOR inputLightColor, int inputLane, int inputSecond);
	void setLightTime(int inTime);
	int getLengthOfCycle();
	~TraficSignal();
private:
	int maxLightSeconds;
	int numberOfDirections;
	LIGHTCOLOR ***allLightCycleColors;	//[direction][second][lane]
	LIGHTCOLOR **nLightCycleColors; //[seconds][lanes]
	LIGHTCOLOR **eLightCycleColors; //[seconds][lanes]
	LIGHTCOLOR **sLightCycleColors; //[seconds][lanes]
	LIGHTCOLOR **wLightCycleColors; //[seconds][lanes]
	
	void increaseLightCylceTime(int endSeconds);
	void setLightColors(DIRECTION inputDirection, LIGHTCOLOR inputLightColor, int lane);
};