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
	virtual int getX();
	virtual int getY();
	virtual int getLength();
	virtual int getWidth();
	virtual int getWeight();
	virtual int getTraction();
	virtual int getHazardRating();
	virtual double getMaxAcceleration();
	virtual double getAcceleration();
	virtual double getbrakingPower();
	virtual double getCurrentSpeed();
	virtual double getDirection();
	virtual double getLatitude();
	virtual double getLongitude();
	virtual bool getEmergencyVehicle();
	virtual bool isActiveEmergency();			
	virtual bool getOversized();
	virtual CARTYPES getModel();
	virtual CARDINAL getCardinalD();
	
	//SETTERS
	virtual void setMinSpeed(int inputSpeed);
	virtual void setMaxSpeed(int inputSpeed);
	virtual void setX(int inputX);
	virtual void setY(int inputY);
	virtual void setLength(int inputLength);
	virtual void setWidth(int inputWidth);
	virtual void setWeight(int input);
	virtual void setTraction(int inputTraction);
	virtual void setHazardRating(int inputHazardRating);
	virtual void setMaxAcceleration(double inputSpeed);
	virtual void setAcceleration(double inputAcceleration);
	virtual void setbrakingPower(double inputbrakingPower);
	virtual void setCurrentSpeed(double inputSpeed);
	virtual void setDirection(double inputDirection);
	virtual void setLatitude(double input);
	virtual void setLongitude(double input);
	virtual void setEmergencyVehicle(bool inputEmergencyVehicle);
	virtual void setActiveEmergency(bool);			
	virtual void setOversized(bool inputOversized);
	virtual void setModel(CARTYPES inputModel);
	virtual void setCardinalD(CARDINAL inputCardinalD);
};
