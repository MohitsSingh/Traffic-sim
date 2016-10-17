#include "TrafficSignal.h"
#include "includes.h"

Signal::Signal()
{
}

Signal::Signal(bool signControled)
{
	if (signControled == true)
	{
		fixedSign == true;
		lightedSignal == false;
		SignControlled(instance);
	}

	else
	{
		fixedSign == false;
		lightedSignal == true;
		ElecControlled(instance);
	}
}

/****************************************************************************************
Setters
*****************************************************************************************/

void Signal::setlatitude(double inputlatitude)
{
	if (inputlatitude <= MAXLAT && inputlatitude >= MINLAT)
	{
		latitude = inputlatitude;
	}

	else
	{
		cout << "Error void Signal::setlatitude(double inputlatitude) \n";
	}
}

void Signal::setLongitude(double inputLongitude)
{
	if (inputLongitude <= MAXLONG && inputLongitude >= MINLONG)
	{
		longitude = inputLongitude;
	}

	else
	{
		cout << "Error void Signal::setLongitude(double inputLongitude) \n";
	}

}

void Signal::setNumberOfPossDirections(int dir)
{
	if (dir > 0)
	{
		numberOfPossDirections = dir;
	}

	else
	{
		cout << "Error void Signal::setNumberOfPossDirections(int dir) \n";
	}
}

void Signal::SignControlled : setIntersectionName(string str)
{
	intersectionName = str;
}
int signType;							//stop, yield, etc.
int directionNumber;					//number the possible choices
double controlledDirection;				//radians east is zero
bool twoWayTraffic;						//true on two way streets

Signal::~Signal()
{
}
//
