#include "Car.h"


Car::Car(bool emergency)		//JG optional, defaults to false
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

	//JG police car specs (probably needs tweaking)
	if (emergency)
	{
		acceleration = 4.5;
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
