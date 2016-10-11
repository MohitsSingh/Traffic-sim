#include "Includes.h"

Sportscar::Sportscar()
{
#if TSIM_CONSTRUCTOR_OUTPUT == 1
	cout << "Default constructor for Sportscar called.\n";
#endif
	model = SPORT;
	acceleration = 3.1;
	maxSpeed = 217;
	weight = 4100;
	length = 190;
	width = 80;	
	oversized = false;
	emergencyVehicle = false;		//a man can dream
	activeEmergency = false;
}

Sportscar::~Sportscar()
{

}