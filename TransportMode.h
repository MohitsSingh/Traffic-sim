#pragma once
//#include "Location.h"
#include "Includes.h"
class Location;

/***********************************************************************
Commented by: Michael Ritter
Change Log Location: bottom of this file.
************************************************************************/


class TransportMode
{
private:
	Location spot();            /*where on x y grid*/
	int minSpeed;				//minimum speed mode is allowed to go
	int maxSpeed;				//maximum speed mode can go (speed limit on current rode)
	double currentSpeed;		//the current speed of mode
	double latitude;			//vehicle position
	double longitude;			//vehicle position
	double direction;			//radians east is zero
	
	int length;					//not being used at the moment
	int width;					//not being used at the moment
	int hazardRating;			//not being used at the moment
public:
	TransportMode();
	~TransportMode();

	//GETTERS
	int getMinSpeed();
	int getMaxSpeed();
	double getCurrentSpeed();
	double getLatitude();
	double getLongitude();
	double getDirection();

	int getLength();
	int getWidth();
	int getHazardRating();

	//SETTERS
	void setMinSpeed(int inputSpeed);
	void setMaxSpeed(int inputSpeed);
	void setCurrentSpeed(double inputSpeed);
	void setLatitude(double inputlatitude);
	void setLongitude(double inputLongitude);
	void setDirection(double inputDirection);

	void setLength(int inputLength);
	void setWidth(int inputWidth);
	void setHazardRating(int inputHazardRating);
};

