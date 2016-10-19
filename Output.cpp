#include "Includes.h"

/***************************************************Output Team*****************************************************
simplePrint
parameter: Vehicle for output
return: void
prints speed, acceleration, direction, and position

10/11 Spencemw updated the variable names and member fucntion names to the current term (traction is still mispelled)
*******************************************************************************************************************/



/***************************************************Output Team*****************************************************
simplePrint
parameter: Vehicle for output
return: void
prints speed, acceleration, direction, and position
*******************************************************************************************************************/
void simplePrint(Vehicle lorry)									//outputs current speed, acceleration, direction, long, lat
{
	cout << "Current Speed: " << lorry.getCurrentSpeed() << " Acceleration: " << lorry.getAcceleration() << " Direction(radians): " << lorry.getDirection() << endl;
	cout << "Longitude: " << lorry.getX() << " Latitude: " << lorry.getY() << endl;
}



/***************************************************Output Team*****************************************************
directionPrint
parameter: Vehicle for output
return: void
prints the direction in degrees(East being 0, North being 90)
and the cardinal direction of the Vehicle

10/11 Spencemw updated the variable names and member fucntion names to the current term (traction is still mispelled)
*******************************************************************************************************************/
void directionPrint(Vehicle lorry)								//outputs direction degrees, and cardinal direction
{
	cout << "Direction(degrees): " << lorry.getDirection() << /*" Cardinal: " << lorry.calculateCardinalDirection() <<*/ endl;
}



