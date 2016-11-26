#pragma once
#include "Includes.h"
#include "TransportMode.h"

class Intersection
{
private:
	int someInt;
	bool waiting;
	deque <TransportMode*> cars;
	
	
protected:
	//protected data lets the data types be accesses by sub classes such as our stop lights, 4way stops, 2way stops etc...
	//all common information about intersections will be stored in here
	int intersectionID;
	//int nLanes = 0;	//try not to set values inside class calls make defaults inside the default constructor
	//or give the possibility of an overide that lets you set on the class call
	int nLanes;
	int sLanes;
	int eLanes;
	int wLanes;
	double xLoc;                     // the x is columns	
	double yLoc;                     // the y is rows
	int carDirection();
	LIGHTCOLOR *nLaneColor;
	LIGHTCOLOR *sLaneColor;
	LIGHTCOLOR *eLaneColor;
	LIGHTCOLOR *wLaneColor;

	void createPointers();

public:
	bool getWaiting();
	void interPush(TransportMode* modes);
	vector <TransportMode*> Intersection::interPop();
	Intersection();
	Intersection(double xLoc, double yLoc);
	Intersection(int inputIntersectionID, int nbLanes, int ebLanes, int sbLanes, int wbLanes);
	double getXLoc();
	double getYLoc();
	
	virtual int approachingCar(int xLoc, int yLoc);
	virtual LIGHTCOLOR checkLight(CARDINAL inputCARDINAL, int laneNumber);	//we will asume that stop signs are the same as a red light
	virtual int *turnChoice(int xLoc, int yLoc);
	virtual int getNumberOfLanes(CARDINAL inputCARDINAL);
};


