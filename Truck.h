//Christine Sobolewski, Adam Gunnell, Jack Grebb
#pragma once
#include "Includes.h"
#include "Vehicle.h"

//Christine Sobolewski
class Truck : public Vehicle
{
private:
	string model;
public:
	Truck();
	Truck(bool emergency);
	~Truck();
};

