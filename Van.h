#pragma once
#include "Includes.h"

class Van : public Vehicle
{
protected:
public:
	Van(bool emergency = false);  // doubles as default constructor if no bool is entered
	~Van();
	Van(double x, double y, bool emergency = false);
};

