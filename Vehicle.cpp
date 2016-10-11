//#pragma once
#include "Includes.h"

//constructers
Vehicle::Vehicle()
{
	Location(spot);
	traction = 0;
	weight = 0;
	brakingPower = 0;
	acceleration = 0.0;
	oversized = false;
	emergencyVehicle = false;
	cout << "Default constructor for Vehicle called.\n";
}

//operator overloads
ostream &operator<<(ostream &output, Vehicle inputVehicle)
{
	output << "Model:\t\t\t" << inputVehicle.getModel() << endl;
	output << "Latitude:\t\t" << inputVehicle.getLatitude() << endl;
	output << "Longitude:\t\t" << inputVehicle.getLongitude() << endl;
	output << "Current Speed:\t\t" << inputVehicle.getCurrentSpeed() << endl;
	//output << "Acceleration:\t\t" << inputVechicle.getAcceleration() << endl;
	output << "Maximum Speed:\t\t" << inputVehicle.getMaxSpeed() << endl;
	output << "Weight:\t\t\t" << inputVehicle.getWeight() << endl;
	output << "Length:\t\t\t" << inputVehicle.getLength() << endl; 
	output << "Width:\t\t\t" << inputVehicle.getWidth() << endl; 
	output << "Oversized:\t\t" << ((inputVehicle.getOversized()) == 1 ? "True":"False")  << endl;
	output << "Emergency Vehicle:\t" << ((inputVehicle.getEmergencyVehicle()) == 1 ? "True" : "False") << endl;
	output << endl << endl;
	return output;
}
Vehicle Vehicle::operator++()
{
	setCurrentSpeed(getCurrentSpeed() + acceleration / 3600); //why / by 3600 are we not storing acceleration in seconds?
	setLongitude(getLongitude() + 0.001);
	return *this;
}

//************************************************
//Getters
//************************************************
CARTYPES Vehicle::getModel()
{
	return MIDSIZE;
	//return vehicleModel;
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

//************************************************
//Setters
//************************************************
void Vehicle::setMaxAcceleration(double inputSpeed)
{
	maxAcceleration = inputSpeed;
}
void Vehicle::setModel(CARTYPES inputModel)
{
	//vehicleModel = inputModel;
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

//**************************************
//Test functions
//**************************************
void Vehicle::applyAcceleration(double time)
{
	//d(t) = 0.5at^2 + vt + k

	double distance;

	distance = 0.5 * acceleration * time * time + getCurrentSpeed() * time;
	setCurrentSpeed(getCurrentSpeed() + acceleration * time);
}
