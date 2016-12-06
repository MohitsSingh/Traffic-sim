/***************************************************************************************
David Sant
Spence Wilson
Isaac Haas
Last submitted on: 10/22/16
last update: 12/2/16

Adds Jackie Garcia's from the Data Teams code that inserts intersections to Main.  

Adds Kyle Cilley's from the Road Teams class part of their code (only used Road.h & cpp in the end).  

Modified my print function to look for the instance of road instead of the previous bool

***************************************************************************************/

#include "Includes.h"
#include "MapOBJ.h"
#include "TransportMode.h"
#include "main.h"
#include "Road.h"
#include "Vehicle.h"
#include "Bus.h"
#include "Car.h"
#include "Semi.h"
#include "Sportscar.h"
#include "Truck.h"
#include "Van.h"
#include "Intersection.h"
#include <Windows.h>
#include <typeinfo>

int TransportMode::id = 0;


void createCars(vector <TransportMode*> &list, MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])
{
	int count = 0;
	Vehicle* temp;
	for (int y = 0; y < MAX_CITY_Y - 1; y++)
	{
		if (map[y][0] != nullptr && map[y + 1][0] != nullptr)
		{
			//++y;
			temp = new Vehicle(0, (y + 1) * 3);
			temp->setDirection(0);
			list.push_back(temp);
			map[y + 1][0]->setVehicle(temp);
			count++;
		}
		if (map[y][MAX_CITY_X - 1] != nullptr && map[y + 1][MAX_CITY_X - 1] != nullptr)
		{
			//++y;
			temp = new Vehicle(MAX_CITY_X, (y + 1) * 3);
			temp->setDirection(PI);
			list.push_back(temp);
			map[y][MAX_CITY_X -1]->setVehicle(temp);
			count++;
		}
	}
	for (int x = 0; x < MAX_CITY_X - 1; x++)
	{
		if (map[0][x] != nullptr && map[0][x + 1] != nullptr)
		{
			temp = new Vehicle(x * 3, 0);
			temp->setDirection(3 * PI / 2);
			list.push_back(temp);
			map[0][x]->setVehicle(temp);
			count++;
		}
		if (map[MAX_CITY_Y - 1][x] != nullptr && map[MAX_CITY_Y - 1][x + 1] != nullptr)
		{
			temp = new Vehicle(x, MAX_CITY_Y);
			temp->setDirection(PI / 2);
			list.push_back(temp);
			map[MAX_CITY_Y - 1][x]->setVehicle(temp);
			count++;
		}
	}
	cout << "Created " << count << " cars\n";
}



int main()
{
	TransportMode *temp;
	MapOBJ *map[MAX_CITY_Y][MAX_CITY_X];	//an array of pointers to mapobj
	vector <TransportMode*> transportList;
	initializeMap(map);			//initialize array and put in the intersections (see function below)

	addIntersections(map);		//add intersections, by JGarcia
	cout << endl << endl;
	system("pause");

	makeRoads(map);				//now that the intersections are in put in the roads...
	createCars(transportList, map);

	printArray(map);			//prints the array



	cout << endl << endl;
	system("pause");
	return 0;
}

/*
Section by Jacqueline Garcia
Puts 9 real intersection onto MapOBJ at the top right. The intersectios are placed at
10-unit intervals(distance), both down and across.
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
			map[j][k]->setIntersection(new Intersection());
			map[j][k]->getIntersection()->setIntersectionID(intersectionToPlot[next]);
			map[j][k + 1] = map[j][k];
			map[j + 1][k] = map[j][k];
			map[j + 1][k + 1] = map[j][k];
			next++;
		}
	}

	//testing placement
	for (j = 0; j < 31; j++)
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







/**********************************   Initialize Array of pointers in Main   ****************************************  

Modified by spencemw 11-19-16
Adds language and a stub for the data team's methods to set intersections in the array after it is initialized
Some garbage commented out per Mike R.  

*********************************************************************************************************************/ 
void initializeMap(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])
{
	for (int i = 0; i < MAX_CITY_Y; i++)		//initialize the array with nullptrs
	{
		for (int j = 0; j < MAX_CITY_X; j++)
		{
			map[i][j] = nullptr;						
		}
	}
	
	//spencemw 12-2-16 removed stub that added fake instersections which came from intersectionDataSTUB.h & .cpp
}


/********************************************************************************************************************
This function puts roads on the array between intersections after intersections are installed.
spencemw 11-19-16, updated 12-2-16 to use new road.h and road.cpp instead of bool
*********************************************************************************************************************/
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

