#include "Truck.h"


Truck::Truck()
{
	cout << "Default constructor for Truck called.\n";

	setAcceleration(8.4);  //units?
	setMaxSpeed(90);   //units?
	setWeight(5200);   //units?
	setLength(6); // meters
	setWidth(2); // meters
	setOversized(false);
}

Truck::Truck(bool emergency) // Fire Truck constructor
{
	cout << "\"Emergency\" constructor for Truck called.\n";

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
