#pragma once
#include "Includes.h"
#include "MapOBJ.h"
#include "TransportMode.h"

class MapOBJ;
class TransportMode;

vector<TransportMode*> fillVector();	//
void initializeDirection(vector<TransportMode*> tempList);	// sets every object's direction to one of the cardinal directions
void initializeAcceleration(vector<TransportMode*> tempList);	// sets every object's acceleration to 0, 3, or 4 m/s/s
void initializeCurrentSpeed(vector<TransportMode*> tempList);	// sets every object's speed to 10 m/s
void initializeMap(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X], vector<TransportMode*> tempList);	//puts all the vehicles on the map
void printVector(vector<TransportMode*> tempList);	// just a temporary output function


//leaving these up here because changes will prolly need to be made. -Mike
MapOBJ* findClosest(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X], int x, int y, CARDINAL direction)
{
	switch (direction)
	{
	case NORTH:
		for (int i = y - 1; i > 0; i--)
		{
			if (y > 0 && map[i][x]->getClassType() == TRANSPORTMODE)
			{
				return map[i][x];
			}
		}
		break;
	case SOUTH:
		for (int i = y + 1; i < MAX_CITY_Y; i++)
		{
			if (y < MAX_CITY_Y && map[i][x]->getClassType() == TRANSPORTMODE)
			{
				return map[i][x];
			}
		}
		break;
	case EAST:
		for (int i = x + 1; i < MAX_CITY_X; i++)
		{
			if (x < MAX_CITY_X && map[y][i]->getClassType() == TRANSPORTMODE)
			{
				return map[y][i];
			}
		}
		break;
	case WEST:
		for (int i = x - 1; i > 0; i--)
		{
			if (x > 0 && map[y][i]->getClassType() == TRANSPORTMODE)
			{
				return map[y][i];
			}
		}
		break;
	default:
		cout << "\nError in defualt of findClosest\n";
		break;
	}
	return nullptr;
}
int calcDistance(MapOBJ *start, MapOBJ *end)
{
	int totalDis = 0;
	totalDis += start->getX() - end->getX();
	totalDis += start->getY() - end->getY();
	totalDis = abs(totalDis);
	return totalDis;
}
