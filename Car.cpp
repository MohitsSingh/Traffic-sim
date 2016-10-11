#include "Car.h"


Car::Car()
{
	cout << "Default constructor for Car called.\n";
	
	setAcceleration(7.5); 
	setMaxSpeed(150); 
	setWeight(4000);
	setLength(200); // inches
	setWidth(85); // inches
	setOversized(false);
}

Car::Car(bool emergency) // Police car constructor
{
	cout << "\"Emergency\" constructor for Car called.\n";

	setAcceleration(4.5);
	setMaxSpeed(180);
	setWeight(4000);
	setLength(200); // inches
	setWidth(85); // inches
	setOversized(false);
	setEmergencyVehicle(((emergency = true) ? true:false));
}

Car::~Car()
{
}
