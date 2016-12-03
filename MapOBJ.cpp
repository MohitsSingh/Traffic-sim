/*******************************************************************************************
This object will fill the array in main
spencemw   12/2/16 
	- Added the Road class, removed the bools for road1 and road2.  
	
************************************/

#include "Includes.h"
#include "MapOBJ.h"



MapOBJ::MapOBJ()
{
	road1 = nullptr;
	road2 = nullptr;
	inter = nullptr;
	motor = nullptr;
}

//MapOBJ::MapOBJ(bool road)  //use if your laying road btwn intersections in the array spencemw 11-19-16
//{
//	road1 = road;
//	road2 = false;
//	inter = nullptr;
//	motor = nullptr;
//}

MapOBJ::MapOBJ(Road aNewRoad)  //uses the road class
{
	road1 = &aNewRoad;
	road2 = nullptr;
	inter = nullptr;
	motor = nullptr;
}

MapOBJ::~MapOBJ()
{

}



void MapOBJ::interPush(MapOBJ* modes)
{

}
vector <MapOBJ*> MapOBJ::interPop()
{
	vector <MapOBJ*> empty;
	return empty;
}


//	GETTERS

Road* MapOBJ::getRoad()
{
	return road1;
}


//bool MapOBJ::getRoad1()
//{
//	return road1;
//}
//bool MapOBJ::getRoad2()
//{
//	return road2;
//}
Intersection* MapOBJ::getIntersection()
{
	return inter;
}
TransportMode* MapOBJ::getVehicle()
{
	return motor;
}


//	SETTERS

void MapOBJ::setRoad(Road* road)
{
	this->road1 = road;
}

//void MapOBJ::setRoad1(bool road1)
//{
//	this->road1 = road1;
//}
//void MapOBJ::setRoad2(bool road2)
//{
//	this->road2 = road2;
//}
void MapOBJ::setIntersection(Intersection* inter)
{
	this->inter = inter;
}
void MapOBJ::setVehicle(TransportMode* motor)
{
	this->motor = motor;
}

