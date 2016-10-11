#pragma once
#include "Includes.h"

class Truck : public Vehicle
{
private:
	string model;
public:
	Truck();
	Truck(bool emergency);
	~Truck();
};

