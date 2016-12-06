#include "Car.h"

Car::Car(bool emergency)		//JG bool input optional, defaults to false if default constructor called
{
	//JG: see includes.h
#if TSIM_CONSTRUCTOR_OUTPUT == 1
	if (emergency)
	{
		cout << "\"Emergency\" constructor for Car called.\n";
	}
	else
		cout << "Default constructor for Car called.\n";
#endif

	// police car specs
	if (emergency)
	{
		acceleration = 4.5;  	// seconds to 97kph (or 60mph)
		maxSpeed = 290;  	// kph
		weight = 4000;		// pounds
		length = 5;		// rounded meters
		width = 2;		// rounded meters
	}
	// normal car specs
	else
	{
		acceleration = 7.5;	// seconds to 97kph (or 60mph)
		maxSpeed = 240;		// kph
		weight = 4000;		// pounds
		length = 5;		// rounded meters
		width = 2;		// rounded meters
	}

	model = MIDSIZE;
	oversized = false;
	activeEmergency = false;
	emergencyVehicle = emergency;
}

Car::~Car()
{
}
