#include "Van.h"

Van::Van()
{
	cout << "Default constructor for Van called.\n";

	acceleration = 10.2;
	maxSpeed = 94;
	weight = 4700;
	length = 200;			//inches
	width = 80;				//inches
	setOversized(false);
	oversized = false;
	model = VAN;
	activeEmergency = false;
}
Van::Van(bool emergency) //JG optional, defaults to false
{
#if TSIM_CONSTRUCTOR_OUTPUT == 1
	if (emergency)
	{
		cout << "\"Emergency\" constructor for Van called.\n";
	}
	else
		cout << "Default constructor for Van called.\n";
#endif

	//JG ambulance specs
	if (emergency)
	{
		acceleration = 5.5;
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
