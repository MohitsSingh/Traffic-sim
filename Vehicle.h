#pragma once
#include "Includes.h"
/***********************************************************************
Commented by: Michael Ritter
Change Log Location: bottom of this file.
************************************************************************/

class Vehicle
{
private:
	enum CARTYPES vehicleModel;  //enum, FOUND IN: Inclueds.h
	int minSpeed;				//minimum speed the car is allowed to go
	int maxSpeed;				//maximum speed the car can go (speed limit on current rode)
	double currentSpeed;		//the current speed of vehicle
	double acceleration;		//current acceleration 
	double maxAcceleration;	//current acceleration
	double brakingPower;		//Vehicle spec of breaking power
	double latitude;			//vehicle position
	double longitude;			//vehicle position
	double direction;			//radians east is zero
	

	bool oversized;			//not being used at the moment
	bool emergencyVehicle;	//not being used at the moment
	int tracktion;				//not being used at the moment
	int weight;					//not being used at the moment
	int length;					//not being used at the moment
	int width;					//not being used at the moment
	int hazardRating;			//not being used at the moment

public:
	
	//constructers
	Vehicle();
	Vehicle(enum CARTYPES inputCARTYPE);

	//operator overloads
	friend ostream &operator<<(ostream &output, Vehicle inputCar);
	Vehicle operator++();

	//GETTERS
	CARTYPES getModel();
	int getMinSpeed();
	int getMaxSpeed();
	int getTracktion();
	int getWeight();
	int getLength();
	int getWidth();
	int getHazardRating();
	double getMaxAcceleration();
	double getCurrentSpeed();
	double getbrakingPower();
	double getlatitude();
	double getLongitude();
	double getAcceleration();
	double getDirection();
	bool getOversized();
	bool getEmergencyVehicle();
	
	//SETTERS
	void setMaxAcceleration(double inputSpeed);
	void setModel(CARTYPES inputModel);
	void setMinSpeed(int inputSpeed);
	void setMaxSpeed(int inputSpeed);
	void setCurrentSpeed(double inputSpeed);
	void setTracktion(int inputTraction);
	void setWeight(int inputWeight);
	void setbrakingPower(double inputbrakingPower);
	void setLength(int inputLength);
	void setWidth(int inputWidth);
	void setHazardRating(int inputHazardRating);
	void setlatitude(double inputlatitude);
	void setLongitude(double inputLongitude);
	void setAcceleration(double inputAcceleration);
	void setOversized(bool inputOversized);
	void setEmergencyVehicle(bool inputEmergencyVehicle);
	void setDirection(double inputDirection);

	//unknow functions
	void applyAcceleration(double time); //no idea what this is for
};


/************************************************************
								CHANGE LOG
1. vehicleModle type change to enum CARTYPES.			 REASON: Obvs - Michael Ritter
2. removed data member breakingSpeed.						 REASON: breaking is just negative acceleration. - Michael Ritter
3. name change of accelerationSpeed to maxAcceleration REASON: clarity between this data member and acceleration. - Michael Ritter
4. removed Vehicle operator++(int x)						 REASON: overloading one does both, you only do this one if you want only this one to be overloaded - Michael Ritter
*************************************************************/
