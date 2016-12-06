#include "Truck.h"


Truck::Truck()
{
	cout << "Default constructor for Truck called.\n";

	setAcceleration(8.4);		// seconds to 97kph (or 60mph)
	setMaxSpeed(145);   		// kph
	setWeight(5200);   		// pounds
	setLength(6); 			// meters
	setWidth(2); 			// meters
	setOversized(false);
}

Truck::Truck(bool emergency) // Fire Truck constructor
{
	cout << "\"Emergency\" constructor for Truck called.\n";

	setAcceleration(8.4);  		// seconds to 97kph (or 60mph)
	setMaxSpeed(161);  		// kph
	setWeight(5200);  		// pounds
	setLength(10); 			// meters
	setWidth(2); 			// meters
	setOversized(false);
	setEmergencyVehicle(((emergency = true) ? true : false));
}

Truck::~Truck()
{
}

Truck::Truck(double x, double y, bool emergency)
{
	cout << "Default constructor for Truck called.\n";

	setAcceleration(8.4);		// seconds to 97kph (or 60mph)
	setMaxSpeed(145);   		// kph
	setWeight(5200);   		// pounds
	setLength(6); 			// meters
	setWidth(2); 			// meters
	setOversized(false);
	setEmergencyVehicle(((emergency = true) ? true : false));

	setX(x);
	setY(y);
}
