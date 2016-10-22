#pragma once
#include "includes.h"


class MapOBJ
{
protected:

	
	int minSpeed;				//minimum speed the car is allowed to go
	int maxSpeed;				//maximum speed the car can go (speed limit on current rode)
	int xPos;					//x position of object
	int yPos;					//y position of object
	double currentSpeed;		//the current speed of vehicle
	double acceleration;		//current acceleration 
	double maxAcceleration;		//maximum acceleration
	double brakingPower;		//Vehicle spec of breaking power
	double latitude;			//vehicle position North/South: relates to the y axis
	double longitude;			//vehicle position East/West: relates to the x axis
	double direction;			//radians: east is zero
	enum CARDINAL cardinalD;	//direction of car for simple cardinal directions
	


	
	int hazardRating;			//not being used at the moment

public:
	

	
	//GETTERS
	virtual int getMinSpeed();
	virtual int getMaxSpeed();
	virtual int getHazardRating();
	virtual double getMaxAcceleration();
	virtual double getCurrentSpeed();
	virtual double getbrakingPower();
	virtual double getAcceleration();
	virtual double getDirection();
	virtual int getX();
	virtual int getY();
	virtual enum CARDINAL getCardinalD();
	
	

	//SETTERS
	virtual void setMaxAcceleration(double inputSpeed);
	virtual void setMinSpeed(int inputSpeed);
	virtual void setMaxSpeed(int inputSpeed);
	virtual void setCurrentSpeed(double inputSpeed);
	virtual void setbrakingPower(double inputbrakingPower);
	virtual void setHazardRating(int inputHazardRating);
	virtual void setAcceleration(double inputAcceleration);
	virtual void setDirection(double inputDirection);
	virtual void setX(int inputX);
	virtual void setY(int inputY);
	virtual void setCardinalD(enum CARDINAL inputCardinalD);
};
