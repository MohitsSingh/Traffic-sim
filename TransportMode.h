#pragma once
#include "Includes.h"



class TransportMode : public MapOBJ
{
protected:
	int minSpeed;				//minimum speed the car is allowed to go
	int maxSpeed;				//maximum speed the car can go (speed limit on current rode)
	int length;					//not being used at the moment
	int width;					//not being used at the moment
	int hazardRating;			//not being used at the moment
	int weight;					
	double acceleration;		//current acceleration 
	double maxAcceleration;		//maximum acceleration
	double brakingPower;		//Vehicle spec of breaking power
	double currentSpeed;		//the current speed of vehicle
	double direction;			//radians: east is zero
	enum CARDINAL cardinalD;	//direction of car for simple cardinal directions
	

public:
	TransportMode();
	~TransportMode();
	TransportMode(int xStartCoordinate, int yStartCoordinate);

	//GETTERS
	int getLength();
	int getWidth();
	int getHazardRating();
	int getWeight();
	int getMinSpeed();
	int getMaxSpeed();
	double getCurrentSpeed();
	double getMaxAcceleration();
	double getbrakingPower();
	double getAcceleration();
	double getDirection();
	enum CARDINAL getCardinalD();
	

	//SETTERS
	void setLength(int inputLength);
	void setWidth(int inputWidth);
	void setWeight(int inputWeight);
	void setMinSpeed(int inputSpeed);
	void setMaxSpeed(int inputSpeed);
	void setCurrentSpeed(double inputSpeed);
	void setMaxAcceleration(double inputSpeed);
	void setbrakingPower(double inputbrakingPower);
	void setAcceleration(double inputAcceleration);
	void setCardinalD(enum CARDINAL inputCardinalD);
	void setDirection(double inputDirection);
	void setHazardRating(int inputHazardRating);

	void move(int distance, double direction)
	{
		xPos += distance * cos(direction);
		yPos += distance * sin(direction);
	}
	void update()
	{
		int distance;
		currentSpeed += acceleration * TIME_INCREMENT;
		distance = currentSpeed * TIME_INCREMENT;
		move(distance, direction);
	}
};

