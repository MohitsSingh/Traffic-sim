#include "Includes.h"
#include "TransportMode.h"


TransportMode::TransportMode()
{
	minSpeed = 0;
	maxSpeed = 0;
	currentSpeed = 0;
	length = 0;
	width = 0;
	hazardRating = 0;
	xPos = 0.0;
	yPos = 0.0;
	direction = PI / 2;
	id++;
}

TransportMode::TransportMode(int xStartCoordinate, int yStartCoordinate)
{
	xPos = xStartCoordinate;
	yPos = yStartCoordinate;
	minSpeed = 0;
	maxSpeed = 0;
	currentSpeed = 0;
	weight = 0;
	brakingPower = 0;
	length = 0;
	width = 0;
	hazardRating = 0;
	/*latitude = 0.0;
	longitude = 0.0;*/
	acceleration = 0.0;
	direction = 0;
	id++;
}

TransportMode::~TransportMode()
{
}

//************************************************
//Getters
//************************************************
int TransportMode::getX()
{
	return xPos;
}
int TransportMode::getY()
{
	return yPos;
}
int TransportMode::getMinSpeed()
{
	return minSpeed;
}
int TransportMode::getMaxSpeed()
{
	return maxSpeed;
}
double TransportMode::getCurrentSpeed()
{
	return currentSpeed;
}
double TransportMode::getMaxAcceleration()
{
	return maxAcceleration;
}
double TransportMode::getbrakingPower()
{
	return brakingPower;
}
double TransportMode::getAcceleration()
{
	return acceleration;
}
double TransportMode::getDirection()
{
	return direction;
}
enum CARDINAL TransportMode::getCardinalD()
{
	return cardinalD;
}
CARDINAL TransportMode::getDesieredD()
{
	return desiredD;
}
int TransportMode::getLength()
{
	return length;
}
int TransportMode::getWidth()
{
	return width;
}
int TransportMode::getHazardRating()
{
	return hazardRating;
}
int TransportMode::getWeight()
{
	return weight;
}
int TransportMode::getId()
{
	return id;
}


//************************************************
//Setters
//************************************************
void TransportMode::setLength(int inputLength)
{
	length = inputLength;
}
void TransportMode::setWidth(int inputWidth)
{
	width = inputWidth;
}
void TransportMode::setHazardRating(int inputHazardRating)
{
	hazardRating = inputHazardRating;
}
void TransportMode::setWeight(int inputWeight)
{
	weight = inputWeight;
}
void TransportMode::setMinSpeed(int inputSpeed)
{
	minSpeed = inputSpeed;
}
void TransportMode::setMaxSpeed(int inputSpeed)
{
	maxSpeed = inputSpeed;
}
void TransportMode::setCurrentSpeed(double inputSpeed)
{
	currentSpeed = inputSpeed;
}
void TransportMode::setMaxAcceleration(double inputSpeed)
{
	maxAcceleration = inputSpeed;
}
void TransportMode::setbrakingPower(double inputbrakingPower)
{
	brakingPower = inputbrakingPower;
}
void TransportMode::setAcceleration(double inputAcceleration)
{
	acceleration = inputAcceleration;
}
void TransportMode::setCardinalD(enum CARDINAL inputCardinalD)
{
	cardinalD = inputCardinalD;
}
void TransportMode::setDesieredD(CARDINAL value)
{
	desiredD = value;
}
void TransportMode::setDirection(double inputDirection)
{
	direction = inputDirection;
}