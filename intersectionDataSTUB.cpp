/*******************************************************************************************
This is a stub - Data team will produce the working version

spencemw  11/19/16  Simulates what the data team is doing

Their methods populate a local array on their side.  We will pass the array from main
to them, they will load our array in main with intersections.

************************************/

#include "intersectionDataSTUB.h"

intersectionData::intersectionData()
{
}

/****************************  STUB STUB STUB STUB STUB  *****************************

A function that makes 5 fake intersections
spencemw 11-19-16

***************************************************************************************/

void intersectionData::addIntersections(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])
{
	//map arrives as an array of nullptrs....

	//this is a stub that puts in 5 fake intersections for testing

	for (int i = 0; i < 5; i++)
	{
		int r[5] = { 25, 45, 25, 25, 5 };
		int c[5] = { 25, 25, 40, 10, 25 };
		
		//location for an intersection

		map[r[i]][c[i]] = new MapOBJ;				//add an instance of MapOBJ to the array		
		map[r[i]][c[i]]->setRoad1(true);			//has 1st road
		map[r[i]][c[i]]->setRoad2(true);			//has 2nd road making an intersection
		map[r[i]][c[i]]->setIntersection(new Intersection());		//add an instance of instersection

		//an intersection is 4 elements on the array (1 eastbound, 1 westbound, 1 northbound, 1 southbound)

		map[r[i] + 1][c[i]] = new MapOBJ;				//add an instance of MapOBJ to the array		
		map[r[i] + 1][c[i]]->setRoad1(true);			//has 1st road
		map[r[i] + 1][c[i]]->setRoad2(true);			//has 2nd road making an intersection
		map[r[i] + 1][c[i]]->setIntersection(new Intersection());		//add an instance of instersection

		map[r[i]][c[i] + 1] = new MapOBJ;				//add an instance of MapOBJ to the array		
		map[r[i]][c[i] + 1]->setRoad1(true);			//has 1st road
		map[r[i]][c[i] + 1]->setRoad2(true);			//has 2nd road making an intersection
		map[r[i]][c[i] + 1]->setIntersection(new Intersection());		//add an instance of instersection

		map[r[i] + 1][c[i] + 1] = new MapOBJ;				//add an instance of MapOBJ to the array		
		map[r[i] + 1][c[i] + 1]->setRoad1(true);			//has 1st road
		map[r[i] + 1][c[i] + 1]->setRoad2(true);			//has 2nd road making an intersection
		map[r[i] + 1][c[i] + 1]->setIntersection(new Intersection());		//add an instance of instersection
	}
}



intersectionData::~intersectionData()
{
}
