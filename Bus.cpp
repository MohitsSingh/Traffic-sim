#include "Includes.h"

Bus::Bus()
{
#if TSIM_CONSTRUCTOR_OUTPUT == 1
	cout << "Default constructor for Bus called.\n";
#endif
	model = BUS;
	acceleration = 59;  // Time in seconds vehicle takes to reach 97 kph (or 60 mph)
	maxSpeed = 119;     // maximum speed in kph
	weight = 24000;
	length = 14;  // in meters
	width = 3;    // in meters
	oversized = true;
	emergencyVehicle = false;
	activeEmergency = false;
}

Bus::~Bus()
{

}

//Constructor where you can set the x and y values.
Bus::Bus(double x, double y)

{

	model = BUS;
	acceleration = 59;  // Time in seconds vehicle takes to reach 97 kph (or 60 mph)
	maxSpeed = 119;     // maximum speed in kph
	weight = 24000;
	length = 14;  // in meters
	width = 3;    // in meters
	oversized = true;
	emergencyVehicle = false;
	activeEmergency = false;

	setX(x);
	setY(y);

}
