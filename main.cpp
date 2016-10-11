/***************************************************************************************
Isaac Haas
Spence Wilson
David Sant
Last submitted on: 10/11/16
Uses: Car, Vehicle, Location, and includes
Creates a vector of Vehicels, reads in values from txt file
Moves through the origin.
***************************************************************************************/

#include "Includes.h"
int time = 0;

int main()
{
	//cout << "cos(PI/2) = " << cos(PI / 2) << "/tsin(PI/2) = " << sin(PI / 2) << endl;
	//cout << "cos(0) = " << cos(0) << "/tsin(0) = " << sin(0) << endl;

	ifstream fin;
	vector <Vehicle> vehicleList;

	fin.open("sampleVehilces.txt");

	while (!fin.fail())
	{
		Vehicle x = Vehicle(fin);
		vehicleList.push_back(x);
	}



	Car myFirstCar(-20, 2, 0.0), mySecondCar(15, -2, PI);
	myFirstCar.setCurrentSpeed(3); mySecondCar.setCurrentSpeed(5);
	cout << endl;
	for (int i = 0; i < 9; i++)
	{
		time++;
		
		cout << "Car1:\t" << endl << myFirstCar << "Car2:\t" << endl << mySecondCar << endl;
		myFirstCar.update();
		mySecondCar.update();

		if (mySecondCar.getLocation().getXCoord() == 0)
		{
			cout << "Car2 is in the intersection at " << time << " seconds" << endl << endl;
		}
		if (myFirstCar.getLocation().getXCoord() >= 0)
		{
			cout << "Car1 is in the intersection at " << time << " seconds" << endl << endl;
			break;
		}
	}






	cout << endl;
	system("pause");
	return 0;
}