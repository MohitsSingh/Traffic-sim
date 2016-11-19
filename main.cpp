/***************************************************************************************
David Sant
Spence Wilson
Isaac Haas
Last submitted on: 10/22/16
last update: 11/19/16
Uses: all of the files

This is a real clean version of main that removes everything not related to what I was adding.  

Added a intersectionsDataSTUB.H and .cpp file that take in the array of MapOBJs add put 
intersections on the array.  

(these STUB files will be replaced with real files by the data team)

Added a function to main that puts roads between the intersections as well as 
	to the edge of the array

Modified MapOBJ to add a constructor 'map[r][x] = new MapOBJ(true)' that accepts a bool
	value.  This bool makes road1 true.

Added a function that outputs the resutls

***************************************************************************************/

#include "Includes.h"
#include "MapOBJ.h"
#include "TransportMode.h"
#include "intersectionDataSTUB.h"
#include "main.h"
#include "Vehicle.h"
#include "Bus.h"
#include "Car.h"
#include "Semi.h"
#include "Sportscar.h"
#include "Truck.h"
#include "Van.h"
#include "Intersection.h"

int TransportMode::id = 0;

int main()
{
	MapOBJ *map[MAX_CITY_Y][MAX_CITY_X];	//an array of pointers to mapobj

	initializeMap(map);			//initialize array and put in the intersections (see function below)
	
	makeRoads(map);				//now that the intersections are in put in the roads...

	printArray(map);			//prints the array


	cout << endl << endl;
	system("pause");
	return 0;
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

	/****************************  STUB STUB STUB STUB STUB  ***************************** 

	pass the entire array to data team.  
	something like.... 
	
	#include "intersectionData.h" (from data team)
	'addIntersections(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])'
	
	map comes back with the intersections only in it.  
	11-19-16 spencemw, Isaac, Jackie, David

	***************************************************************************************/		

	intersectionData::addIntersections(map);  //Set intersections from the intersectionDataSTUB.h

}


/********************************************************************************************************************
This function puts roads on the array between intersections after intersections are installed.
spencemw 11-19-16
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
							map[r][x] = new MapOBJ(true);				//put in a section of road
						}
						r++;

					}//end while put roads in row

					int c = 0;									//go to the edge of the array
					while (c < MAX_CITY_X)						//step thru the array until you get to the opp edge
					{
						if (map[y][c] == nullptr)					//at each empty element...
						{
							map[y][c] = new MapOBJ(true);				//put in a section of road
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
spencemw 11-19-16
*********************************************************************************************************************/
void printArray(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X])
{
	for (int y = 0; y < MAX_CITY_Y; y++)
	{
		for (int x = 0; x < MAX_CITY_X; x++)		//scan the array from 0,0
		{
			string str = ".";

			if (map[y][x] != nullptr)					//check each element for a MapOBJ....
			{
				if (map[y][x]->getIntersection() != nullptr)
				{
					str = "I";
				}
				else
					str = "X";

			}//end if map[y][x] != nullptr

			cout << str;

		}//end for y

		cout << endl;

	}//end for x
}

