#pragma once
#include "Includes.h"

Intersection::Intersection()     // the default constructer that makes an intersection with a stop sign
{
	//typeSign = stop;
	nLanes = 1;
	sLanes = 1;
	eLanes = 1;
	wLanes = 1;
	createPointers();
}


Intersection::Intersection(int xLoc, int yLoc)  // overloaded constructer that makes a specific intersection based on location
{
	//sign signArray[2][2];
	//signArray[0][0] = stop;
	//signArray[0][1] = light;
	//typeSign = signArray[xLoc][yLoc];
	nLanes = 1;
	sLanes = 1;
	eLanes = 1;
	wLanes = 1;
	createPointers();
}
Intersection::Intersection(int inputIntersectionID, int nbLanes, int ebLanes, int sbLanes, int wbLanes)
{
	intersectionID = inputIntersectionID;
	nLanes = nbLanes;
	eLanes = ebLanes;
	sLanes = sbLanes;
	wLanes = wbLanes;
	createPointers();
}
void Intersection::createPointers()
{
	nLaneColor = new LIGHTCOLOR[nLanes];
	sLaneColor = new LIGHTCOLOR[sLanes];
	eLaneColor = new LIGHTCOLOR[eLanes];
	wLaneColor = new LIGHTCOLOR[wLanes];
}
int Intersection::approachingCar(int xLoc, int yLoc) // returns stop or go for car
{
	//sign signArray[2][2];
	//signArray[0][0] = stop;
	//signArray[0][1] = light;
	//int typeSign = signArray[xLoc][yLoc];
	//if (typeSign == 0)
	//{
	//	return typeSign;
	//}
	//else
	//{
	//	int lightStat = checkLight(xLoc, yLoc);
	//}

	return 0;
}

LIGHTCOLOR Intersection::getLightColor(DIRECTION inputDirection, int laneNumber)
{
	//int lightArray[3][2];
	//lightArray[0][0] = 1;
	//lightArray[0][1] = 2;
	//lightArray[0][2] = 0;
	//int status = lightArray[xLoc][yLoc];
	//return 0;
	switch (inputDirection)
	{
	case NORTH:
		return nLaneColor[laneNumber];
	case EAST:
		return eLaneColor[laneNumber];
	case SOUTH:
		return sLaneColor[laneNumber];
	case WEST:
		return wLaneColor[laneNumber];
	default:
		return RED;
	}

	return RED;
}


int *Intersection::turnChoice(int xLoc, int yLoc)  //based on location only permits allowable turns
{
	int turnArray[3] = {1,1,1};
	return turnArray;

}
int Intersection::getNumberOfLanes(DIRECTION inputDirection)
{
	switch (inputDirection)
	{
	case NORTH:
		return nLanes;
		break;
	case EAST:
		return eLanes;
		break;
	case SOUTH:
		return sLanes;
		break;
	case WEST:
		return wLanes;
		break;
	default:
		break;
	}
	return 0;
}