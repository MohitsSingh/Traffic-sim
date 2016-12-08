#pragma once
#include "Includes.h"
#include "MapOBJ.h"
#include "TransportMode.h"
class TransportMode;

class Intersection
{
protected:
	
	int intersectionID;
	int intersectionSize;
	

	int nLanes;
	int sLanes;
	int eLanes;
	int wLanes;

public:
	INTERSECTION_TYPES interType;
	
	Intersection();
	Intersection(int id, int xLoc, int yLoc, int northL, int southL, int eastL, int westL);

	int getIntersectionID();
	int getIntersectionSize();
	virtual int getNumberOfLanes(CARDINAL inputCARDINAL);
	virtual vector <TransportMode*> interPop();
	virtual LIGHTCOLOR getLightColor(CARDINAL dir);

	virtual void interPush(TransportMode* modes);
	virtual void updateSignal();

	void setIntersectionID(int value);
};
