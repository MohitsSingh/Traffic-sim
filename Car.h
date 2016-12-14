//Christine Sobolewski, Adam Gunnell, Jack Grebb
#pragma once
#include "Includes.h"
#include "Vehicle.h"

//Adam Gunnell
class Car : public Vehicle
{
protected:
public:
	Car(bool emergency = false); // doubles as default constructor if no bool value is entered
	~Car();
};

