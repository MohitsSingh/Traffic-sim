
#pragma once
#include <string>
#include <iostream>
#include <iomanip>			//10/11 spencemw for setprecision and fixed in output
#include <Math.h>
#include <vector>
#include <fstream>
#include <cmath>	//added by Isaac Haas
using namespace std;



enum CARTYPES { UNDEFINED, MIDSIZE, VAN, TRUCK, SEMI, BUS, SPORT };
enum CARDINAL { NORTH, SOUTH, EAST, WEST };
const double PI = 3.14159265359;
const int TIME_INCREMENT = 1;

//proposed additions by spencemw.  These will be used to range bound the city as well notated the proper positions of things
const double MAXLONG = -105.153185;			//western city limit    40.569385, -105.153185 Longitude is vertical
const double MINLONG = -104.982092;			//eastern city limit	40.567903, -104.982092
const double MAXLAT = 40.639270;			//northern city limit	40.639270, -105.038198 Latitidue is horizontal
const double MINLAT = 40.474082;			//southern city limit	40.474082, -105.127653
const int COMPASSMIN = 1;             //North 360, East 090, South 180, West 270
const int COMPASSMAX = 360;            //North 360, East 090, South 180, West 270 (avoids 0 being used as North)
const double DELTA_GPS_TO_METERS = 1.1;   //when the GPS long lat position has changed 0.00001 the item has moved 1.1meters
const double DELTA_METERS_TO_GPS = 0.00001;  //when the meters change 1.1 the long lat position has changed 0.00001
const int MAX_CITY_X = 100;
const int MAX_CITY_Y = 100;

//typedef int myTime;

#include "MapOBJ.h"
#include "TransportMode.h"
#include "Vehicle.h"
#include "Pedestrian.h"
#include "Car.h"
#include "Van.h"
#include "Sportscar.h"
#include "Bus.h"
#include "Truck.h"
#include "Semi.h"
