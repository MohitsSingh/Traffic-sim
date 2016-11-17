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
#include "MapOBJ.h"
#include "main.h"
#include "TransportMode.h"
#include "Vehicle.h"
#include "Bus.h"
#include "Car.h"
#include "Semi.h"
#include "Sportscar.h"
#include "Truck.h"
#include "Van.h"
#include "Intersection.h"



int simTime = 9;	// I think this should be inside of "includes.h", but it's not working for me
const int SIM_DURATION = 10;						// this could also be it's own data type. typedef int simTime;



void moveCarsWaiting(vector <MapOBJ*> icw, MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])
{
	for (int i = 0; i < icw.size(); i++)
	{
		int tempX = icw[i]->getX();
		int tempY = icw[i]->getY();

		switch (icw[i]->getCardinalD())
		{
		case NORTH:
			switch (icw[i]->getDesieredD())
			{
			case NORTH:
				icw[i]->setY(tempY - 3);
				break;
			case WEST:
				icw[i]->setX(tempX - 2);
				icw[i]->setY(tempY - 2);
				break;
			case EAST:
				icw[i]->setX(tempX + 1);
				icw[i]->setY(tempY - 1);
				break;
			default:
				break;
			}
			break;
		case SOUTH:
			switch (icw[i]->getDesieredD())
			{
			case SOUTH:
				icw[i]->setY(tempY + 3);
				break;
			case WEST:
				icw[i]->setX(tempX - 1);
				icw[i]->setY(tempY + 1);
				break;
			case EAST:
				icw[i]->setX(tempX + 2);
				icw[i]->setY(tempY + 2);
				break;
			default:
				break;
			}
			break;
		case EAST:
			switch (icw[i]->getDesieredD())
			{
			case SOUTH:
				icw[i]->setY(tempY + 1);
				icw[i]->setX(tempX + 1);
				break;
			case NORTH:
				icw[i]->setX(tempX + 2);
				icw[i]->setY(tempY - 2);
				break;
			case EAST:
				icw[i]->setX(tempX + 3);
				break;
			default:
				break;
			}
			break;
		case WEST:
			switch (icw[i]->getDesieredD())
			{
			case SOUTH:
				icw[i]->setY(tempY + 2);
				icw[i]->setX(tempX - 2);
				break;
			case NORTH:
				icw[i]->setX(tempX - 1);
				icw[i]->setY(tempY - 1);
				break;
			case WEST:
				icw[i]->setX(tempX - 3);
				break;
			default:
				break;
			}
		default:
			break;
		}
	}
}
void updateMap(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X], vector <TransportMode*> transportList)
{
	for (int i = 0; i < transportList.size(); i++)
	{
		map[transportList[i]->getY()][transportList[i]->getX()] = transportList[i];
	}
}

int TransportMode::id = 0;

int main()
{
	int count = 0;
	int randType;

	srand(time(NULL));

	MapOBJ *map[MAX_CITY_Y][MAX_CITY_X];
	vector <TransportMode*> transportList;
	vector <Intersection*> intersectionList;
	vector <MapOBJ*> intersectionCarsWaiting;

	initializeMap(map, transportList);
	
	intersectionList.push_back(new Intersection());
	transportList.push_back(new TransportMode(6, 7));	//N,E,S,W
	cout << transportList[0]->getX() << ", " << transportList[0]->getY();
	transportList[0]->setCardinalD(NORTH);
	transportList[0]->setDesieredD(NORTH);
	//transportList.push_back(new Vehicle(6, 4));
	//transportList.push_back(new Vehicle(4, 5));
	//transportList.push_back(new Vehicle(5, 7));
	map[5][5] = intersectionList[0];
	map[5][6] = intersectionList[0];
	map[6][6] = intersectionList[0];
	map[6][5] = intersectionList[0];
	updateMap(map, transportList);

	while (simTime < SIM_DURATION)
	{
		//update cars
		for (int i = 0; i < transportList.size(); i++)
		{
			transportList[i]->smartMove(map);
		}
		//update intersections
		for (int i = 0; i < intersectionList.size(); i++)
		{
			intersectionCarsWaiting = intersectionList[i]->interPop();
		}
		//update intersectionCarsWaiting
		moveCarsWaiting(intersectionCarsWaiting, map);
		simTime++;
	}

	cout << transportList[0]->getX() << ", " << transportList[0]->getY();







	/*initializeDirection(transportList);
	initializeAcceleration(transportList);
	initializeCurrentSpeed(transportList);*/


	
	//cout << "\n\nBefore updates:\n--------------------------------------------"
	//	<<"-------------------------------------------------------------\n";
	//printVector(transportList);
	//cout << "--------------------------------------------"
	//	<< "-------------------------------------------------------------\n";

	//while (simTime < 5)
	//{
	//	simTime += TIME_INCREMENT;

	//	for (int i = 0; i < transportList.size(); i++)
	//	{
	//		transportList[i]->update();	// changes speed and location
	//	}
	//	printVector(transportList);
	//}
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
void initializeMap(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X], vector<TransportMode*> tempList)
{
	for (int i = 0; i < MAX_CITY_Y; i++)
	{
		for (int j = 0; j < MAX_CITY_X; j++)
		{
			map[i][j] = nullptr;
		}
	}

	for (int i = 0; i < tempList.size(); i++)
	{
		map[tempList[i]->getX()][tempList[i]->getY()] = tempList[i];
	}
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
			tempList[i]->setCardinalD(SOUTH);
			break;
		case 1:
			startDirection = 0;
			tempList[i]->setCardinalD(EAST);
			break;
		case 2:
			startDirection = PI / 2;
			tempList[i]->setCardinalD(NORTH);
			break;
		case 3:
			startDirection = PI;
			tempList[i]->setCardinalD(WEST);
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
