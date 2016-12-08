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
lets say that braking speed is just triple that just to be easy
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
#include "Road.h"
#include "TraficSignal.h"
#include <Windows.h>
#include <typeinfo>

int simTime = 0;	// I think this should be inside of "includes.h", but it's not working for me
const int SIM_DURATION = 8;						// this could also be it's own data type. typedef int simTime;

void createCars(vector <TransportMode*> &list, MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])
{
	int count = 0;
	Vehicle* temp;
	for (int y = 0; y < MAX_CITY_Y - 1; y++)
	{
		if (map[y][0] != nullptr && map[y + 1][0] != nullptr)
		{
			//++y;
			temp = new Vehicle(0, (y + 1));
			temp->setCardinalD(EAST);
			temp->setDesieredD(EAST);
			list.push_back(temp);
			map[y + 1][0]->setVehicle(temp);
			count++;
		}
		if (map[y][MAX_CITY_X - 1] != nullptr && map[y + 1][MAX_CITY_X - 1] != nullptr)
		{
			//++y;
			temp = new Vehicle(MAX_CITY_X-1, (y));
			temp->setCardinalD(WEST);
			temp->setDesieredD(WEST);

			list.push_back(temp);
			map[y][MAX_CITY_X -1]->setVehicle(temp);
			count++;
		}
	}
	for (int x = 0; x < MAX_CITY_X - 1; x++)
	{
		if (map[0][x] != nullptr && map[0][x + 1] != nullptr)
		{
			temp = new Vehicle(x, 0);
			temp->setCardinalD(SOUTH);
			temp->setDesieredD(SOUTH);

			list.push_back(temp);
			map[0][x]->setVehicle(temp);
			count++;
		}
		if (map[MAX_CITY_Y - 1][x] != nullptr && map[MAX_CITY_Y - 1][x + 1] != nullptr)
		{
			temp = new Vehicle(x+1, MAX_CITY_Y-1);
			temp->setCardinalD(NORTH);
			temp->setDesieredD(NORTH);
			list.push_back(temp);
			map[MAX_CITY_Y - 1][x+1]->setVehicle(temp);
			count++;
		}
	}
	cout << "Created " << count << " cars\n";
}


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

void addIntersections(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])
{

	//IntersectionData myIntersectionData;

	/*int row = MAX_CITY_Y / 2;
	int column = MAX_CITY_X / 2;
	int scalefactor = 100;
	int nrow;
	int ncolumn;*/

	int distance = 10;
	int j, k;

	int intersectionToPlot[9]{ 48, 5, 64, 101, 1, 61, 102, 53, 98 };

	int next = 0;
	for (j = 5; j < 30; j = j + distance)
	{
		for (k = 10; k < 30; k = k + distance)
		{
			map[j][k] = new MapOBJ;
			map[j][k]->setIntersection(new TraficSignal);
			map[j][k]->getIntersection()->setIntersectionID(intersectionToPlot[next]);
			map[j][k + 1] = map[j][k];
			map[j + 1][k] = map[j][k];
			map[j + 1][k + 1] = map[j][k];
			next++;
		}
	}

	//testing placement
	/*for (j = 0; j < 31; j++)
	{
		for (k = 0; k < 31; k++)
		{
			if (map[j][k] != nullptr)
			{
				cout << j << "  " << k << "  ";
				cout << map[j][k]->getIntersection()->getIntersectionID() << endl;
			}
		}
	}
*/
	//works with new mapobj
	/*	map[row][column] = new MapOBJ();
	map[row][column]->setIntersection(new Intersection());
	map[row][column]->getIntersection()->setIntersectionID(intersectionToPlot[k]);

	map[row + 1][column] = new MapOBJ();
	map[row + 1][column]->setIntersection(new Intersection());
	map[row + 1][column]->getIntersection()->setIntersectionID(intersectionToPlot[k]);
	map[row][column + 1] = new MapOBJ();
	map[row][column + 1]->setIntersection(new Intersection());
	map[row][column + 1]->getIntersection()->setIntersectionID(intersectionToPlot[k]);

	map[row + 1][column + 1] = new MapOBJ();
	map[row + 1][column + 1]->setIntersection(new Intersection());
	map[row + 1][column + 1]->getIntersection()->setIntersectionID(intersectionToPlot[k]);
	}*/
	cout << "9 grid intersections set";
	//	cout << "middle node set" << endl;
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
}

void makeRoads(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])
{

	for (int x = 0; x < MAX_CITY_X; x++)
	{
		for (int y = 0; y < MAX_CITY_Y; y++)		//scan the array from 0,0
		{
			if (map[y][x] != nullptr)					//check each element for a MapOBJ....
			{
				if (map[y][x]->getIntersection() != nullptr)	//check if the MapOBJ is an intersection...
				{


					int r = 0;									//go to the edge of the array
					while (r < MAX_CITY_Y)						//step thru the array until you get to the opp edge
					{
						if (map[r][x] == nullptr)					//at each empty element...
						{
							map[r][x] = new MapOBJ();					//spencemw updates 12-2	
							map[r][x]->setRoad(new Road);
						}
						r++;

					}//end while put roads in row


					int c = 0;									//go to the edge of the array
					while (c < MAX_CITY_X)						//step thru the array until you get to the opp edge
					{
						if (map[y][c] == nullptr)					//at each empty element...
						{
							map[y][c] = new MapOBJ();					//spencemw updates 12-2	
							map[y][c]->setRoad(new Road);
						}
						c++;

					}//end while pur roads in columns



				}//end if test MapOBJ contains an instance of intersection
			}//end if map[y][x] != nullptr
		}//end for y
	}//end for x


}

/********************************************************************************************************************
This function crudely prints the array for testing purposes.
spencemw 11-19-16, updated 12-2-16
*********************************************************************************************************************/
void printArray(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\n\nPrint Array's contents...\n";
	for (int y = 0; y < MAX_CITY_Y; y++)
	{
		for (int x = 0; x < MAX_CITY_X; x++)		//scan the array from 0,0
		{
			char str = ' ';
			SetConsoleTextAttribute(hConsole, 7);
			if (map[y][x] != nullptr)					//check each element for a MapOBJ....
			{
				if (map[y][x]->getIntersection() != nullptr)
				{
					SetConsoleTextAttribute(hConsole, 79);
					str = ' ';
				}

				else if (map[y][x]->getRoad() != nullptr)
				{
					SetConsoleTextAttribute(hConsole, 143);
					str = ' ';
					if (map[y][x]->getVehicle() != nullptr)
					{
						str = 254;
					}
				}

				else
					str = ' ';

			}//end if map[y][x] != nullptr
			cout << str;

		}//end for y

		cout << endl;

	}//end for x
	cout << "\n\n '.' = nullptr 'I' = MapObj with intersection 'r' = MapObj with road\n\n";
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
	addIntersections(map);		//add intersections, by JGarcia
	makeRoads(map);				//now that the intersections are in put in the roads...
	createCars(transportList, map);
	printArray(map);
	system("pause");

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
			if (intersectionList[i]->interType == STOPSIGN)
			{
				vector<TransportMode*> temp = intersectionList[i]->interPop();
				for (int i = 0; i < temp.size(); i++)
				{
					intersectionCarsWaiting.push_back(temp[i]);
				}
			}
			else
			{
				intersectionList[i]->updateSignal();
			}

		}
		//update intersectionCarsWaiting
		moveCarsWaiting(intersectionCarsWaiting, map);
		printArray(map);
		system("pause");
		simTime++;
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
void deleteMap(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])
{
	
}


/*
I would like to add a way to stop acceleration, start acceleration, change direction,
and apply brakes for all of the vehicles during the simulation.

For starting out pretty sure we are just going to have our "world" be able to have instantaneous changes in acceleration and velocity so
screw physics for now. And for changing direction we can just have a simple random funtion that passes the car into a random lane in the intersection OBJ.
So like the car is 1 square down from the intersection and then it wants to move so it gets passed into the "through", "left", or "right" lane. -Mike


*/
