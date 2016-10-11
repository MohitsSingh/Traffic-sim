#pragma once
//#include "Location.h"
#include "Includes.h"

/***********************************************************************
Commented by: Michael Ritter
Change Log Location: bottom of this file.
************************************************************************/

class Vehicle : public TransportMode
{
private:
	double acceleration;		//current acceleration 
	double maxAcceleration;	    //current acceleration
	double brakingPower;		//Vehicle spec of breaking power

	bool oversized;			    //not being used at the moment
	bool emergencyVehicle;	    //not being used at the moment
	int traction;				//not being used at the moment
	int weight;					//not being used at the moment
	

public:
	//constructers
	Vehicle();
	Vehicle(enum CARTYPES inputCARTYPE);

	//operator overloads
	friend ostream &operator<<(ostream &output, Vehicle inputCar);
	Vehicle operator++();

	//GETTERS
	CARTYPES getModel();
	int getTraction();
	int getWeight();
	
	double getMaxAcceleration();
	double getbrakingPower();
	double getAcceleration();
	
	bool getOversized();
	bool getEmergencyVehicle();

	//SETTERS
	void setModel(CARTYPES inputModel);
	void setTraction(int inputTraction);
	void setWeight(int inputWeight);

	void setMaxAcceleration(double inputSpeed);
	void setbrakingPower(double inputbrakingPower);	
	void setAcceleration(double inputAcceleration);

	void setOversized(bool inputOversized);
	void setEmergencyVehicle(bool inputEmergencyVehicle);


	void applyAcceleration(double time);
};


/************************************************************
CHANGE LOG
1. Moved variables minSpeed, maxSpeed, currentSpeed, latitude, longitude, direction, length, width, and hazardRating to TransportMode Class		- Adam Gunnell
*************************************************************/
