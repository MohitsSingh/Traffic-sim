#pragma once
#include "includes.h"
#include "Intersection.h"	
#include "TransportMode.h"


class MapOBJ
{
private:

	// *** New items by Isaac
	bool road1, road2;	// No access to the Road class at this point. This is just a way around this
	Intersection* inter;
	TransportMode* motor;
	// ***   


public:

	//Constructors
	MapOBJ();


	bool getRoad1();
	bool getRoad2(); 
	Intersection* getIntersection();
	TransportMode* getVehicle();

	void setRoad1(bool road1);
	void setRoad2(bool road2);
	void setIntersection(Intersection* inter);
	void setVehicle(TransportMode* motor);

};