/***************************************************************************************
David Sant
Spence Wilson
Isaac Haas
Last submitted on: 10/22/16
Uses: all of the files
Creates a vector of TransportMode, and then moves them around
***************************************************************************************/


/* Approximate conversions:

75 mph (approx)= 35 meters/sec or 35 m/s
60 mph (approx)= 25 m/s
35 mph (approx)= 15 m/s

an average acceleration is 3 to 4 m/s,
which translates to approximately 7 to 9 mph/s

*/



#include "Includes.h"

int simTime = 0;	// I think this should be inside of "includes.h", but it's not working for me
						// this could also be it's own data type. typedef int simTime;

vector<TransportMode*> fillVector();	//
void initializeDirection(vector<TransportMode*> tempList);	// sets every object's direction to one of the cardinal directions
void initializeAcceleration(vector<TransportMode*> tempList);	// sets every object's acceleration to 0, 3, or 4 m/s/s
void initializeCurrentSpeed(vector<TransportMode*> tempList);	// sets every object's speed to 10 m/s
void printVector(vector<TransportMode*> tempList);	// just a temporary output function

int main()
{
	int count = 0;
	int randType;

	srand(time(NULL));

	vector <TransportMode*> transportList = fillVector();
	initializeDirection(transportList);
	initializeAcceleration(transportList);
	initializeCurrentSpeed(transportList);
	
	cout << "\n\nBefore updates:\n--------------------------------------------"
		<<"-------------------------------------------------------------\n";
	printVector(transportList);
	cout << "--------------------------------------------"
		<< "-------------------------------------------------------------\n";

	while (simTime < 5)
	{
		simTime += TIME_INCREMENT;

		for (int i = 0; i < transportList.size(); i++)
		{
			transportList[i]->update();	// changes speed and location
		}
		printVector(transportList);
	}
	cout << endl << endl;
	system("pause");
	return 0;
}


vector<TransportMode*> fillVector()
{
	vector <TransportMode*> tempList;
	int sizeOfList;
	int count = 0;
	int randType;

	cout << "(in computer voice) Enter number of vehicles for start of simulation ";
	cin >> sizeOfList;
	//declare the vector here so it already has the right size, then change the lines in the case to be just templist[count] = new Bus()
	//pushback is slow so if we know the starting size already then lets just put it at that. - Mike

	// 6 types of vehicles: bus, car, semi, sport, truck, and van
	while (count < sizeOfList)
	{

		randType = rand() % 6 + 1;
		switch (randType)
		{
		case 1:
			tempList.push_back(new Bus());
			break;
		case 2:
			tempList.push_back(new Car());
			break;
		case 3:
			tempList.push_back(new Semi());
			break;
		case 4:
			tempList.push_back(new Sportscar());
			break;
		case 5:
			tempList.push_back(new Truck());
			break;
		default:
			tempList.push_back(new Van());
		}
		count++;
	}
	return tempList;
}
void initializeDirection(vector<TransportMode*> tempList)
{
	double startDirection;
	int randType;
	for (int i = 0; i < tempList.size(); i++)
	{
		randType = rand() % 3;
		switch (randType)
		{
		case 0:
			startDirection = 3 * PI / 2;
			break;
		case 1:
			startDirection = 0;
			break;
		case 2:
			startDirection = PI / 2;
			break;
		case 3:
			startDirection = PI;
			break;
		}
		tempList[i]->setDirection(startDirection);
	}
}
void initializeAcceleration(vector<TransportMode*> tempList)
{
	int randType;
	for (int i = 0; i < tempList.size(); i++)
	{
		randType = rand() % 5;	// a number between 0 and 4

										// only setting acceleration to 0, 3, or 4
		if (randType != 1 && randType != 2)
		{
			tempList[i]->setAcceleration(randType);
		}
		else
		{
			tempList[i]->setAcceleration(randType);
		}
	}

}
void initializeCurrentSpeed(vector<TransportMode*> tempList)
{
	int randType;
	for (int i = 0; i < tempList.size(); i++)
	{
		tempList[i]->setCurrentSpeed(10);
	}
}
void printVector(vector<TransportMode*> tempList)
{
	for (int i = 0; i < tempList.size(); i++)
	{
		cout << "model num: " << tempList[i]->getModel();
		cout << "\tDIRECTION: " << tempList[i]->getDirection() * 180 / PI;
		cout << "\tACCELERATION: " << tempList[i]->getAcceleration();
		cout << "\tCURRENT SPEED: " << tempList[i]->getCurrentSpeed();
		cout << endl;
	}
	cout << endl << endl;
}



/*
I would like to add a way to stop acceleration, start acceleration, change direction,
and apply brakes for all of the vehicles during the simulation.

For starting out pretty sure we are just going to have our "world" be able to have instantaneous changes in acceleration and velocity so
screw physics for now. And for changing direction we can just have a simple random funtion that passes the car into a random lane in the intersection OBJ.
So like the car is 1 square down from the intersection and then it wants to move so it gets passed into the "through", "left", or "right" lane. -Mike


*/
