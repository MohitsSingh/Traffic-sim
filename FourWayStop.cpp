#pragma once
#include "FourWayStop.h"

FourWayStop::FourWayStop()
{
	intersectionID = 0;
	nLanes = 1;
	eLanes = 1;
	sLanes = 1;
	wLanes = 1;
	createPointers();
}

FourWayStop::FourWayStop(int inputIntersectionID, int nbLanes, int ebLanes, int sbLanes, int wbLanes)
{
	intersectionID = inputIntersectionID;
	nLanes = nbLanes;
	eLanes = ebLanes;
	sLanes = sbLanes;
	wLanes = wbLanes;
	createPointers();

	for (int i = 0; i < nbLanes; i++)
		nLaneColor[i] = RED;
	for (int i = 0; i < ebLanes; i++)
		eLaneColor[i] = RED;
	for (int i = 0; i < sbLanes; i++)
		sLaneColor[i] = RED;
	for (int i = 0; i < wbLanes; i++)
		wLaneColor[i] = RED;
}

