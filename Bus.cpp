#include "Includes.h"

Bus::Bus()
{
#if TSIM_CONSTRUCTOR_OUTPUT == 1
	cout << "Default constructor for Bus called.\n";
#endif
	model = BUS;
	acceleration = 59;
	maxSpeed = 74;
	weight = 24000;
	length = 540;
	width = 100;
	oversized = true;
	emergencyVehicle = false;
	activeEmergency = false;
}

Bus::~Bus()
{

}