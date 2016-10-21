#pragma once
#include "includes.h"


class MapOBJ
{
protected:
	int xPos;					//x position of object
	int yPos;					//y position of object
	double latitude;			//vehicle position North/South: relates to the y axis
	double longitude;			//vehicle position East/West: relates to the x axis

public:

	//Constructors
	MapOBJ();
	MapOBJ(int xStartCoordinate, int yStartCoordinate);

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
	virtual int getLength();
	virtual int getWidth();
	virtual int getWeight();
	virtual int getTraction();
	
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
	virtual void setLength(int inputLength);
	virtual void setWidth(int inputWidth);
	virtual void setTraction(int inputTraction);
	virtual void setOversized(bool inputOversized);
};
