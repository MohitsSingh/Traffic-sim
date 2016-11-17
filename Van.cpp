#include "Van.h"

Van::Van(bool emergency) //JG bool input optional, set to false if default constructor called
{
	//JG ambulance specs
	if (emergency)
	{
		acceleration = 5.5;  // seconds to 60 mph
		maxSpeed = 100;
		weight = 4700;
		length = 180;			//inches
		width = 80;				//inches
	}
	//JG normal van specs
	else
	{
		acceleration = 10.2;
		maxSpeed = 94;
		weight = 4700;
		length = 200;			//inches
		width = 80;				//inches
	}
	model = VAN;
	oversized = false;
	activeEmergency = false;
	emergencyVehicle = emergency;
}


Van::~Van()
{
}
