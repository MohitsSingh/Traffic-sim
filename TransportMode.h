#pragma once
//#include "Location.h"
#include "Includes.h"
class Location;

/***********************************************************************
Code for TransportMode and its subclasses by (in alphabetical order of first name): 
Adam Gunnell, Christine Sobolewski, Jack Grebb, Michael Ritter

Commented by: Michael Ritter, Jack Grebb, Adam Gunnell
Change Log Location: bottom of this file.
************************************************************************/


class TransportMode
{
protected:
	int minSpeed;				// minimum speed mode is allowed to go
	int maxSpeed;				// maximum speed mode can go (speed limit on current rode)
	double currentSpeed;			// the current speed of mode
	double xPos;				// meters eastward from southwest corner
	double yPos;				// meters northward from southwest corner
	double direction;			// radians east is zero
	
	int length;				// rounded to nearest meter
	int width;				// rounded to nearest meter
	int hazardRating;			// not being used at the moment
public:
	TransportMode();
	~TransportMode();

	//GETTERS
	int getMinSpeed();
	int getMaxSpeed();
	double getCurrentSpeed();
	double getX();
	double getY();
	double getDirection();

	int getLength();
	int getWidth();
	int getHazardRating();

	//SETTERS
	void setMinSpeed(int inputSpeed);
	void setMaxSpeed(int inputSpeed);
	void setCurrentSpeed(double inputSpeed);
	void setX(double inputX);
	void setY(double inputY);
	void setDirection(double inputDirection);

	void setLength(int inputLength);
	void setWidth(int inputWidth);
	void setHazardRating(int inputHazardRating);
};

