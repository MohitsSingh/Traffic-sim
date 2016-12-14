//Christine Sobolewski, Adam Gunnell, Jack Grebb
#pragma once
#include "Truck.h"

//Christine Sobolewski
Truck::Truck()
{
	setAcceleration(8.4);  //units?
	setMaxSpeed(90);   //units?
	setWeight(5200);   //units?
	setLength(6); // meters
	setWidth(2); // meters
	setOversized(false);
}

Truck::Truck(bool emergency) // Fire Truck constructor
{
	setAcceleration(8.4);  //units?
	setMaxSpeed(100);  //units?
	setWeight(5200);  //units?
	setLength(10); // meters
	setWidth(2); // meters
	setOversized(false);
	setEmergencyVehicle(((emergency = true) ? true : false));
}

Truck::~Truck()
{
}
