#pragma once
#include "Includes.h"

IntersectionData::IntersectionData()
{
	numberOfIntersections = 600;
	myDataReader = new DataReader;
	myDataReader->readData("traficData.csv");
	myData = new DataClasses[numberOfIntersections];
	readLinkData();
}
string IntersectionData::getNbName(int inputIntersectionId)
{
	return myData[inputIntersectionId].nameNB;
}
void IntersectionData::readLinkData()
{

	int jump = 20;			//set jump variable to get to next dataset
	int k = 532;				//row of intersection ID number
	int l = 533;				//row of number of lanes data
	int m = 534;				//row  of Name data
	int n = 535;				//row of distance number
	int o = 536;				//row of speed data
	int i;

	// fix the above with right dataset




	for (i = 0; i < numberOfIntersections; i++)
	{
		//row of intersection ID number
		myData[i].ID = stoi(myDataReader->getDataCell(k, 2));

		myData[i].lanesNB = stoi(myDataReader->getDataCell(l, 3));		//read in lanes data
		myData[i].lanesSB = stoi(myDataReader->getDataCell(l, 4));
		myData[i].lanesEB = stoi(myDataReader->getDataCell(l, 5));
		myData[i].lanesWB = stoi(myDataReader->getDataCell(l, 6));

		myData[i].nameNB = myDataReader->getDataCell(m, 3);		//read in name data
		myData[i].nameSB = myDataReader->getDataCell(m, 4);
		myData[i].nameEB = myDataReader->getDataCell(m, 5);
		myData[i].nameWB = myDataReader->getDataCell(m, 6);

		myData[i].upIDNB = stoi(myDataReader->getDataCell(k, 3));
		myData[i].upIDSB = stoi(myDataReader->getDataCell(k, 4));
		myData[i].upIDEB = stoi(myDataReader->getDataCell(k, 5));
		myData[i].upIDWB = stoi(myDataReader->getDataCell(k, 6));

		myData[i].distanceNB = stoi(myDataReader->getDataCell(n, 3));		//Distance to the intersection id of the road previous to this intersection
		myData[i].distanceSB = stoi(myDataReader->getDataCell(n, 4));
		myData[i].distanceEB = stoi(myDataReader->getDataCell(n, 5));
		myData[i].distanceWB = stoi(myDataReader->getDataCell(n, 6));

		myData[i].speedLimitNB = stoi(myDataReader->getDataCell(o, 3));	//Speed limit in this intersection going NB
		myData[i].speedLimitSB = stoi(myDataReader->getDataCell(o, 4));
		myData[i].speedLimitEB = stoi(myDataReader->getDataCell(o, 5));
		myData[i].speedLimitWB = stoi(myDataReader->getDataCell(o, 6));

		k, l, m, n, o += jump;  //jump to next intersection dataset

	}
	cout << "testing\t" << myDataReader->getDataCell(3, 1);
	myData[5].nameNB = myDataReader->getDataCell(3, 1);
}