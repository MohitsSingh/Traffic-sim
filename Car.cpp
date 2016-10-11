#include "includes.h"


Car::Car()
{
	cout << "Car" << endl;
}

Car::Car(int x, int y, double directionData) : Vehicle(x, y)
{
	setDirection(directionData);
}


Car::~Car()
{
}