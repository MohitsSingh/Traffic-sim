#pragma once
#include "includes.h"

using namespace std;


class LinkData
{
public:				//making public now...will probably change



	int ID;	//intersection ID number
	//Get from Link Data set row/column  4,2  (+20)


	string nameNB;			//Name of northbound street
	string nameSB;			//Name of southbound street
	string nameEB;			//Name of eastbound street
	string nameWB;			//Name of westbound street
	//Get frpom Link Data set (6, (3,4,5,6))


	int lanesNB;			//Number of lanes in northbound street
	int lanesSB;			//Number of lanes in southbound street
	int lanesEB;			//Number of lanes in eastbound street
	int lanesWB;			//Number of lanes in westbound street
	//Get from Link Data set (5,(3,4,5,6))


	int distanceNB;		//Distance to the intersection id of the road previous to this intersection
	int distanceSB;		//Distance to the intersection id of the road previous to this intersection
	int distanceEB;		//Distance to the intersection id of the road previous to this intersection
	int distanceWB;		//Distance to the intersection id of the road previous to this intersection
	//Get from Link Data set (7,(3,4,5,6))

	int speedLimitNB;		//Speed limit in this intersection going NB
	int speedLimitSB;		//Speed limit in this intersection going SB
	int speedLimitEB;		//Speed limit in this intersection going EB
	int speedLimitWB;		//Speed limit in this intersection going WB
	//Get from Link Data set (8,3-6)

	int upIDNB;				//Id of intersection prior to current one
	int upIDSB;				//Id of intersection prior to current one
	int upIDEB;				//Id of intersection prior to current one
	int upIDWB;				//Id of intersection prior to current one
	//Get from Link Data Set (4,3-6)


};


class PhasingData
{
public:				//making public now...will probably change

	//Data repeats for each signal every 24 lines
	//Get from Data set row/column  4,2  
	int ID;	//intersection ID number


	//Get from Phasing Data set (5,(3 - 11))
	int minGreenD1;			// ? minimum seconds for a green light
	int minGreenD2;			// ? minimum seconds for a green light
	int minGreenD3;			// ? minimum seconds for a green light
	int minGreenD4;			// ? minimum seconds for a green light
	int minGreenD5;			// ? minimum seconds for a green light
	int minGreenD6;			// ? minimum seconds for a green light
	int minGreenD7;			// ? minimum seconds for a green light
	int minGreenD8;			// ? minimum seconds for a green light
	int minGreenD9;			// ? minimum seconds for a green light
	int minGreenD10;			// ? minimum seconds for a green light
	int minGreenD14;			// ? minimum seconds for a green light


	//Get from Phasing Data set (6,(3 - 11))
	int maxGreenD1;			// ? maximum seconds for a green light
	int maxGreenD2;			// ? maximum seconds for a green light
	int maxGreenD3;			// ? maximum seconds for a green light
	int maxGreenD4;			// ? maximum seconds for a green light
	int maxGreenD5;			// ? maximum seconds for a green light
	int maxGreenD6;			// ? maximum seconds for a green light
	int maxGreenD7;			// ? maximum seconds for a green light
	int maxGreenD8;			// ? maximum seconds for a green light
	int maxGreenD9;			// ? maximum seconds for a green light
	int maxGreenD10;			// ? maximum seconds for a green light
	int maxGreenD14;			// ? maximum seconds for a green light

	//Get from Phasing Data set (11,(3 - 8))
	int yellowD1;				// ? seconds for a yellow light
	int yellowD2;				// ? seconds for a yellow light
	int yellowD3;				// ? seconds for a yellow light
	int yellowD4;				// ? seconds for a yellow light
	int yellowD5;				// ? seconds for a yellow light
	int yellowD6;				// ? seconds for a yellow light
	int yellowD7;				// ? seconds for a yellow light
	int yellowD8;				// ? seconds for a yellow light


	//Get from Phasing Data set (12,(3 - 8))
	int allRedD1;				// ? seconds for a red light in all directions
	int allRedD2;				// ? seconds for a red light in all directions
	int allRedD3;				// ? seconds for a red light in all directions
	int allRedD4;				// ? seconds for a red light in all directions
	int allRedD5;				// ? seconds for a red light in all directions
	int allRedD6;				// ? seconds for a red light in all directions
	int allRedD7;				// ? seconds for a red light in all directions
	int allRedD8;				// ? seconds for a red light in all directions


	//Get from Phasing Data set (14,(3 - 8))
	int walkD1;				// ? seconds for a walk light 
	int walkD2;				// ? seconds for a walk light 
	int walkD3;				// ? seconds for a walk light 
	int walkD4;				// ? seconds for a walk light 
	int walkD5;				// ? seconds for a walk light 
	int walkD6;				// ? seconds for a walk light
	int walkD7;				// ? seconds for a walk light 
	int walkD8;				// ? seconds for a walk light 
	int walkD9;				// ? seconds for a walk light 
	int walkD10;				// ? seconds for a walk light 
	int walkD14;				// ? seconds for a walk light 

	//Get from Phasing Data set (15,(3 - 8))
	int dontwalkD1;			//? seconds for don't walk light
	int dontwalkD2;			//? seconds for don't walk light
	int dontwalkD3;			//? seconds for don't walk light
	int dontwalkD4;			//? seconds for don't walk light
	int dontwalkD5;			//? seconds for don't walk light
	int dontwalkD6;			//? seconds for don't walk light
	int dontwalkD7;			//? seconds for don't walk light
	int dontwalkD8;			//? seconds for don't walk light


	//Get from Phasing Data set (22,(3 - 8))
	int yieldD1;			//? seconds for  yeild light
	int yieldD2;			//? seconds for  yeild light
	int yieldD3;			//? seconds for  yeild light
	int yieldD4;			//? seconds for  yeild light
	int yieldD5;			//? seconds for  yeild light
	int yieldD6;			//? seconds for  yeild light
	int yieldD7;			//? seconds for  yeild light
	int yieldD8;			//? seconds for  yeild light

};