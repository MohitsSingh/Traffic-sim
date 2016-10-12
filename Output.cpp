#include "Vehicle.h"

/***************************************************Output Team*****************************************************
simplePrint
parameter: Vehicle for output
return: void
prints speed, acceleration, direction, and position

10/11 Spencemw updated the variable names and member fucntion names to the current term (traction is still mispelled)
*******************************************************************************************************************/


ostream &operator<<(ostream &output, Vehicle lorry)				//overload << outputs all members of the class
{

	output << /*"Kind: " << lorry.kind <<*/ "\nMax Speed: " << lorry.maxSpeed << "\nMin Speed: " << lorry.minSpeed << "\nTraction: " << lorry.traction << "\nweight: " << lorry.weight << "\nbrakePower: " << lorry.brakingPower << "\nlength: " << lorry.length << "\nwidth: " << lorry.width << "\nhazardRating: " << lorry.hazardRating << "\ncurrentSpeed: " << setprecision(1) << fixed << lorry.currentSpeed << "\ndirection (radian): " << setprecision(5) << lorry.direction << "\nlongitude: " << lorry.longitude << "\nlatitude: " << lorry.latitude << "\nacceleration: " << setprecision(1) << lorry.acceleration << "\nemergencyVehicle: ";

	if (lorry.emergencyVehicle == false ? cout << "False" : cout << "True")
		cout << "\noverSized: ";

	//if (lorry.getOversized == false ? cout << "False" : cout << "True")   Oversized Not working, spenemw 10/11
	
	return output;
}

/***************************************************Output Team*****************************************************
simplePrint
parameter: Vehicle for output
return: void
prints speed, acceleration, direction, and position
*******************************************************************************************************************/
void simplePrint(Vehicle lorry)									//outputs current speed, acceleration, direction, long, lat
{
	cout << "Current Speed: " << lorry.currentSpeed << " Acceleration: " << lorry.acceleration << " Direction(radians): " << lorry.direction << endl;
	cout << "Longitude: " << lorry.longitude << " Latitude: " << lorry.latitude << endl;
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



/***************************************************Garbage, future use, or retired below*****************************************************/

//ostream &operator<<(ostream &output, Vehicle lorry)
//{
//	output << "speed		acceleration	  longitude\n";
//	output << lorry.currentSpeed << setw(20) << lorry.acceleration << setw(20) << lorry.longitude << endl;
//	return output;
//}




// These are mine  (Isaac Haas)***********************************************************

//double Vehicle::convertRadians(double numRadians)
//{
//	return (numRadians / 3.141592654 * 180);
//}

/* calculateCardinalDirection
parameters: none
return: the cardinal direction of the Vehicle
Assumes 0 radians is East, calculates the cardinal direction */