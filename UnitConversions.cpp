#pragma once
using namespace std;

double miToKm(double distance)//Converts from miles to kilometers
{
	return distance * 1.60934;
}
double kmToMi(double distance)//converts from kilometers to miles
{
	return distance * 0.621371;
}

double kmhToMph(double speed)//Converts from kilometers per hour to miles per hour
{
	return  speed * 0.621371;
}
double mphToKmh(double speed)//converts from miles per hour to kilometers per hour
{
	return  speed * 1.60934;
}

double kmhToMps(double speed)//converts from kilometers per hour to meters per second
{
	return  speed * 0.44704;
}
double mpsToKmh(double speed)//converts from meters per second to miles per hour
{
	return  speed * 3.6;
}

double degreesToRadians(double direction)//converts from degrees to radians
{
	return  direction * 0.0174533;
}
double radiansToDegrees(double direction)//converts from radians to degrees
{
	return  direction * 57.2598;
}
