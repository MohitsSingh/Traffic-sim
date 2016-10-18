//#pragma once
#include "Includes.h"

//constructers
Vehicle::Vehicle()
{
	//JG see Includes.h

	model = UNDEFINED;		//JG
	traction = 0;
	weight = 0;
	brakingPower = 0;
	acceleration = 0.0;
	oversized = false;
	activeEmergency = false;
	emergencyVehicle = false;
}

//operator overloads
ostream &operator<<(ostream &output, Vehicle inputVehicle)
{
	output << "Model:\t\t\t" << inputVehicle.getModel() << endl;		//JG will output an int from the enum, but das ist ok
	output << "X Position:\t\t" << inputVehicle.getX() << endl;
	output << "Y Position:\t\t" << inputVehicle.getY() << endl;
	output << "Current Speed:\t\t" << inputVehicle.getCurrentSpeed() << endl;
	output << "Acceleration:\t\t" << inputVehicle.getAcceleration() << endl;
	output << "Maximum Speed:\t\t" << inputVehicle.getMaxSpeed() << endl;
	output << "Weight:\t\t\t" << inputVehicle.getWeight() << endl;
	output << "Length:\t\t\t" << inputVehicle.getLength() << endl; 
	output << "Width:\t\t\t" << inputVehicle.getWidth() << endl; 
	output << "Oversized:\t\t" << ((inputVehicle.getOversized()) == 1 ? "True":"False")  << endl;
	output << "Emergency Vehicle:\t" << ((inputVehicle.getEmergencyVehicle()) == 1 ? "True" : "False") << endl;
	output << endl << endl;
	return output;
}
/*	JG: in-class example, not going to be used
Vehicle Vehicle::operator++()
{
	setCurrentSpeed(getCurrentSpeed() + acceleration / 3600); //why / by 3600 are we not storing acceleration in seconds?
	setLongitude(getLongitude() + 0.001);
	return *this;
}
*/

//************************************************
//Getters
//************************************************
//JG: compiler issues resolved
CARTYPES Vehicle::getModel()
{
	return model;
}
double Vehicle::getMaxAcceleration()
{
	return maxAcceleration;
}
int Vehicle::getTraction()
{
	return traction;
}
int Vehicle::getWeight()
{
	return weight;
}
double Vehicle::getbrakingPower()
{
	return brakingPower;
}
double Vehicle::getAcceleration()
{
	return acceleration;
}
bool Vehicle::getOversized()
{
	return oversized;
}
bool Vehicle::getEmergencyVehicle()
{
	return emergencyVehicle;
}
bool Vehicle::isActiveEmergency()		//JG
{
	return activeEmergency;
}

//************************************************
//Setters
//************************************************
void Vehicle::setMaxAcceleration(double inputSpeed)
{
	maxAcceleration = inputSpeed;
}
//JG: compiler issues resolved
void Vehicle::setModel(CARTYPES inputModel)
{
	model = inputModel;
}
void Vehicle::setTraction(int inputTraction)
{
	traction = inputTraction;
}
void Vehicle::setWeight(int inputWeight)
{
	weight = inputWeight;
}
void Vehicle::setbrakingPower(double inputbrakingPower)
{
	brakingPower = inputbrakingPower;
}
void Vehicle::setAcceleration(double inputAcceleration)
{
	acceleration = inputAcceleration;
}
void Vehicle::setOversized(bool inputOversized)
{
	oversized = inputOversized;
}

void Vehicle::setEmergencyVehicle(bool inputEmergencyVehicle)
{
	emergencyVehicle = inputEmergencyVehicle;
}
void Vehicle::setActiveEmergency(bool input)		//JG
{
	activeEmergency = input;  //AG All vehicles react to active emergency
}

//**************************************
//Test functions
//**************************************
void Vehicle::applyAcceleration(double time)
{
	//d(t) = 0.5at^2 + vt + k

	double distance;

	distance = 0.5 * acceleration * time * time + currentSpeed * time;
	xPos += distance * cos(direction);
	yPos += distance * sin(direction);

	if (xPos < 0)
		xPos = 0;
	if (yPos < 0)
		yPos = 0;

	currentSpeed += acceleration * time;
}
