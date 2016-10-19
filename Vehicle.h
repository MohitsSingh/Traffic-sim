#pragma once
#include "Includes.h"



class Vehicle : public TransportMode
{
protected:
	CARTYPES model;					//JG: enumerated type of model
	bool emergencyVehicle;			//JG: represents whether vehicle is an emergency variant (e.g. an ambulance)
	bool activeEmergency;			//JG: whether the vehicle is currently in an emergency (e.g. an ambulance, with its lights on)
	

	
	

public:

	//constructers
	Vehicle();

	//operator overloads
	friend ostream &operator<<(ostream &output, Vehicle inputCar);
	

	//GETTERS
	CARTYPES getModel();
	bool getEmergencyVehicle();
	bool isActiveEmergency();			//JG


	//SETTERS
	void setModel(CARTYPES inputModel);
	void setEmergencyVehicle(bool inputEmergencyVehicle);
	void setActiveEmergency(bool);			//JG
	
};


/************************************************************
CHANGE LOG
1. Moved variables minSpeed, maxSpeed, currentSpeed, latitude, longitude, direction, length, width, and hazardRating to TransportMode Class		- Adam Gunnell
*************************************************************/
/*
Jack Grebb 10/11 changes:

*/