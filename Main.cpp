/*_____________________________________________
Isaac Haas, Spence Wilson, Brian Choi, Alexander Tate, Christine Sobolewski, Michael Galzin
First output draft
September 22, 2016
_______________________________________________*/
#include <iostream>
#include "Vehicle.h"
#include <iomanip>
#include <vector>
using namespace std;

#define PI 3.141592654


int main()
{
	Vehicle one;									//create a car

	//one.setKind("someCar");							//initialize variables in the class
	one.setMaxSpeed(1);
	one.setMinSpeed(2);
	//one.setTraction(3);
	one.setWeight(4);
	//one.setBrakePower(5);
	//one.setLeangth(6);
	one.setWidth(7);
	one.setHazardRating(8);
	one.setCurrentSpeed(45);
	one.setDirection(PI / 6);						//radains, E is 0
	one.setLongitude(40.0);
	//one.setLatitude(-105.0);
	one.setAcceleration(9);
	one.setEmergencyVehicle(true);
	//one.setOverSized(false);

	cout << endl << "Use Overloaded '<<' as an output of all member values..." << endl;
	cout << one << endl;

	cout << endl << "Use 'simplePrint' fxn..." << endl;
	simplePrint(one);

	cout << endl << "Use, 'directionPrint' fxn..." << endl;
	directionPrint(one);

	cout << endl << endl;
	system("pause");
	return 0;
}