#pragma once
#include "Includes.h"

class FourWayStop : public Intersection
{
private:
	int someInt;
protected:

public:
	FourWayStop();
	FourWayStop(int inputIntersectionID, int nbLanes, int ebLanes, int sbLanes, int wbLanes);

	//virtual int getNumberOfLanes(DIRECTION inputDirection);
};