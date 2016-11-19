#pragma once
#include "Includes.h"
#include "MapOBJ.h"
#include "TransportMode.h"

class Intersection : public MapOBJ
{
protected:
	
	int intersectionID;
	int intersectionSize;
	
	int nLanes;
	int sLanes;
	int eLanes;
	int wLanes;


public:
	
	
	Intersection();
	Intersection(int xLoc, int yLoc);
	Intersection(int id, int xLoc, int yLoc, int northL, int southL, int eastL, int westL);

	int getIntersectionID();
	int getIntersectionSize();
	virtual int getNumberOfLanes(CARDINAL inputCARDINAL);

	void setIntersectionID(int value);
};


