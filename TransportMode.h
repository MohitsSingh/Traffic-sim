#pragma once
#include "Includes.h"
#include "MapOBJ.h"
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

	MapOBJ* findClosest(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X], int &distance)
	{
		switch (cardinalD)
		{
		case NORTH:
			for (int i = yPos - 1; i > 0 && distance < 50; i--)
			{
				distance++;
				MapOBJ* temp = map[i][xPos];
				if (temp != nullptr && temp->getIntersection() != nullptr || temp->getVehicle() != nullptr && yPos > 0)
				{
					return temp;
				}
			}
			break;
		case SOUTH:
			for (int i = yPos + 1; i < MAX_CITY_Y; i++)
			{
				distance++;
				MapOBJ* temp = map[i][xPos];
				if (temp != nullptr && temp->getIntersection() != nullptr || temp->getVehicle() != nullptr && yPos < MAX_CITY_Y)
				{
					return temp;
				}
			}
			break;
		case EAST:
			for (int i = xPos + 1; i < MAX_CITY_X; i++)
			{
				distance++;
				MapOBJ* temp = map[i][xPos];
				if (temp != nullptr && temp->getIntersection() != nullptr || temp->getVehicle() != nullptr && xPos < MAX_CITY_X)
				{
					return temp;
				}
			}
			break;
		case WEST:
			for (int i = xPos - 1; i > 0; i--)
			{
				distance++;
				MapOBJ* temp = map[i][xPos];
				if (temp != nullptr && temp->getIntersection() != nullptr || temp->getVehicle() != nullptr && xPos > 0)
				{
					return temp;
				}
			}
			break;
		default:
			cout << "\nError in defualt of findClosest\n";
			break;
		}
		return nullptr;
	}

	//changed the names of the functions to what I thought was more clear as to what they do -Mike
	void updateXY()		//changed so that is works off the 4 cardinals instead of off of the double distance. -Mike
	{
		switch (cardinalD)
		{
		case NORTH:
			yPos -= currentSpeed;
			break;
		case SOUTH:
			yPos += currentSpeed;
			break;
		case EAST:
			xPos += currentSpeed;
			break;
		case WEST:
			xPos -= currentSpeed;
			break;
		default:
			cout << "\nError in move\n";
			break;
		}
	}
	void simpleMove()
	{
		if (currentSpeed < maxSpeed * .25)	//if you are going 1/4 of your max speed, slam that pedal into the floor
		{
			acceleration = maxAcceleration;
		}
		else if (currentSpeed < maxSpeed / 2)	//if you are going half your speed accelerate at a decent rate
		{
			acceleration = 3;
		}
		else if (currentSpeed < maxSpeed)	//if you got here that means your above half your max speed so chill out on the gas now
		{
			acceleration = 1;
		}

		currentSpeed += acceleration * TIME_INCREMENT;
		if (currentSpeed > maxSpeed)	//if you went over your max speed, cheat and go back down to it
		{
			currentSpeed = maxSpeed;
		}
		updateXY();
	}
	
	void smartMove(MapOBJ *map[MAX_CITY_X][MAX_CITY_Y])	//still needs alot of work going to need to bounce ideas off you guys some time - Mike
	{
		int distance = 0;
		MapOBJ *closest = findClosest(map, distance);
		TransportMode* tempCar = closest->getVehicle();
		Intersection* tempInter = closest->getIntersection();
		
		if (closest == nullptr || distance >= 50)	//if nothing is in front of you for 50 meters then just do simple movement
		{
			simpleMove();
		}
		else
		{
			if (tempCar != nullptr)
			{
				if (tempCar->getAcceleration() < 0 && tempCar->getCurrentSpeed() < this->currentSpeed)	//if person in front of you is slowing and they are going slower then you slow down at 1.5 the rate they are
				{
					acceleration = tempCar->getAcceleration() * 1.5;
				}
				else if (tempCar->getAcceleration() < 0 && tempCar->getCurrentSpeed() > this->currentSpeed) //if person in front of you is slowing and they are going faster then you slow down at half the rate they are slowing
				{
					acceleration = tempCar->getAcceleration() / 2;
				}
				else if (tempCar->getAcceleration() == 0 && tempCar->getCurrentSpeed() > this->currentSpeed) //if the person in front of you is not accelerating and they are going faster then you just simple move
				{
					simpleMove();	//this will prolly have to change, for example both cars just started moving from a intersection. So in simple move you would be slaming you gas pedal which might be to fast and thus rear ending the car in front of you
				}
				else if (tempCar->getAcceleration() == 0 && tempCar->getCurrentSpeed() < this->currentSpeed) //if the person in front of you is not accelerating and their speed is less then your start slowing down but only a bit
				{
					acceleration = -1;
				}
				else if (tempCar->getAcceleration() > 0 && tempCar->getCurrentSpeed() > this->currentSpeed) //if the person in front of you is accelerating and they are going faster just simple move
				{
					simpleMove();	//will also prolly change
				}
				else if (tempCar->getAcceleration() > 0 && tempCar->getCurrentSpeed() < this->currentSpeed) //if the person in front of you is accelerating and they are going slower then you start coasting
				{
					acceleration = 0;
				}
			}
			else if (tempInter != nullptr)
			{
				if (distance == 1)
				{
					tempInter->interPush(this);
				}
				else if (distance <= 10)
				{
					acceleration = 0;
					currentSpeed = distance-1;
				}
				
			}
		}
	}
};



