#include "Includes.h"


//getters
double MapOBJ::getMaxAcceleration()
{
	return maxAcceleration;
}
double MapOBJ::getbrakingPower()
{
	return brakingPower;
}
double MapOBJ::getAcceleration()
{
	return acceleration;
}
int MapOBJ::getMinSpeed()
{
	return minSpeed;
}
int MapOBJ::getMaxSpeed()
{
	return maxSpeed;
}
double MapOBJ::getCurrentSpeed()
{
	return currentSpeed;
}
int MapOBJ::getX()
{
	return xPos;
}
int MapOBJ::getY()
{
	return yPos;
}
double MapOBJ::getDirection()
{
	return direction;
}
int MapOBJ::getHazardRating()
{
	return hazardRating;
}

//setters
void MapOBJ::setbrakingPower(double inputbrakingPower)
{
	brakingPower = inputbrakingPower;
}
void MapOBJ::setAcceleration(double inputAcceleration)
{
	acceleration = inputAcceleration;
}
void MapOBJ::setMaxAcceleration(double inputSpeed)
{
	maxAcceleration = inputSpeed;
}
void MapOBJ::setMinSpeed(int inputSpeed)
{
	minSpeed = inputSpeed;
}
void MapOBJ::setMaxSpeed(int inputSpeed)
{
	maxSpeed = inputSpeed;
}
void MapOBJ::setCurrentSpeed(double inputSpeed)
{
	currentSpeed = inputSpeed;
}
void MapOBJ::setX(int inputX)
{
	xPos = inputX;
}
void MapOBJ::setY(int inputY)
{
	yPos = inputY;
}
void MapOBJ::setDirection(double inputDirection)
{
	direction = inputDirection;
}
void MapOBJ::setHazardRating(int inputHazardRating)
{
	hazardRating = inputHazardRating;
}