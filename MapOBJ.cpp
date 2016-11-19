#include "Includes.h"
#include "MapOBJ.h"



MapOBJ::MapOBJ()
{

	road1 = false;
	road2 = false;
	inter = nullptr;
	motor = nullptr;

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

bool MapOBJ::getRoad1()
{
	return road1;
}
bool MapOBJ::getRoad2()
{
	return road2;
}
Intersection* MapOBJ::getIntersection()
{
	return inter;
}
Vehicle* MapOBJ::getVehicle()
{
	return motor;
}


//	SETTERS

void MapOBJ::setRoad1(bool road1)
{
	this->road1 = road1;
}
void MapOBJ::setRoad2(bool road2)
{
	this->road2 = road2;
}
void MapOBJ::setIntersection(Intersection* inter)
{
	this->inter = inter;
}
void MapOBJ::setVehicle(Vehicle* motor)
{
	this->motor = motor;
}