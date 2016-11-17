#include "Includes.h"
#include "MapOBJ.h"


//Constructors
MapOBJ::MapOBJ(int xStartCoordinate, int yStartCoordinate)
{
	xPos = xStartCoordinate;
	yPos = yStartCoordinate;
	classType = MAPOBJ;
}

MapOBJ::MapOBJ()
{
	xPos = -1;
	yPos = -1;
	classType = MAPOBJ;
}

void MapOBJ::interPush(MapOBJ* modes)
{

}
vector <MapOBJ*> MapOBJ::interPop()
{
	vector <MapOBJ*> empty;
	return empty;
}


//Getters
int MapOBJ::getId()
{
	return -1;
}
CLASSTYPES MapOBJ::getClassType()
{
	return classType;
}
CARDINAL MapOBJ::getDesieredD()
{
	return CARDINAL();
}
int MapOBJ::getX()
{
	return xPos;
}
int MapOBJ::getY()
{
	return yPos;
}
double MapOBJ::getLatitude()
{
	return latitude;
}
double MapOBJ::getLongitude()
{
	return longitude;
}
int MapOBJ::getLength()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return -1;
}
int MapOBJ::getWidth()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return -1;
}
int MapOBJ::getWeight()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return -1;
}
int MapOBJ::getTraction()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return -1;
}
enum CARDINAL MapOBJ::getCardinalD()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return ERROR;
}
double MapOBJ::getMaxAcceleration()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return -1;
}
double MapOBJ::getbrakingPower()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return -1;
}
double MapOBJ::getAcceleration()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return -1;
}
int MapOBJ::getMinSpeed()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return -1;
}
int MapOBJ::getMaxSpeed()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return -1;
}
double MapOBJ::getCurrentSpeed()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return -1;
}
double MapOBJ::getDirection()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return -1;
}
int MapOBJ::getHazardRating()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return -1;
}
CARTYPES MapOBJ::getModel()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return CARTYPES::UNDEFINED;
}
bool MapOBJ::getEmergencyVehicle()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return nullptr;
}
bool MapOBJ::isActiveEmergency()		
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return nullptr;
}
bool MapOBJ::getOversized()
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
	return nullptr;
}


//Setters
void MapOBJ::setClassType(CLASSTYPES input)
{
	classType = input;
}
void MapOBJ::setDesieredD(CARDINAL value)
{
	
}
void MapOBJ::setX(int inputX)
{
	xPos = inputX;
}
void MapOBJ::setY(int inputY)
{
	yPos = inputY;
}
void MapOBJ::setLatitude(double input)
{
	latitude = input;
}
void MapOBJ::setLongitude(double input)
{
	longitude = input;
}
void MapOBJ::setCardinalD(enum CARDINAL inputCardinalD)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setbrakingPower(double inputbrakingPower)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setAcceleration(double inputAcceleration)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setMaxAcceleration(double inputSpeed)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setMinSpeed(int inputSpeed)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setMaxSpeed(int inputSpeed)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setCurrentSpeed(double inputSpeed)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setDirection(double inputDirection)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setHazardRating(int inputHazardRating)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setLength(int inputLength)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setWidth(int inputWidth)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setTraction(int inputTraction)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setOversized(bool inputOversized)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setModel(CARTYPES inputModel)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setEmergencyVehicle(bool inputEmergencyVehicle)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setActiveEmergency(bool input)	
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";
}
void MapOBJ::setWeight(int input)
{
	cout << "\nyou somehow called a empty funcion in MapOBJ\n";

}