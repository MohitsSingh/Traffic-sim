#pragma once
#include "includes.h"

class Car : public Vehicle
{
private: 
	string model;
public:
	Car();
	Car(int x, int y, double directionData);
	~Car();
};

