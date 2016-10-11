#pragma once
//#include "Location.h"
#include "Includes.h"

/***********************************************************************
Commented by: Michael Ritter
Change Log Location: bottom of this file.
************************************************************************/

class Vehicle : public TransportMode
{
protected:
	CARTYPES model;					//JG: enumerated type of model
	bool emergencyVehicle;			//JG: represents whether vehicle is an emergency variant (e.g. an ambulance)
	bool activeEmergency;			//JG: whether the vehicle is currently in an emergency (e.g. an ambulance, with its lights on)

	double acceleration;			//current acceleration 
	double maxAcceleration;			//current acceleration
	double brakingPower;			//Vehicle spec of breaking power

	bool oversized;					//not being used at the moment
	
	int traction;					//not being used at the moment
	int weight;						//not being used at the moment
	

public:
	//constructers
	Vehicle();

	//operator overloads
	friend ostream &operator<<(ostream &output, Vehicle inputCar);
	//Vehicle operator++();					//JG was an in-class example, no function

	//GETTERS
	CARTYPES getModel();
	int getTraction();
	int getWeight();
	
	double getMaxAcceleration();
	double getbrakingPower();
	double getAcceleration();
	
	bool getOversized();
	bool getEmergencyVehicle();
	bool isActiveEmergency();			//JG

	//SETTERS
	void setModel(CARTYPES inputModel);
	void setTraction(int inputTraction);
	void setWeight(int inputWeight);

	void setMaxAcceleration(double inputSpeed);
	void setbrakingPower(double inputbrakingPower);	
	void setAcceleration(double inputAcceleration);

	void setOversized(bool inputOversized);
	void setEmergencyVehicle(bool inputEmergencyVehicle);
	void setActiveEmergency(bool);			//JG

	void applyAcceleration(double time);
};


/************************************************************
CHANGE LOG
1. Moved variables minSpeed, maxSpeed, currentSpeed, latitude, longitude, direction, length, width, and hazardRating to TransportMode Class		- Adam Gunnell
*************************************************************/
/*
Jack Grebb 10/11 changes:

*/