//#pragma once
#include "Includes.h"


//constructers
Vehicle::Vehicle()
{
	TransportMode();
	model = UNDEFINED;		
	traction = 0;
	oversized = false;
	activeEmergency = false;
	emergencyVehicle = false;
}

Vehicle::Vehicle(int inputX, int inputY)
{
	TransportMode(inputX, inputY);
	model = CARTYPES::UNDEFINED;
	emergencyVehicle = false;
	activeEmergency = false;
	oversized = false;
	traction = 0;
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


//************************************************
//Getters
//************************************************
CARTYPES Vehicle::getModel()
{
	return model;
}
bool Vehicle::getEmergencyVehicle()
{
	return emergencyVehicle;
}
bool Vehicle::isActiveEmergency()		//JG
{
	return activeEmergency;
}
int Vehicle::getTraction()
{
	return traction;
}
bool Vehicle::getOversized()
{
	return oversized;
}

//************************************************
//Setters
//************************************************

void Vehicle::setModel(CARTYPES inputModel)
{
	model = inputModel;
}
void Vehicle::setEmergencyVehicle(bool inputEmergencyVehicle)
{
	emergencyVehicle = inputEmergencyVehicle;
}
void Vehicle::setActiveEmergency(bool input)		//JG
{
	activeEmergency = input;  //AG All vehicles react to active emergency
}
void Vehicle::setTraction(int inputTraction)
{
	traction = inputTraction;
}
void Vehicle::setOversized(bool inputOversized)
{
	oversized = inputOversized;
}
