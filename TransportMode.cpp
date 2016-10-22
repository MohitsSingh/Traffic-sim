#include "Includes.h"


TransportMode::TransportMode()
{
	minSpeed = 0;
	maxSpeed = 0;
	currentSpeed = 0;
	length = 0;
	width = 0;
	hazardRating = 0;
	xPos = 0;
	yPos = 0;
	direction = PI / 2;
}

TransportMode::TransportMode(int xStartCoordinate, int yStartCoordinate)
{
	xPos = xStartCoordinate;
	yPos = yStartCoordinate;
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
	direction = 0;

}

TransportMode::~TransportMode()
{
}

//************************************************
//Getters
//************************************************
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
int TransportMode::getTraction()
{
	return traction;
}
bool TransportMode::getOversized()
{
	return oversized;
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
void TransportMode::setTraction(int inputTraction)
{
	traction = inputTraction;
}
void TransportMode::setOversized(bool inputOversized)
{
	oversized = inputOversized;
}

