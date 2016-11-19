#pragma once
#include "Includes.h"
#include "Vehicle.h"

class Truck : public Vehicle
{
private:
	string model;
public:
	Truck();
	Truck(bool emergency);
	~Truck();
};

