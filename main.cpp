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


#pragma once
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



void moveCarsWaiting(vector <TransportMode*> icw, MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])
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


int TransportMode::id = 0;

int main()
{
	int count = 0;
	int randType;

	srand(time(NULL));

	MapOBJ *map[MAX_CITY_Y][MAX_CITY_X];
	vector <TransportMode*> transportList;
	vector <Intersection*> intersectionList;
	vector <TransportMode*> intersectionCarsWaiting;

	initializeMap(map);
	addIntersections(map);
	
	
	//intersectionList.push_back(new Intersection());
	//transportList.push_back(new TransportMode(6, 7));	//N,E,S,W
	//cout << transportList[0]->getX() << ", " << transportList[0]->getY();
	//transportList[0]->setCardinalD(NORTH);
	//transportList[0]->setDesieredD(NORTH);
	//transportList.push_back(new Vehicle(6, 4));
	//transportList.push_back(new Vehicle(4, 5));
	//transportList.push_back(new Vehicle(5, 7));
	/*map[5][5] = intersectionList[0];
	map[5][6] = intersectionList[0];
	map[6][6] = intersectionList[0];
	map[6][5] = intersectionList[0];*/
	

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
void initializeMap(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])
{
	for (int i = 0; i < MAX_CITY_Y; i++)
	{
		for (int j = 0; j < MAX_CITY_X; j++)
		{
			map[i][j] = nullptr;
		}
	}
}

/*
Section by Jacqueline Garcia
Puts 9 real intersection onto MapOBJ at the top right. The intersectios are placed at 
520 unit intervals(distance), both down and across.
Puts pointers to these intersections in the next right,next below, and next right below spaces

48 - represents shields and drake
5   - represents college and drake
64	- represents lemay and drake
101- represents shields and horsetooth
1	- represents college and horsetooth
61	- represents lemay and horsetooth
102- represents shields and harmony
53	- represents college and harmony
98 - represents lemay and harmony

The printout statement shows where and what intersection ID the pointers are set to.

*/
void addIntersections(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])
{
	
	IntersectionData myIntersectionData;
	
	/*int row = MAX_CITY_Y / 2;
	int column = MAX_CITY_X / 2;
	int scalefactor = 100;
	int nrow;
	int ncolumn;*/

	int distance = 52;
	int j,k;

	int intersectionToPlot[9]{ 48,5,64,101,1,61,102,53,98 };
	
	int next = 0;
	for (j = 0; j < MAX_CITY_X; j = j + distance)
	{
		for (k = 0; k < MAX_CITY_Y; k = k + distance)
		{
			map[j][k] = new MapOBJ;
			map[j][k]->setIntersection(new Intersection());
			map[j][k]->getIntersection()->setIntersectionID(intersectionToPlot[next]);
			map[j][k + 1] = map[j][k];
			map[j + 1][k] = map[j][k];
			map[j + 1][k + 1] = map[j][k];
			next++;
		}
	}

	//testing placement
	for (j = 0; j < MAX_CITY_X; j++)
	{
		for (k = 0; k < MAX_CITY_Y; k++)
		{
			if (map[j][k] != nullptr)
			{
				cout << j << "  " << k << "  ";
				cout << map[j][k] ->getIntersection()->getIntersectionID()<< endl;
			}
		}
	}
	
		}

//	cout << "9 grid intersections set";
//cout << "middle node set" << endl;
//	//set intersection to the south
//	distance = myIntersectionData.getDistanceNB(intID);
//	distance = (distance *0.308)/scalefactor;
//	cout << "distance " << distance << endl;
//	nrow = row + distance;
//	if (nrow <= MAX_CITY_Y && nrow > 0)
//	{
//		map[nrow][column] = new MapOBJ();
//		map[nrow][column]->setIntersection(new Intersection());		
//		map[nrow][column]->getIntersection()->setIntersectionID(myIntersectionData.getUpIdNB(intID));
//		cout << "south node set" << endl;
//	}
//	else
//	{
//		return;
//		//cout <<" no more room for south streets";
//	//	//do not try to put more south streets into the grid
//	}
//
//	//set intersection to the north
//	distance = myIntersectionData.getDistanceSB(intID);
//	distance = (distance *0.308)/scalefactor;
//	nrow = row - distance;
//	if (nrow <= MAX_CITY_Y && nrow > 0)
//	{
//		map[nrow][column] = new MapOBJ();
//		map[nrow][column]->setIntersection(new Intersection());
//		map[nrow][column]->getIntersection()->setIntersectionID(myIntersectionData.getUpIdSB(intID));
//		cout << "north node set at " << nrow << " " << column << endl;
//	}
//	else
//	{
//		return;
//		//cout <<" no more room for north streets";
//		//do not try to put more north streets into the grid
//	}
//
//	//set intersection to the west
//	distance = myIntersectionData.getDistanceEB(intID);
//	distance = (distance *0.308)/scalefactor;
//	ncolumn = column - distance;
//	if (ncolumn <= MAX_CITY_X && ncolumn > 0)
//	{
//		map[row][ncolumn] = new MapOBJ();
//		map[row][ncolumn]->setIntersection(new Intersection());
//		map[row][ncolumn]->getIntersection()->setIntersectionID(myIntersectionData.getUpIdEB(intID));
//
//	}
//	else
//	{
//		return;
//		//cout <<" no more room for west streets";
//		//do not try to put more west streets into the grid
//	}
//
//	//set intersection to the east
//	distance = myIntersectionData.getDistanceWB(intID);
//	distance = (distance *0.308)/scalefactor;
//	ncolumn = column + distance;
//	if (ncolumn <= MAX_CITY_X && ncolumn > 0)
//	{
//		map[row][ncolumn] = new MapOBJ();
//		map[row][ncolumn]->setIntersection(new Intersection());
//		map[row][ncolumn]->getIntersection()->setIntersectionID(myIntersectionData.getUpIdWB(intID));
//
//		map[row+1][ncolumn] = new MapOBJ();
//		map[row+1][ncolumn]->setIntersection(new Intersection());
//		map[row+1][ncolumn]->getIntersection()->setIntersectionID(myIntersectionData.getUpIdWB(intID));
//
//		map[row][ncolumn+1] = new MapOBJ();
//		map[row][ncolumn+1]->setIntersection(new Intersection());
//		map[row][ncolumn+1]->getIntersection()->setIntersectionID(myIntersectionData.getUpIdWB(intID));
//
//		map[row+1][ncolumn+1] = new MapOBJ();
//		map[row+1][ncolumn+1]->setIntersection(new Intersection());
//		map[row+1][ncolumn+1]->getIntersection()->setIntersectionID(myIntersectionData.getUpIdWB(intID));
//
//	}
//	else
//	{
//		//cout <<" no more room for east streets";
//		//do not try to put more east streets into the grid
//	}
//
//	cout << "At end";
//	//return;

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
		cout << "model num: " << tempList[i]->getId();
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
