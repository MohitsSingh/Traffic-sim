/******************
Contributors
Wesley Stutzman
Jacqueline Garcia
Andrew
Danni

*******************/
#pragma once
#include "Includes.h"

IntersectionData::IntersectionData()
{
	numberOfIntersections = 1000;
	setPointers();
	myDataReader = new DataReader;
	myDataReader->readData("traficData.csv");
	setLinkData();
	setPhasingData();
}
void IntersectionData::setPointers()
{
	nameNB = new string[numberOfIntersections];				//Name of northbound street
	nameSB = new string[numberOfIntersections];				//Name of southbound street
	nameEB = new string[numberOfIntersections];				//Name of eastbound street
	nameWB = new string[numberOfIntersections];				//Name of westbound street
	//Get frpom Link Data set (534, (3,4,5,6))

	lanesNB = new int[numberOfIntersections];				//Number of lanes in northbound street
	lanesSB = new int[numberOfIntersections];				//Number of lanes in southbound street
	lanesEB = new int[numberOfIntersections];				//Number of lanes in eastbound street
	lanesWB = new int[numberOfIntersections];				//Number of lanes in westbound street
	//Get from Link Data set (533,(3,4,5,6))


	distanceNB = new int[numberOfIntersections];			//Distance to the intersection id of the road previous to this intersection
	distanceSB = new int[numberOfIntersections];			//Distance to the intersection id of the road previous to this intersection
	distanceEB = new int[numberOfIntersections];			//Distance to the intersection id of the road previous to this intersection
	distanceWB = new int[numberOfIntersections];			//Distance to the intersection id of the road previous to this intersection
	//Get from Link Data set (7,(3,4,5,6))

	speedLimitNB = new int[numberOfIntersections];			//Speed limit in this intersection going NB
	speedLimitSB = new int[numberOfIntersections];			//Speed limit in this intersection going SB
	speedLimitEB = new int[numberOfIntersections];			//Speed limit in this intersection going EB
	speedLimitWB = new int[numberOfIntersections];			//Speed limit in this intersection going WB
	//Get from Link Data set (8,3-6)

	upIdNB = new int[numberOfIntersections];				//Id of intersection prior to current one
	upIdSB = new int[numberOfIntersections];				//Id of intersection prior to current one
	upIdEB = new int[numberOfIntersections];				//Id of intersection prior to current one
	upIdWB = new int[numberOfIntersections];				//Id of intersection prior to current one
	//Get from Link Data Set (4,3-6)


	//Get from Phasing Data set (23246,(3 - 11))
	minGreenD1 = new double[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD2 = new double[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD3 = new double[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD4 = new double[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD5 = new double[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD6 = new double[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD7 = new double[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD8 = new double[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD9 = new double[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD10 = new double[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD14 = new double[numberOfIntersections];			// ? minimum seconds for a green light

	//Get from Phasing Data set (23247,(3 - 11))
	maxGreenD1 = new double[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD2 = new double[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD3 = new double[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD4 = new double[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD5 = new double[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD6 = new double[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD7 = new double[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD8 = new double[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD9 = new double[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD10 = new double[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD14 = new double[numberOfIntersections];			// ? maximum seconds for a green light

	//Get from Phasing Data set (23252,(3 - 8))
	yellowD1 = new double[numberOfIntersections];				// ? seconds for a yellow light
	yellowD2 = new double[numberOfIntersections];				// ? seconds for a yellow light
	yellowD3 = new double[numberOfIntersections];				// ? seconds for a yellow light
	yellowD4 = new double[numberOfIntersections];				// ? seconds for a yellow light
	yellowD5 = new double[numberOfIntersections];				// ? seconds for a yellow light
	yellowD6 = new double[numberOfIntersections];				// ? seconds for a yellow light
	yellowD7 = new double[numberOfIntersections];				// ? seconds for a yellow light
	yellowD8 = new double[numberOfIntersections];				// ? seconds for a yellow light

	//Get from Phasing Data set (23253,(23253 - 8))
	allRedD1 = new double[numberOfIntersections];				// ? seconds for a red light in all directions
	allRedD2 = new double[numberOfIntersections];				// ? seconds for a red light in all directions
	allRedD3 = new double[numberOfIntersections];				// ? seconds for a red light in all directions
	allRedD4 = new double[numberOfIntersections];				// ? seconds for a red light in all directions
	allRedD5 = new double[numberOfIntersections];				// ? seconds for a red light in all directions
	allRedD6 = new double[numberOfIntersections];				// ? seconds for a red light in all directions
	allRedD7 = new double[numberOfIntersections];				// ? seconds for a red light in all directions
	allRedD8 = new double[numberOfIntersections];				// ? seconds for a red light in all directions

	//Get from Phasing Data set (23255,(3 - 8))
	walkD1 = new double[numberOfIntersections];				// ? seconds for a walk light 
	walkD2 = new double[numberOfIntersections];				// ? seconds for a walk light 
	walkD3 = new double[numberOfIntersections];				// ? seconds for a walk light 
	walkD4 = new double[numberOfIntersections];				// ? seconds for a walk light 
	walkD5 = new double[numberOfIntersections];				// ? seconds for a walk light 
	walkD6 = new double[numberOfIntersections];				// ? seconds for a walk light
	walkD7 = new double[numberOfIntersections];				// ? seconds for a walk light 
	walkD8 = new double[numberOfIntersections];				// ? seconds for a walk light 
	walkD9 = new double[numberOfIntersections];				// ? seconds for a walk light 
	walkD10 = new double[numberOfIntersections];				// ? seconds for a walk light 
	walkD14 = new double[numberOfIntersections];				// ? seconds for a walk light 

	//Get from Phasing Data set (23256,(3 - 8))
	dontWalkD1 = new double[numberOfIntersections];			//? seconds for don't walk light
	dontWalkD2 = new double[numberOfIntersections];			//? seconds for don't walk light
	dontWalkD3 = new double[numberOfIntersections];			//? seconds for don't walk light
	dontWalkD4 = new double[numberOfIntersections];			//? seconds for don't walk light
	dontWalkD5 = new double[numberOfIntersections];			//? seconds for don't walk light
	dontWalkD6 = new double[numberOfIntersections];			//? seconds for don't walk light
	dontWalkD7 = new double[numberOfIntersections];			//? seconds for don't walk light
	dontWalkD8 = new double[numberOfIntersections];			//? seconds for don't walk light

	//Get from Phasing Data set (23263,(3 - 8))
	yieldD1 = new double[numberOfIntersections];				//? seconds for  yeild light
	yieldD2 = new double[numberOfIntersections];				//? seconds for  yeild light
	yieldD3 = new double[numberOfIntersections];				//? seconds for  yeild light
	yieldD4 = new double[numberOfIntersections];				//? seconds for  yeild light
	yieldD5 = new double[numberOfIntersections];				//? seconds for  yeild light
	yieldD6 = new double[numberOfIntersections];				//? seconds for  yeild light
	yieldD7 = new double[numberOfIntersections];				//? seconds for  yeild light
	yieldD8 = new double[numberOfIntersections];				//? seconds for  yeild light
}
IntersectionData::~IntersectionData()
{
	delete[]myDataReader;	

	delete []nameNB;			//Name of northbound street
	delete []nameSB;			//Name of southbound street
	delete []nameEB;			//Name of eastbound street
	delete []nameWB;			//Name of westbound street
							//Get frpom Link Data set (534, (3,4,5,6))

	delete []lanesNB;			//Number of lanes in northbound street
	delete []lanesSB;			//Number of lanes in southbound street
	delete []lanesEB;			//Number of lanes in eastbound street
	delete []lanesWB;			//Number of lanes in westbound street
							//Get from Link Data set (533,(3,4,5,6))


	delete []distanceNB;		//Distance to the intersection id of the road previous to this intersection
	delete []distanceSB;		//Distance to the intersection id of the road previous to this intersection
	delete []distanceEB;		//Distance to the intersection id of the road previous to this intersection
	delete []distanceWB;		//Distance to the intersection id of the road previous to this intersection
							//Get from Link Data set (7,(3,4,5,6))

	delete []speedLimitNB;		//Speed limit in this intersection going NB
	delete []speedLimitSB;		//Speed limit in this intersection going SB
	delete []speedLimitEB;		//Speed limit in this intersection going EB
	delete []speedLimitWB;		//Speed limit in this intersection going WB
							//Get from Link Data set (8,3-6)

	delete []upIdNB;				//Id of intersection prior to current one
	delete []upIdSB;				//Id of intersection prior to current one
	delete []upIdEB;				//Id of intersection prior to current one
	delete []upIdWB;				//Id of intersection prior to current one
								//Get from Link Data Set (4,3-6)



								//Get from Phasing Data set (5,(3 - 11))
	delete []minGreenD1;			// ? minimum seconds for a green light
	delete []minGreenD2;			// ? minimum seconds for a green light
	delete []minGreenD3;			// ? minimum seconds for a green light
	delete []minGreenD4;			// ? minimum seconds for a green light
	delete []minGreenD5;			// ? minimum seconds for a green light
	delete []minGreenD6;			// ? minimum seconds for a green light
	delete []minGreenD7;			// ? minimum seconds for a green light
	delete []minGreenD8;			// ? minimum seconds for a green light
	delete []minGreenD9;			// ? minimum seconds for a green light
	delete []minGreenD10;			// ? minimum seconds for a green light
	delete []minGreenD14;			// ? minimum seconds for a green light


								//Get from Phasing Data set (6,(3 - 11))
	delete []maxGreenD1;			// ? maximum seconds for a green light
	delete []maxGreenD2;			// ? maximum seconds for a green light
	delete []maxGreenD3;			// ? maximum seconds for a green light
	delete []maxGreenD4;			// ? maximum seconds for a green light
	delete []maxGreenD5;			// ? maximum seconds for a green light
	delete []maxGreenD6;			// ? maximum seconds for a green light
	delete []maxGreenD7;			// ? maximum seconds for a green light
	delete []maxGreenD8;			// ? maximum seconds for a green light
	delete []maxGreenD9;			// ? maximum seconds for a green light
	delete []maxGreenD10;			// ? maximum seconds for a green light
	delete []maxGreenD14;			// ? maximum seconds for a green light

								//Get from Phasing Data set (11,(3 - 8))
	delete []yellowD1;				// ? seconds for a yellow light
	delete []yellowD2;				// ? seconds for a yellow light
	delete []yellowD3;				// ? seconds for a yellow light
	delete []yellowD4;				// ? seconds for a yellow light
	delete []yellowD5;				// ? seconds for a yellow light
	delete []yellowD6;				// ? seconds for a yellow light
	delete []yellowD7;				// ? seconds for a yellow light
	delete []yellowD8;				// ? seconds for a yellow light


								//Get from Phasing Data set (12,(3 - 8))
	delete []allRedD1;				// ? seconds for a red light in all directions
	delete []allRedD2;				// ? seconds for a red light in all directions
	delete []allRedD3;				// ? seconds for a red light in all directions
	delete []allRedD4;				// ? seconds for a red light in all directions
	delete []allRedD5;				// ? seconds for a red light in all directions
	delete []allRedD6;				// ? seconds for a red light in all directions
	delete []allRedD7;				// ? seconds for a red light in all directions
	delete []allRedD8;				// ? seconds for a red light in all directions


								//Get from Phasing Data set (14,(3 - 8))
	delete []walkD1;				// ? seconds for a walk light 
	delete []walkD2;				// ? seconds for a walk light 
	delete []walkD3;				// ? seconds for a walk light 
	delete []walkD4;				// ? seconds for a walk light 
	delete []walkD5;				// ? seconds for a walk light 
	delete []walkD6;				// ? seconds for a walk light
	delete []walkD7;				// ? seconds for a walk light 
	delete []walkD8;				// ? seconds for a walk light 
	delete []walkD9;				// ? seconds for a walk light 
	delete []walkD10;				// ? seconds for a walk light 
	delete []walkD14;				// ? seconds for a walk light 

								//Get from Phasing Data set (15,(3 - 8))
	delete []dontWalkD1;			//? seconds for don't walk light
	delete []dontWalkD2;			//? seconds for don't walk light
	delete []dontWalkD3;			//? seconds for don't walk light
	delete []dontWalkD4;			//? seconds for don't walk light
	delete []dontWalkD5;			//? seconds for don't walk light
	delete []dontWalkD6;			//? seconds for don't walk light
	delete []dontWalkD7;			//? seconds for don't walk light
	delete []dontWalkD8;			//? seconds for don't walk light


								//Get from Phasing Data set (22,(3 - 8))
	delete []yieldD1;			//? seconds for  yeild light
	delete []yieldD2;			//? seconds for  yeild light
	delete []yieldD3;			//? seconds for  yeild light
	delete []yieldD4;			//? seconds for  yeild light
	delete []yieldD5;			//? seconds for  yeild light
	delete []yieldD6;			//? seconds for  yeild light
	delete []yieldD7;			//? seconds for  yeild light
	delete []yieldD8;			//? seconds for  yeild light
}

//**Add code after here!!
//**
//**

//now all we need to do when we want information is call an information type and return an array location inside that type based on the itesm id number
//Link Data set variables

string IntersectionData::getNameNB(int inputId)
{
	return nameNB[inputId];
}
string IntersectionData::getNameSB(int inputId)
{
	return nameSB[inputId];
}
string IntersectionData::getNameEB(int inputId)
{
	return nameEB[inputId];
}
string IntersectionData::getNameWB(int inputId)
{
	return nameWB[inputId];
}

int IntersectionData::getUpIdNB(int inputId)
{
	return upIdNB[inputId];
}
int IntersectionData::getUpIdSB(int inputId)
{
	return upIdSB[inputId];
}
int IntersectionData::getUpIdWB(int inputId)
{
	return upIdNB[inputId];
}
int IntersectionData::getUpIdEB(int inputId)
{
	return upIdSB[inputId];
}

int IntersectionData::getLanesNB(int inputId)
{
	return lanesNB[inputId];
}
int IntersectionData::getLanesSB(int inputId)
{
	return lanesSB[inputId];
}
int IntersectionData::getLanesWB(int inputId)
{
	return lanesWB[inputId];
}
int IntersectionData::getLanesEB(int inputId)
{
	return lanesEB[inputId];
}

int IntersectionData::getDistanceNB(int inputId)
{
	return distanceNB[inputId];
}
int IntersectionData::getDistanceSB(int inputId)
{
	return distanceSB[inputId];
}
int IntersectionData::getDistanceEB(int inputId)
{
	return distanceEB[inputId];
}
int IntersectionData::getDistanceWB(int inputId)
{
	return distanceWB[inputId];
}

int IntersectionData::getSpeedLimitNB(int inputId)
{
	return speedLimitNB[inputId];
}
int IntersectionData::getSpeedLimitSB(int inputId)
{
	return speedLimitSB[inputId];
}
int IntersectionData::getSpeedLimitEB(int inputId)
{
	return speedLimitEB[inputId];
}
int IntersectionData::getSpeedLimitWB(int inputId)
{
	return speedLimitWB[inputId];
}


//Phasing Data Set

//Get from Phasing Data set (23246,(3 - 11)) (+24)


double IntersectionData::getMinGreenD1(int inputId)
{
	return minGreenD1[inputId];
}
double IntersectionData::getMinGreenD2(int inputId)
{
	return minGreenD2[inputId];
}
double IntersectionData::getMinGreenD3(int inputId)
{
	return minGreenD3[inputId];
}
double IntersectionData::getMinGreenD4(int inputId)
{
	return minGreenD4[inputId];
}
double IntersectionData::getMinGreenD5(int inputId)
{
	return minGreenD5[inputId];
}
double IntersectionData::getMinGreenD6(int inputId)
{
	return minGreenD6[inputId];
}
double IntersectionData::getMinGreenD7(int inputId)
{
	return minGreenD7[inputId];
}
double IntersectionData::getMinGreenD8(int inputId)
{
	return minGreenD8[inputId];
}
double IntersectionData::getMinGreenD9(int inputId)
{
	return minGreenD9[inputId];
}
double IntersectionData::getMinGreenD10(int inputId)
{
	return minGreenD10[inputId];
}
double IntersectionData::getMinGreenD14(int inputId)
{
	return minGreenD14[inputId];
}



double IntersectionData::getMaxGreenD1(int inputId)
{
	return maxGreenD1[inputId];
}
double IntersectionData::getMaxGreenD2(int inputId)
{
	return maxGreenD2[inputId];
}
double IntersectionData::getMaxGreenD3(int inputId)
{
	return maxGreenD3[inputId];
}
double IntersectionData::getMaxGreenD4(int inputId)
{
	return maxGreenD4[inputId];
}
double IntersectionData::getMaxGreenD5(int inputID)
{
	return maxGreenD5[inputID];
}
double IntersectionData::getMaxGreenD6(int inputId)
{
	return maxGreenD6[inputId];
}
double IntersectionData::getMaxGreenD7(int inputId)
{
	return maxGreenD7[inputId];
}
double IntersectionData::getMaxGreenD8(int inputId)
{
	return maxGreenD8[inputId];
}
double IntersectionData::getMaxGreenD9(int inputId)
{
	return maxGreenD9[inputId];
}
double IntersectionData::getMaxGreenD10(int inputId)
{
	return maxGreenD10[inputId];
}
double IntersectionData::getMaxGreenD14(int inputId)
{
	return maxGreenD14[inputId];
}

double IntersectionData::getYellowD1(int inputId)
{
	return yellowD1[inputId];
}
double IntersectionData::getYellowD2(int inputId)
{
	return yellowD2[inputId];
}
double IntersectionData::getYellowD3(int inputId)
{
	return yellowD3[inputId];
}
double IntersectionData::getYellowD4(int inputId)
{
	return yellowD4[inputId];
}
double IntersectionData::getYellowD5(int inputId)
{
	return yellowD5[inputId];
}
double IntersectionData::getYellowD6(int inputId)
{
	return yellowD6[inputId];
}
double IntersectionData::getYellowD7(int inputId)
{
	return yellowD7[inputId];
}
double IntersectionData::getYellowD8(int inputId)
{
	return yellowD8[inputId];
}

double IntersectionData::getAllRedD1(int inputId) // ? seconds for a red light in all directions
{
	return allRedD1[inputId];
}
double IntersectionData::getAllRedD2(int inputId) // ? seconds for a red light in all directions
{
	return allRedD2[inputId];
}
double IntersectionData::getAllRedD3(int inputId) // ? seconds for a red light in all directions
{
	return allRedD3[inputId];
}
double IntersectionData::getAllRedD4(int inputId) // ? seconds for a red light in all directions
{
	return allRedD4[inputId];
}
double IntersectionData::getAllRedD5(int inputId) // ? seconds for a red light in all directions
{
	return allRedD5[inputId];
}
double IntersectionData::getAllRedD6(int inputId) // ? seconds for a red light in all directions
{
	return allRedD6[inputId];
}
double IntersectionData::getAllRedD7(int inputId) // ? seconds for a red light in all directions
{
	return allRedD7[inputId];
}
double IntersectionData::getAllRedD8(int inputId) // ? seconds for a red light in all directions
{
	return allRedD8[inputId];
}

double IntersectionData::getWalkD1(int inputId)    // ? seconds for a walk light 
{
	return walkD1[inputId];
}
double IntersectionData::getWalkD2(int inputId)    // ? seconds for a walk light 
{
	return walkD2[inputId];
}
double IntersectionData::getWalkD3(int inputId)    // ? seconds for a walk light 
{
	return walkD3[inputId];
}
double IntersectionData::getWalkD4(int inputId)    // ? seconds for a walk light 
{
	return walkD4[inputId];
}
double IntersectionData::getWalkD5(int inputId)    // ? seconds for a walk light 
{
	return walkD5[inputId];
}
double IntersectionData::getWalkD6(int inputId)    // ? seconds for a walk light 
{
	return walkD6[inputId];
}
double IntersectionData::getWalkD7(int inputId)    // ? seconds for a walk light 
{
	return walkD7[inputId];
}
double IntersectionData::getWalkD8(int inputId)    // ? seconds for a walk light 
{
	return walkD8[inputId];
}
double IntersectionData::getWalkD9(int inputId)    // ? seconds for a walk light 
{
	return walkD9[inputId];
}
double IntersectionData::getWalkD10(int inputId)    // ? seconds for a walk light 
{
	return walkD10[inputId];
}
double IntersectionData::getWalkD14(int inputId)    
{
	return walkD14[inputId];
}



double IntersectionData::getDontWalkD1(int inputId)			//? seconds for don't walk light
{
	return dontWalkD1[inputId];
}
double IntersectionData::getDontWalkD2(int inputId)			
{
	return dontWalkD2[inputId];
}
double IntersectionData::getDontWalkD3(int inputId)			
{
	return dontWalkD3[inputId];
}
double IntersectionData::getDontWalkD4(int inputId)			//? seconds for don't walk light
{
	return dontWalkD4[inputId];
}
double IntersectionData::getDontWalkD5(int inputId)			//? seconds for don't walk light
{
	return dontWalkD5[inputId];
}
double IntersectionData::getDontWalkD6(int inputId)		
{
	return dontWalkD6[inputId];
}
double IntersectionData::getDontWalkD7(int inputId)
{
	return dontWalkD7[inputId];
}
double IntersectionData::getDontWalkD8(int inputId)			//? seconds for don't walk light
{
	return dontWalkD8[inputId];
}

double IntersectionData::getYieldD1(int inputId)
{
	return yieldD1[inputId];
}
double IntersectionData::getYieldD2(int inputId)
{
	return yieldD2[inputId];
}
double IntersectionData::getYieldD3(int inputId)
{
	return yieldD3[inputId];
}
double IntersectionData::getYieldD4(int inputId)
{
	return yieldD4[inputId];
}
double IntersectionData::getYieldD5(int inputId)
{
	return yieldD5[inputId];
}
double IntersectionData::getYieldD6(int inputId)
{
	return yieldD6[inputId];
}
double IntersectionData::getYieldD7(int inputId)
{
	return yieldD7[inputId];
}
double IntersectionData::getYieldD8(int inputId)
{
	return yieldD8[inputId];
}



//start be knowing all the information needed to be read is between lines 532-10411
//int IntersectionData::getSpeedLimitNB(int inputID)

//so loop based on how many lines are still needing to be read
//first grab out the items number from the cell and store it in the array based on that location
//the store each itesms infomration in an array in the location of that item as well
//move to the next collom based on information needing to be read
//then lastly skip 16 lines to move to the same place of the next cell
void IntersectionData::setLinkData()
{
	// fix the above with right dataset
	int lineToRead = 532;																//start on line 532 (this keeps track of the line number to read in on)
	while (lineToRead < 10411)
	{
		int itemNumber = stoi(myDataReader->getDataCell(lineToRead, 2));				
		//row of intersection ID number
		upIdNB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 3));
		upIdSB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 4));
		upIdEB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 5));
		upIdWB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 6));
		lineToRead++;																	

		lanesNB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 3));			
		lanesSB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 4));
		lanesEB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 5));
		lanesWB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 6));
		lineToRead++;

		nameNB[itemNumber] = myDataReader->getDataCell(lineToRead, 3);
		nameSB[itemNumber] = myDataReader->getDataCell(lineToRead, 4);
		nameEB[itemNumber] = myDataReader->getDataCell(lineToRead, 5);
		nameWB[itemNumber] = myDataReader->getDataCell(lineToRead, 6);
		lineToRead++;

		distanceNB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 3));
		distanceSB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 4));
		distanceEB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 5));
		distanceWB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 6));
		lineToRead++;

		speedLimitNB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 3));		
		speedLimitSB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 4));
		speedLimitEB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 5));
		speedLimitWB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 6));
		lineToRead += 16;
	}
}


//Phasing data starts at line 23246 and jumps 24 each cycle


void IntersectionData::setPhasingData()
{
	
	int lineToRead = 23246;
	while (lineToRead < 27759)
	{
		int itemNumber = stoi(myDataReader->getDataCell(lineToRead, 2));

		
		minGreenD1[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 3));
		minGreenD2[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 4));
		minGreenD3[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 5));
		minGreenD4[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 6));
		minGreenD5[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 7));
		minGreenD6[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 8));
		minGreenD7[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 9));
		minGreenD8[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 10));
		lineToRead++;

		maxGreenD1[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 3));
		maxGreenD2[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 4));
		maxGreenD3[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 5));
		maxGreenD4[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 6));
		maxGreenD5[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 7));
		maxGreenD6[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 8));
		maxGreenD7[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 9));
		maxGreenD8[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 10));
		lineToRead = lineToRead + 5;

		yellowD1[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 3));
		yellowD2[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 4));
		yellowD3[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 5));
		yellowD4[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 6));
		yellowD5[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 7));
		yellowD6[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 8));
		yellowD7[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 9));
		yellowD8[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 10));
		lineToRead++;

		allRedD1[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 3));
		allRedD2[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 4));
		allRedD3[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 5));
		allRedD4[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 6));
		allRedD5[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 7));
		allRedD6[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 8));
		allRedD7[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 9));
		allRedD8[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 10));
		lineToRead = lineToRead + 2;

		walkD1[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 3));
		walkD2[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 4));
		walkD3[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 5));
		walkD4[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 6));
		walkD5[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 7));
		walkD6[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 8));
		walkD7[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 9));
		walkD8[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 10));
		lineToRead = lineToRead + 1;

		dontWalkD1[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 3));
		dontWalkD2[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 4));
		dontWalkD3[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 5));
		dontWalkD4[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 6));
		dontWalkD5[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 7));
		dontWalkD6[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 8));
		dontWalkD7[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 9));
		dontWalkD8[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 10));
		lineToRead = lineToRead + 7;

		yieldD1[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 3));
		yieldD2[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 4));
		yieldD3[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 5));
		yieldD4[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 6));
		yieldD5[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 7));
		yieldD6[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 8));
		yieldD7[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 9));
		yieldD8[itemNumber] = stod(myDataReader->getDataCell(lineToRead, 10));
		lineToRead = lineToRead + 7;
	}

}



