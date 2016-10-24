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