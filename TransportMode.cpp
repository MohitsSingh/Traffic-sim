#include "Includes.h"


TransportMode::TransportMode()
{
	minSpeed = 0;
	maxSpeed = 0;
	currentSpeed = 0;
	length = 0;
	width = 0;
	hazardRating = 0;
	latitude = 0.0;
	longitude = 0.0;
	direction = PI / 2;
	cout << "Default constructor for Transportation Mode called.\n";
}


TransportMode::~TransportMode()
{
}

//************************************************
//Getters
//************************************************

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
double TransportMode::getLatitude()
{
	return latitude;
}
double TransportMode::getLongitude()
{
	return longitude;
}
double TransportMode::getDirection()
{
	return direction;
}

//************************************************
//Setters
//************************************************

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
void TransportMode::setLatitude(double inputlatitude)
{
	latitude = inputlatitude;
}
void TransportMode::setLongitude(double inputLongitude)
{
	longitude = inputLongitude;
}
void TransportMode::setDirection(double inputDirection)
{
	direction = inputDirection;
}