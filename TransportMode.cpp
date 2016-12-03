#pragma once
#include "Includes.h"
#include "TransportMode.h"


TransportMode::TransportMode()
{
	minSpeed = 0;
	maxSpeed = 0;
	currentSpeed = 0;
	length = 0;
	width = 0;
	hazardRating = 0;
	xPos = 0;
	yPos = 0;
	direction = PI / 2;
	id++;
}

TransportMode::TransportMode(int xStartCoordinate, int yStartCoordinate)
{
	xPos = xStartCoordinate;
	yPos = yStartCoordinate;
	minSpeed = 0;
	maxSpeed = 0;
	currentSpeed = 0;
	weight = 0;
	brakingPower = 0;
	length = 0;
	width = 0;
	hazardRating = 0;
	/*latitude = 0.0;
	longitude = 0.0;*/
	acceleration = 0.0;
	direction = 0;
	id++;
}

TransportMode::~TransportMode()
{
}

MapOBJ* TransportMode::findClosest(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X], int &distance)
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
void TransportMode::smartMove(MapOBJ *map[MAX_CITY_X][MAX_CITY_Y])	//still needs alot of work going to need to bounce ideas off you guys some time - Mike
{
	int distance = 0;
	MapOBJ *closest = findClosest(map, distance);
	TransportMode* tempCar = closest->getVehicle();
	Intersection* tempInter = closest->getIntersection();

	if (closest == nullptr || distance >= 50)	//if nothing is in front of you for 50 meters then just do simple movement
	{
		simpleMove(map);
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
				acceleration = 1;	//this will prolly have to change, for example both cars just started moving from a intersection. So in simple move you would be slaming you gas pedal which might be to fast and thus rear ending the car in front of you
			}
			else if (tempCar->getAcceleration() == 0 && tempCar->getCurrentSpeed() < this->currentSpeed) //if the person in front of you is not accelerating and their speed is less then your start slowing down but only a bit
			{
				acceleration = -1;
			}
			else if (tempCar->getAcceleration() > 0 && tempCar->getCurrentSpeed() > this->currentSpeed) //if the person in front of you is accelerating and they are going faster just simple move
			{
				simpleMove(map);	//will also prolly change
			}
			else if (tempCar->getAcceleration() > 0 && tempCar->getCurrentSpeed() < this->currentSpeed) //if the person in front of you is accelerating and they are going slower then you start coasting
			{
				acceleration = 0;
			}
			updateXY(map);
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
				currentSpeed = distance - 1;
			}

		}
	}
}
void TransportMode::updateXY(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])		//changed so that is works off the 4 cardinals instead of off of the double distance. -Mike
{
	map[yPos][xPos]->setVehicle(nullptr);
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
	if (map[yPos][xPos]->getVehicle() != nullptr) //CRASH
	{
		cout << "************************************************************************\n\t\tCRASH AT x= " << xPos << " y= " << yPos << endl;
		cout << "************************************************************************\n";
		delete map[yPos][xPos]->getVehicle();
		delete this;
		map[yPos][xPos]->setVehicle(nullptr);
	}
	else
	{
		map[yPos][xPos]->setVehicle(this);
	}

}
void TransportMode::simpleMove(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])
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
	updateXY(map);
}

//************************************************
//Getters
//************************************************
int TransportMode::getX()
{
	return xPos;
}
int TransportMode::getY()
{
	return yPos;
}
int TransportMode::getMinSpeed()
{
	return minSpeed;
}
int TransportMode::getMaxSpeed()
{
	return maxSpeed;
}
double TransportMode::getCurrentSpeed()
{
	return currentSpeed;
}
double TransportMode::getMaxAcceleration()
{
	return maxAcceleration;
}
double TransportMode::getbrakingPower()
{
	return brakingPower;
}
double TransportMode::getAcceleration()
{
	return acceleration;
}
double TransportMode::getDirection()
{
	return direction;
}
enum CARDINAL TransportMode::getCardinalD()
{
	return cardinalD;
}
CARDINAL TransportMode::getDesieredD()
{
	return desiredD;
}
int TransportMode::getLength()
{
	return length;
}
int TransportMode::getWidth()
{
	return width;
}
int TransportMode::getHazardRating()
{
	return hazardRating;
}
int TransportMode::getWeight()
{
	return weight;
}
int TransportMode::getId()
{
	return id;
}


//************************************************
//Setters
//************************************************
void TransportMode::setX(int x)
{
	xPos = x;
}
void TransportMode::setY(int y)
{
	yPos = y;
}
void TransportMode::setLength(int inputLength)
{
	length = inputLength;
}
void TransportMode::setWidth(int inputWidth)
{
	width = inputWidth;
}
void TransportMode::setHazardRating(int inputHazardRating)
{
	hazardRating = inputHazardRating;
}
void TransportMode::setWeight(int inputWeight)
{
	weight = inputWeight;
}
void TransportMode::setMinSpeed(int inputSpeed)
{
	minSpeed = inputSpeed;
}
void TransportMode::setMaxSpeed(int inputSpeed)
{
	maxSpeed = inputSpeed;
}
void TransportMode::setCurrentSpeed(double inputSpeed)
{
	currentSpeed = inputSpeed;
}
void TransportMode::setMaxAcceleration(double inputSpeed)
{
	maxAcceleration = inputSpeed;
}
void TransportMode::setbrakingPower(double inputbrakingPower)
{
	brakingPower = inputbrakingPower;
}
void TransportMode::setAcceleration(double inputAcceleration)
{
	acceleration = inputAcceleration;
}
void TransportMode::setCardinalD(enum CARDINAL inputCardinalD)
{
	cardinalD = inputCardinalD;
}
void TransportMode::setDesieredD(CARDINAL value)
{
	desiredD = value;
}
void TransportMode::setDirection(double inputDirection)
{
	direction = inputDirection;
}