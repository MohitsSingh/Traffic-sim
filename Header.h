#pragma once
#include "includes.h"

using namespace std;


class linkData
{
public:				//making public now...will probably change



	int ID;	//intersection ID number
	//Get from Data set row/column  4,1  (+20)


	string nameNB;			//Name of northbound street
	string nameSB;			//Name of southbound street
	string nameEB;			//Name of eastbound street
	string nameWB;			//Name of westbound street
	//Get frpom Data set (6, (3,4,5,6))


	int lanesNB;			//NUmber of lanes in northbound street
	int lanesSB;			//Number of lanes in southbound street
	int lanesEB;			//Number of lanes in eastbound street
	int lanesWB;			//Number of lanes in westbound street
	//Get from Data set (5,(3,4,5,6))


	int distanceNB;		//Distance to the intersection id of the road previous to this intersection
	int distanceSB;		//Distance to the intersection id of the road previous to this intersection
	int distanceEB;		//Distance to the intersection id of the road previous to this intersection
	int distanceWB;		//Distance to the intersection id of the road previous to this intersection
	//Get from Data set (7,(3,4,5,6))

	int speedLimitNB;		//Speed limit in this intersection going NB
	int speedLimitSB;		//Speed limit in this intersection going SB
	int speedLimitEB;		//Speed limit in this intersection going EB
	int speedLimitWB;		//Speed limit in this intersection going WB
	//Get from Data set ?????

	int upIDNB;				//Id of intersection prior to current one
	int upIDSB;				//Id of intersection prior to current one
	int upIDEB;				//Id of intersection prior to current one
	int upIDWB;				//Id of intersection prior to current one
	//Get from Data Set ??????


};









