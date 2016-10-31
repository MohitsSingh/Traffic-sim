/***
@Author Wesley Stutzman
This class holds the functions to controll how a trafic light will work
It can be pluged into an intersection and controll the intersections values based on telling it what time cycle we are on
***/
#pragma once
#include "Includes.h"

//allows the user to input all important information about the trafic signal at the point of creation
TraficSignal::TraficSignal(int inputIntersectionID, int nbLanes, int ebLanes, int sbLanes, int wbLanes)
{
	maxLightSeconds = 0;												//set the max amount of time in the light cycle to zero
	intersectionID = inputIntersectionID;								//inser in an intersection id might be removed later for knowing the intersection by its id in an array
	nLanes = nbLanes;													//set the number of lanes going north
	eLanes = ebLanes;													//set the number of lanes going east
	sLanes = sbLanes;													//set the number of lanes going south
	wLanes = wbLanes;													//set the number of lanes going west
	createPointers();													//create the pointers that store the Intersecion light colors (Inside intersection class)
	numberOfDirections = 4;												//set the general amount of direction (this is for easy changes later in code if needed)
	int sampleLightSize = 501;											//start the lights with a general "500"seconds worth of cycles (can be grown later)
																		//start to build a 3D array [directions][seconds][lane]
	allLightCycleColors = new LIGHTCOLOR**[numberOfDirections];			//create the array with the four difrent directions
	for (int i = 0; i < numberOfDirections; i++)						
		allLightCycleColors[i] = new LIGHTCOLOR*[sampleLightSize];		//save the general size of the light cycles in seconds

	for (int i = 0; i < numberOfDirections; i++)						//now add in the number of lanes to each direction at that second
	{
		for (int m = 0; m < sampleLightSize; m++)						//loop based on the seconds of light time
		{
			switch (i)													//create each new pointer based on its direction
			{
			case 0:
				allLightCycleColors[i][m] = new LIGHTCOLOR[nLanes];		//set the number of lanes
				break;
			case 1:
				allLightCycleColors[i][m] = new LIGHTCOLOR[eLanes];
				break;
			case 2:
				allLightCycleColors[i][m] = new LIGHTCOLOR[sLanes];
				break;
			case 3:
				allLightCycleColors[i][m] = new LIGHTCOLOR[wLanes];
				break;
			default:
				cout << "ERROR SETTING POINTERS FOR LIGHT COLORS; INSIDE TRAFICSIGNAL CONSTRUCTOR" << endl;
				break;
			}
		}
	}
}
TraficSignal::~TraficSignal()
{
	delete[]allLightCycleColors;										//destroy the pointer since we are now done with it
}
//returns the current light cycle timing
int TraficSignal::getLengthOfCycle()
{
	return maxLightSeconds;
}
void TraficSignal::setLightCycle(DIRECTION inputDirection, LIGHTCOLOR inputLightColor, int inputLane, int inputSecond)
{
	if (inputSecond > maxLightSeconds)
		maxLightSeconds = inputSecond;
	allLightCycleColors[inputDirection][inputSecond][inputLane] = inputLightColor;
}
void TraficSignal::setLightTime(int inTime)
{
	//change all lane light colors based on the time interval and lanes of the light cycle
	if (inTime > maxLightSeconds)
		throw "Invalid light time";

	for (int i = 0; i < nLanes; i++)
		nLaneColor[i] = allLightCycleColors[0][inTime][i];		//set the lane inside intersection class to the color of the light at this second
	for (int i = 0; i < eLanes; i++)
		eLaneColor[i] = allLightCycleColors[1][inTime][i];
	for (int i = 0; i < sLanes; i++)
		sLaneColor[i] = allLightCycleColors[2][inTime][i];
	for (int i = 0; i < wLanes; i++)
		wLaneColor[i] = allLightCycleColors[3][inTime][i];
}