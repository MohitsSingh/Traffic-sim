#pragma once
#include "Includes.h"
MapOBJ* findClosest(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X], int x, int y, CARDINAL direction);	//finds the closest object in the given direction from the starting (x,y) point
int calcDistance(MapOBJ *start, MapOBJ *end);	//find the distance between to objects on the map
vector<TransportMode*> fillVector();	//
void initializeDirection(vector<TransportMode*> tempList);	// sets every object's direction to one of the cardinal directions
void initializeAcceleration(vector<TransportMode*> tempList);	// sets every object's acceleration to 0, 3, or 4 m/s/s
void initializeCurrentSpeed(vector<TransportMode*> tempList);	// sets every object's speed to 10 m/s
void initializeMap(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X], vector<TransportMode*> tempList);	//puts all the vehicles on the map
void printVector(vector<TransportMode*> tempList);	// just a temporary output function