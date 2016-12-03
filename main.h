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
void initializeMap(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X]);	//puts nullptr on the map
void addIntersections(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X]); //puts intersections on map
void printVector(vector<TransportMode*> tempList);	// just a temporary output function

void makeRoads(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X]);	//This function puts roads on the array between intersections after	
														//intersections are installed.  spencemw 11 - 19 - 16
void printArray(MapOBJ *map[MAX_CITY_Y][MAX_CITY_X]);	//This function crudely prints the array for testing purposes. spencemw 11-19-16


	//leaving these up here because changes will prolly need to be made. -Mike


