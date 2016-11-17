#pragma once
#include "Includes.h"
#include "Vehicle.h"

class Van : public Vehicle
{
protected:
public:
	Van(bool emergency = false);  // doubles as default constructor if no bool is entered
	~Van();
};

