#pragma once
#include "Includes.h"

class Van : public Vehicle
{
private:
	string model;
public:
	Van();
	Van(bool emergency);
	~Van();
};

