//spencemw 12-1-16, replace bool with road class

#pragma once
#include "Intersection.h"	
#include "TransportMode.h"
#include "includes.h"
#include "Road.h"
//#include "RightLane.h"


class MapOBJ
{
private:

	// *** New items by Isaac
	//bool road1, road2;	// No access to the Road class at this point. This is just a way around this
	Road* road1;
	Road* road2;
	Intersection* inter;
	TransportMode* motor;
	// ***   


public:
	//Constructors
	MapOBJ();
	MapOBJ(Road aNewRoad);
	//MapOBJ(bool road);  //use if your laying road btwn intersections in the array spencemw 11-19-16
	~MapOBJ();

	virtual void interPush(MapOBJ* modes);
	virtual vector <MapOBJ*> interPop();

	//getters
	//bool getRoad1();
	//bool getRoad2(); 
	Road* getRoad();
	Intersection* getIntersection();
	TransportMode* getVehicle();
	

	//setters
	//void setRoad1(bool road1);
	//void setRoad2(bool road2);
	void setRoad(Road* road);
	void setIntersection(Intersection* inter);
	void setVehicle(TransportMode* motor);
	

};
