#include "Includes.h"


TransportMode::TransportMode()
{
	//JG: See includes.h
#if TSIM_CONSTRUCTOR_OUTPUT == 1
	cout << "Default constructor for Transportation Mode called.\n";
#endif
	minSpeed = 0;
	maxSpeed = 0;
	currentSpeed = 0;
	length = 0;
	width = 0;
	hazardRating = 0;
	xPos = 0.0;
	yPos = 0.0;
	direction = PI / 2;
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
double TransportMode::getX()
{
	return xPos;
}
double TransportMode::getY()
{
	return yPos;
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
void TransportMode::setX(double inputX)
{
	xPos = inputX;
}
void TransportMode::setY(double inputY)
{
	yPos = inputY;
}
void TransportMode::setDirection(double inputDirection)
{
	direction = inputDirection;
}