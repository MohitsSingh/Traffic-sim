#pragma once
#include "Includes.h"
#include "Intersection.h"

Intersection::Intersection()     // the default constructer that makes an intersection with a stop sign
{
	nLanes = 1;
	sLanes = 1;
	eLanes = 1;
	wLanes = 1;
	intersectionSize = 4;
}


Intersection::Intersection(int id, int xLoc, int yLoc, int northL, int southL, int eastL, int westL)
{
	intersectionID = id;
	nLanes = northL;
	sLanes = southL;
	eLanes = eastL;
	wLanes = westL;
	intersectionSize = nLanes + sLanes + eLanes + wLanes;
}


int Intersection::getIntersectionID()
{
	return intersectionID;
}

int Intersection::getIntersectionSize()
{
	return intersectionSize;
}

int Intersection::getNumberOfLanes(CARDINAL inputCARDINAL)
{
	switch (inputCARDINAL)
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
		return -1;
		break;
	}
}

vector<TransportMode*> Intersection::interPop()
{
	return vector<TransportMode*>();
}

void Intersection::interPush(TransportMode *modes)
{
}

void Intersection::setIntersectionID(int value)
{
	intersectionID = value;
}

