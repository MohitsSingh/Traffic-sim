#pragma once
#include "Car.h"

Car::Car(bool emergency)		//JG bool input optional, defaults to false if default constructor called
{
	//JG police car specs (probably needs tweaking)
	if (emergency)
	{
		acceleration = 4.5;  // seconds to 60mph
		maxSpeed = 180;
		weight = 4000;
		length = 200;			//inches
		width = 85;				//inches
	}
	//JG normal car specs
	else
	{
		acceleration = 7.5;
		maxSpeed = 150;
		weight = 4000;
		length = 200;			//inches
		width = 85;				//inches
	}
	model = MIDSIZE;
	oversized = false;
	activeEmergency = false;
	emergencyVehicle = emergency;
}

Car::~Car()
{
}
