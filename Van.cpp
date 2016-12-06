#include "Van.h"

Van::Van(bool emergency) //JG bool input optional, set to false if default constructor called
{
#if TSIM_CONSTRUCTOR_OUTPUT == 1
	if (emergency)
	{
		cout << "\"Emergency\" constructor for Van called.\n";
	}
	else
		cout << "Default constructor for Van called.\n";
#endif

	// ambulance specs
	if (emergency)
	{
		acceleration = 5.5;  		// seconds to 97kph (or 60mph)
		maxSpeed = 164;			// kph
		weight = 4700;			// pounds
		length = 5;			// rounded meters
		width = 2;			// rounded meters
	}
	// normal van specs
	else
	{
		acceleration = 10.2;  		// seconds to 97kph (or 60mph)
		maxSpeed = 151;			// kph
		weight = 4700;			// pounds
		length = 5;			// rounded meters
		width = 2;			// rounded meters
	}

	model = VAN;
	oversized = false;
	activeEmergency = false;
	emergencyVehicle = emergency;
}


Van::~Van()
{
}
