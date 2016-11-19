/*******************************************************************************************
This is a stub

spencemw   11/19/16  Simulates what the data team is doing

Their methods populate a local array on their side.  We will pass the array from main 
to them, they will load our array in main with intersections.   

************************************/

#pragma once
#include "Includes.h"
#include "MapOBJ.h"
#include "Intersection.h"

class intersectionData
{
public:
	intersectionData();
	~intersectionData();

	static void addIntersections(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X]);
	//static allows you to use this method without creating an instance back in main
};

