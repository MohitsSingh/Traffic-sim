#pragma once
#include "Includes.h"

//constructers
Vehicle::Vehicle()
{
	minSpeed = 0;
	maxSpeed = 0;
	currentSpeed = 0;
	traction = 0;
	weight = 0;
	brakingPower = 0;
	length = 0;
	width = 0;
	hazardRating = 0;
	latitude = 0.0;
	longitude = 0.0;
	acceleration = 0.0;
	oversized = false;
	emergencyVehicle = false;
	direction = PI / 2;
}
Vehicle::Vehicle(enum CARTYPES inputCARTYPE)
{
	switch (inputCARTYPE)
	{
	case MIDSIZE:
		//** FILL ME
		break;
	case SEMI:
		break;
	case TRUCK:
		break;
	case SPORTSCAR:
		break;
	default:
		minSpeed = 0;
		maxSpeed = 0;
		currentSpeed = 0;
		traction = 0;
		weight = 0;
		brakingPower = 0;
		length = 0;
		width = 0;
		hazardRating = 0;
		latitude = 0.0;
		longitude = 0.0;
		acceleration = 0.0;
		oversized = false;
		emergencyVehicle = false;
		direction = PI / 2;
		break;
	}
}

//operator overloads
ostream &operator<<(ostream &output, Vehicle inputVehicle)
{
	output << "Model:\t\t" << inputVehicle.getModel() << endl;
	output << "Latitude:\t" << inputVehicle.getlatitude() << endl;
	output << "Longitude:\t" << inputVehicle.getLongitude() << endl;
	output << "Current Speed:\t" << inputVehicle.getCurrentSpeed() << endl;
	output << endl << endl;
	return output;
}
Vehicle Vehicle::operator++()
{
	currentSpeed = currentSpeed + acceleration / 3600; //why / by 3600 are we not storing acceleration in seconds?
	longitude += 0.001;
	return *this;
}

//************************************************
//Getters
//************************************************
CARTYPES Vehicle::getModel()
{
	return vehicleModel;
}
double Vehicle::getDirection()
{
	return direction;
}
double Vehicle::getMaxAcceleration()
{
	return maxAcceleration;
}
int Vehicle::getMinSpeed()
{
	return minSpeed;
}
int Vehicle::getMaxSpeed()
{
	return maxSpeed;
}
double Vehicle::getCurrentSpeed()
{
	return currentSpeed;
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
int Vehicle::getLength()
{
	return length;
}
int Vehicle::getWidth()
{
	return width;
}
int Vehicle::getHazardRating()
{
	return hazardRating;
}
double Vehicle::getlatitude()
{
	return latitude;
}
double Vehicle::getLongitude()
{
	return longitude;
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
void Vehicle::setDirection(double inputDirection)
{
	direction = inputDirection;
}
void Vehicle::setModel(CARTYPES inputModel)
{
	vehicleModel = inputModel;
}
void Vehicle::setMinSpeed(int inputSpeed)
{
	minSpeed = inputSpeed;
}
void Vehicle::setMaxSpeed(int inputSpeed)
{
	maxSpeed = inputSpeed;
}
void Vehicle::setCurrentSpeed(double inputSpeed)
{
	currentSpeed = inputSpeed;
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
void Vehicle::setLength(int inputLength)
{
	length = inputLength;
}
void Vehicle::setWidth(int inputWidth)
{
	width = inputWidth;
}
void Vehicle::setHazardRating(int inputHazardRating)
{
	hazardRating = inputHazardRating;
}
void Vehicle::setlatitude(double inputlatitude)
{
	latitude = inputlatitude;
}
void Vehicle::setLongitude(double inputLongitude)
{
	longitude = inputLongitude;
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

	distance = 0.5 * acceleration * time * time + currentSpeed * time;
	currentSpeed += acceleration * time;
}
