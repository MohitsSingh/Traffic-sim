#pragma once
#include "Includes.h"
#include "MapOBJ.h"
#include "Intersection.h"

class MapOBJ;
class Intersection;

class TransportMode
{
protected:
	static int id;
	int xPos;
	int yPos;
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
	CARDINAL cardinalD;	//direction of car for simple cardinal directions
	CARDINAL desiredD; //what direction the car wants to go at an intersection
	

public:

	TransportMode();
	~TransportMode();
	TransportMode(int xStartCoordinate, int yStartCoordinate);

	//GETTERS
	int getX();
	int getY();
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
	CARDINAL getDesieredD();
	int getId();
	

	//SETTERS
	void setX(int x);
	void setY(int y);
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
	void setDesieredD(CARDINAL value);
	void setDirection(double inputDirection);
	void setHazardRating(int inputHazardRating);

	int calcTimeCycles(int distance);

	MapOBJ* findClosest(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X], int &distance);
	void smartMove(MapOBJ *map[MAX_CITY_X][MAX_CITY_Y]);
	
	void updateXY(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X]);
	void simpleMove(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X]);
	void moveThroughIntersection(int distance);
	
	
	
	
};



