#pragma once
#include "Includes.h"

class Car : public Vehicle
{
protected:
public:
	Car();
	Car(bool emergency = false);
	~Car();
};

