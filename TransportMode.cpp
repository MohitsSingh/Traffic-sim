#include "Includes.h"
// comments by Adam Gunnell, Jack Grebb

TransportMode::TransportMode()
{
	//JG: See includes.h
#if TSIM_CONSTRUCTOR_OUTPUT == 1
	cout << "Default constructor for Transportation Mode called.\n";
#endif
	minSpeed = 0;			// Kilometers per hour
	maxSpeed = 0;			// kph
	currentSpeed = 0;		// kph
	length = 0;			// rounded meters
	width = 0;			// rounded meters
	hazardRating = 0;
	xPos = 0.0;			// location on grid (x-axis)
	yPos = 0.0;			// location on grid (y-axis)
	direction = PI / 2;		// direction with defaut setting of pi/2 radians (90 degrees) 
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
