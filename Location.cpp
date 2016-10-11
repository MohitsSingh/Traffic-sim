#include "includes.h"



Location::Location()
{
	cout << "Location" << endl;
}


Location::Location(int x, int y)
{
	xCoord = x;
	yCoord = y;
}

Location::~Location()
{
}

void Location::printLocation()
{
	cout << "x is " << xCoord << " y is " << yCoord;
}


void Location::setXCoord(int value)
{
	xCoord = value;
}
void Location::setYCoord(int value)
{
	yCoord = value;
}
int Location::getXCoord()
{
	return xCoord ;
}
int Location::getYCoord()
{
	return yCoord ;
}