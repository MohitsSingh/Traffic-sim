#include "Van.h"


Van::Van()
{
	cout << "Default constructor for Van called.\n";

	setAcceleration(10.2);
	setMaxSpeed(94);
	setWeight(4700);
	setLength(200); // inches
	setWidth(80); // inches
	setOversized(false);
}

Van::Van(bool emergency) // ambulance constructor
{
	cout << "\"Emergency\" constructor for Van called.\n";

	setAcceleration(5.5);
	setMaxSpeed(100);
	setWeight(4700);
	setLength(180); // inches
	setWidth(80); // inches
	setOversized(false);
	setEmergencyVehicle(((emergency = true) ? true : false));
}


Van::~Van()
{
}
