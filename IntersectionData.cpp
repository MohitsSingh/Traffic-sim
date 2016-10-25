/******************
Contributors
Wesley Stutzman

*******************/
#pragma once
#include "Includes.h"

IntersectionData::IntersectionData()
{
	numberOfIntersections = 1000;
	setPointers();
	myDataReader = new DataReader;
	myDataReader->readData("traficData.csv");
	readLinkData();
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

	upIDNB = new int[numberOfIntersections];				//Id of intersection prior to current one
	upIDSB = new int[numberOfIntersections];				//Id of intersection prior to current one
	upIDEB = new int[numberOfIntersections];				//Id of intersection prior to current one
	upIDWB = new int[numberOfIntersections];				//Id of intersection prior to current one
	//Get from Link Data Set (4,3-6)


	//Get from Phasing Data set (5,(3 - 11))
	minGreenD1 = new int[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD2 = new int[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD3 = new int[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD4 = new int[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD5 = new int[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD6 = new int[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD7 = new int[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD8 = new int[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD9 = new int[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD10 = new int[numberOfIntersections];			// ? minimum seconds for a green light
	minGreenD14 = new int[numberOfIntersections];			// ? minimum seconds for a green light

	//Get from Phasing Data set (6,(3 - 11))
	maxGreenD1 = new int[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD2 = new int[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD3 = new int[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD4 = new int[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD5 = new int[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD6 = new int[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD7 = new int[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD8 = new int[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD9 = new int[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD10 = new int[numberOfIntersections];			// ? maximum seconds for a green light
	maxGreenD14 = new int[numberOfIntersections];			// ? maximum seconds for a green light

	//Get from Phasing Data set (11,(3 - 8))
	yellowD1 = new int[numberOfIntersections];				// ? seconds for a yellow light
	yellowD2 = new int[numberOfIntersections];				// ? seconds for a yellow light
	yellowD3 = new int[numberOfIntersections];				// ? seconds for a yellow light
	yellowD4 = new int[numberOfIntersections];				// ? seconds for a yellow light
	yellowD5 = new int[numberOfIntersections];				// ? seconds for a yellow light
	yellowD6 = new int[numberOfIntersections];				// ? seconds for a yellow light
	yellowD7 = new int[numberOfIntersections];				// ? seconds for a yellow light
	yellowD8 = new int[numberOfIntersections];				// ? seconds for a yellow light

	//Get from Phasing Data set (12,(3 - 8))
	allRedD1 = new int[numberOfIntersections];				// ? seconds for a red light in all directions
	allRedD2 = new int[numberOfIntersections];				// ? seconds for a red light in all directions
	allRedD3 = new int[numberOfIntersections];				// ? seconds for a red light in all directions
	allRedD4 = new int[numberOfIntersections];				// ? seconds for a red light in all directions
	allRedD5 = new int[numberOfIntersections];				// ? seconds for a red light in all directions
	allRedD6 = new int[numberOfIntersections];				// ? seconds for a red light in all directions
	allRedD7 = new int[numberOfIntersections];				// ? seconds for a red light in all directions
	allRedD8 = new int[numberOfIntersections];				// ? seconds for a red light in all directions

	//Get from Phasing Data set (14,(3 - 8))
	walkD1 = new int[numberOfIntersections];				// ? seconds for a walk light 
	walkD2 = new int[numberOfIntersections];				// ? seconds for a walk light 
	walkD3 = new int[numberOfIntersections];				// ? seconds for a walk light 
	walkD4 = new int[numberOfIntersections];				// ? seconds for a walk light 
	walkD5 = new int[numberOfIntersections];				// ? seconds for a walk light 
	walkD6 = new int[numberOfIntersections];				// ? seconds for a walk light
	walkD7 = new int[numberOfIntersections];				// ? seconds for a walk light 
	walkD8 = new int[numberOfIntersections];				// ? seconds for a walk light 
	walkD9 = new int[numberOfIntersections];				// ? seconds for a walk light 
	walkD10 = new int[numberOfIntersections];				// ? seconds for a walk light 
	walkD14 = new int[numberOfIntersections];				// ? seconds for a walk light 

	//Get from Phasing Data set (15,(3 - 8))
	dontwalkD1 = new int[numberOfIntersections];			//? seconds for don't walk light
	dontwalkD2 = new int[numberOfIntersections];			//? seconds for don't walk light
	dontwalkD3 = new int[numberOfIntersections];			//? seconds for don't walk light
	dontwalkD4 = new int[numberOfIntersections];			//? seconds for don't walk light
	dontwalkD5 = new int[numberOfIntersections];			//? seconds for don't walk light
	dontwalkD6 = new int[numberOfIntersections];			//? seconds for don't walk light
	dontwalkD7 = new int[numberOfIntersections];			//? seconds for don't walk light
	dontwalkD8 = new int[numberOfIntersections];			//? seconds for don't walk light

	//Get from Phasing Data set (22,(3 - 8))
	yieldD1 = new int[numberOfIntersections];				//? seconds for  yeild light
	yieldD2 = new int[numberOfIntersections];				//? seconds for  yeild light
	yieldD3 = new int[numberOfIntersections];				//? seconds for  yeild light
	yieldD4 = new int[numberOfIntersections];				//? seconds for  yeild light
	yieldD5 = new int[numberOfIntersections];				//? seconds for  yeild light
	yieldD6 = new int[numberOfIntersections];				//? seconds for  yeild light
	yieldD7 = new int[numberOfIntersections];				//? seconds for  yeild light
	yieldD8 = new int[numberOfIntersections];				//? seconds for  yeild light
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

	delete []upIDNB;				//Id of intersection prior to current one
	delete []upIDSB;				//Id of intersection prior to current one
	delete []upIDEB;				//Id of intersection prior to current one
	delete []upIDWB;				//Id of intersection prior to current one
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
	delete []dontwalkD1;			//? seconds for don't walk light
	delete []dontwalkD2;			//? seconds for don't walk light
	delete []dontwalkD3;			//? seconds for don't walk light
	delete []dontwalkD4;			//? seconds for don't walk light
	delete []dontwalkD5;			//? seconds for don't walk light
	delete []dontwalkD6;			//? seconds for don't walk light
	delete []dontwalkD7;			//? seconds for don't walk light
	delete []dontwalkD8;			//? seconds for don't walk light


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
//now all we need to do when we want information is call an information type and return an array location inside that type based on the itesm id number
string IntersectionData::getNbName(int inputId)
{
	return nameNB[inputId];
}
string IntersectionData::getSbName(int inputId)
{
	return nameSB[inputId];
}
string IntersectionData::getEbName(int inputId)
{
	return nameEB[inputId];
}
string IntersectionData::getWbName(int inputId)
{
	return nameWB[inputId];
}


//start be knowing all the information needed to be read is between lines 532-10411
//so loop based on how many lines are still needing to be read
//first grab out the items number from the cell and store it in the array based on that location
//the store each itesms infomration in an array in the location of that item as well
//move to the next collom based on information needing to be read
//then lastly skip 16 lines to move to the same place of the next cell
void IntersectionData::readLinkData()
{
	// fix the above with right dataset
	int lineToRead = 532;																//start on line 532 (this keeps track of the line number to read in on)
	while (lineToRead < 10411)
	{
		int itemNumber = stoi(myDataReader->getDataCell(lineToRead, 2));				//store the item into the array based on its id number (this allows items to be skiped unlick the for loop)
		//row of intersection ID number
		upIDNB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 3));
		upIDSB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 4));
		upIDEB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 5));
		upIDWB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 6));
		lineToRead++;																	//move on to the next row of information to store

		lanesNB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 3));			//read in lanes data
		lanesSB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 4));
		lanesEB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 5));
		lanesWB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 6));
		lineToRead++;

		nameNB[itemNumber] = myDataReader->getDataCell(lineToRead, 3);					//read in name data
		nameSB[itemNumber] = myDataReader->getDataCell(lineToRead, 4);
		nameEB[itemNumber] = myDataReader->getDataCell(lineToRead, 5);
		nameWB[itemNumber] = myDataReader->getDataCell(lineToRead, 6);
		lineToRead++;

		distanceNB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 3));		//Distance to the intersection id of the road previous to this intersection
		distanceSB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 4));
		distanceEB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 5));
		distanceWB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 6));
		lineToRead++;

		speedLimitNB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 3));		//Speed limit in this intersection going NB
		speedLimitSB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 4));
		speedLimitEB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 5));
		speedLimitWB[itemNumber] = stoi(myDataReader->getDataCell(lineToRead, 6));
		lineToRead += 16;
	}
}
