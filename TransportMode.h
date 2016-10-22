#pragma once
#include "Includes.h"



class TransportMode : public MapOBJ
{
protected:
	int length;					//not being used at the moment
	int width;					//not being used at the moment
	int hazardRating;			//not being used at the moment
	int weight;
	int traction;
	bool oversized;

public:
	TransportMode();
	TransportMode(int xStartCoordinate, int yStartCoordinate);
	~TransportMode();

	//GETTERS
	int getLength();
	int getWidth();
	int getHazardRating();
	int getWeight();
	int getTraction();
	bool getOversized();

	//SETTERS
	void setLength(int inputLength);
	void setWidth(int inputWidth);
	void setHazardRating(int inputHazardRating);
	void setWeight(int inputWeight);
	void setTraction(int inputTraction);
	void setOversized(bool inputOversized);

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

	virtual CARTYPES getModel()
	{
		return CARTYPES(0);
	}
};

