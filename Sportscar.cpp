#include "Includes.h"

Sportscar::Sportscar()
{
#if TSIM_CONSTRUCTOR_OUTPUT == 1
	cout << "Default constructor for Sportscar called.\n";
#endif
	model = SPORT;
	acceleration = 3.1;			// seconds to 97kph
	maxSpeed = 249;				// kph
	weight = 4100;				// pounds
	length = 5;				// rounded meters
	width = 2;				// rounded meters
	oversized = false;
	emergencyVehicle = false;		//a man can dream
	activeEmergency = false;
}

Sportscar::~Sportscar()
{

}
