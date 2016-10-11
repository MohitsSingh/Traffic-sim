#pragma once
#include "Includes.h"

class Car : public Vehicle
{
private:
	string model;
public:
	Car();
	Car(bool emergency);
	~Car();
};

