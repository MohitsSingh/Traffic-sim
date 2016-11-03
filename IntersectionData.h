/******************
Contributors
Wesley Stutzman
Jacqueline Garcia
Andrew
Danni

********************/
#pragma once
#include "Includes.h"

class IntersectionData {

public:
	IntersectionData();
	~IntersectionData();

	//Link Data 
	int getUpIdNB(int inputId);
	int getUpIdSB(int inputId);				//Id of intersection prior to current one
	int getUpIdEB(int inputId);				//Id of intersection prior to current one
	int getUpIdWB(int inputId);

	int getLanesNB(int inputID);
	int getLanesSB(int inputID);			//Number of lanes in southbound street
	int getLanesEB(int inputID);			//Number of lanes in eastbound street
	int getLanesWB(int inputID);

	string getNameNB(int inputId);
	string getNameSB(int inputId);
	string getNameEB(int inputId);
	string getNameWB(int inputId);

	int getDistanceNB(int inputId);		//Distance to the intersection id of the road previous to this intersection
	int getDistanceSB(int inputId);		//Distance to the intersection id of the road previous to this intersection
	int getDistanceEB(int inputId);		//Distance to the intersection id of the road previous to this intersection
	int getDistanceWB(int inputId);

	int getSpeedLimitNB(int inputId);		//Speed limit in this intersection going NB
	int getSpeedLimitSB(int inputId);		//Speed limit in this intersection going SB
	int getSpeedLimitEB(int inputId);		//Speed limit in this intersection going EB
	int getSpeedLimitWB(int inputId);		//Speed limit in this intersection going WB

	//Phasing Data Set

	//Get from Phasing Data (23246,(3 - 11)) (+24)
	double getMinGreenD1(int inputId);			// ? minimum seconds for a green light
	double getMinGreenD2(int inputId);			// ? minimum seconds for a green light
	double getMinGreenD3(int inputId);			// ? minimum seconds for a green light
	double getMinGreenD4(int inputId);			// ? minimum seconds for a green light
	double getMinGreenD5(int inputId);			// ? minimum seconds for a green light
	double getMinGreenD6(int inputId);			// ? minimum seconds for a green light
	double getMinGreenD7(int inputId);			// ? minimum seconds for a green light
	double getMinGreenD8(int inputId);			// ? minimum seconds for a green light
	double getMinGreenD9(int inputId);			// ? minimum seconds for a green light
	double getMinGreenD10(int inputId);			// ? minimum seconds for a green light
	double getMinGreenD14(int inputId);			// ? minimum seconds for a green light


										//Get from Phasing Data set (23246,(3 - 11))
	double getMaxGreenD1(int inputId);			// ? maximum seconds for a green light
	double getMaxGreenD2(int inputId);			// ? maximum seconds for a green light
	double getMaxGreenD3(int inputId);			// ? maximum seconds for a green light
	double getMaxGreenD4(int inputId);			// ? maximum seconds for a green light
	double getMaxGreenD5(int inputId);			// ? maximum seconds for a green light
	double getMaxGreenD6(int inputId);			// ? maximum seconds for a green light
	double getMaxGreenD7(int inputId);			// ? maximum seconds for a green light
	double getMaxGreenD8(int inputId);			// ? maximum seconds for a green light
	double getMaxGreenD9(int inputId);			// ? maximum seconds for a green light
	double getMaxGreenD10(int inputId);			// ? maximum seconds for a green light
	double getMaxGreenD14(int inputId);			// ? maximum seconds for a green light

										//Get from Phasing Data set (23251,(3 - 8))
	double getYellowD1(int inputId);				// ? seconds for a yellow light
	double getYellowD2(int inputId);				// ? seconds for a yellow light
	double getYellowD3(int inputId);				// ? seconds for a yellow light
	double getYellowD4(int inputId);				// ? seconds for a yellow light
	double getYellowD5(int inputId);				// ? seconds for a yellow light
	double getYellowD6(int inputId);				// ? seconds for a yellow light
	double getYellowD7(int inputId);				// ? seconds for a yellow light
	double getYellowD8(int inputId);				// ? seconds for a yellow light


										//Get from Phasing Data set (23252,(3 - 8))
	double getAllRedD1(int inputId);				// ? seconds for a red light in all directions
	double getAllRedD2(int inputId);				// ? seconds for a red light in all directions
	double getAllRedD3(int inputId);				// ? seconds for a red light in all directions
	double getAllRedD4(int inputId);				// ? seconds for a red light in all directions
	double getAllRedD5(int inputId);				// ? seconds for a red light in all directions
	double getAllRedD6(int inputId);				// ? seconds for a red light in all directions
	double getAllRedD7(int inputId);				// ? seconds for a red light in all directions
	double getAllRedD8(int inputId);				// ? seconds for a red light in all directions


										//Get from Phasing Data set (23255,(3 - 8))
	double getWalkD1(int inputId);				// ? seconds for a walk light 
	double getWalkD2(int inputId);				// ? seconds for a walk light 
	double getWalkD3(int inputId);				// ? seconds for a walk light 
	double getWalkD4(int inputId);				// ? seconds for a walk light 
	double getWalkD5(int inputId);				// ? seconds for a walk light 
	double getWalkD6(int inputId);				// ? seconds for a walk light
	double getWalkD7(int inputId);				// ? seconds for a walk light 
	double getWalkD8(int inputId);				// ? seconds for a walk light 
	double getWalkD9(int inputId);				// ? seconds for a walk light 
	double getWalkD10(int inputId);				// ? seconds for a walk light 
	double getWalkD14(int inputId);				// ? seconds for a walk light 

										//Get from Phasing Data set (23256,(3 - 8))
	double getDontWalkD1(int inputId);			//? seconds for don't walk light
	double getDontWalkD2(int inputId);			//? seconds for don't walk light
	double getDontWalkD3(int inputId);			//? seconds for don't walk light
	double getDontWalkD4(int inputId);			//? seconds for don't walk light
	double getDontWalkD5(int inputId);			//? seconds for don't walk light
	double getDontWalkD6(int inputId);			//? seconds for don't walk light
	double getDontWalkD7(int inputId);			//? seconds for don't walk light
	double getDontWalkD8(int inputId);			//? seconds for don't walk light


										//Get from Phasing Data set (23263,(3 - 8))
	double getYieldD1(int inputId);			//? seconds for  yeild light
	double getYieldD2(int inputId);			//? seconds for  yeild light
	double getYieldD3(int inputId);			//? seconds for  yeild light
	double getYieldD4(int inputId);			//? seconds for  yeild light
	double getYieldD5(int inputId);			//? seconds for  yeild light
	double getYieldD6(int inputId);			//? seconds for  yeild light
	double getYieldD7(int inputId);			//? seconds for  yeild light
	double getYieldD8(int inputId);			//? seconds for  
	

private:
	void setLinkData();
	void setPointers();
	void setPhasingData();
	DataReader *myDataReader;
	int numberOfIntersections;

	//Get from Link Data set row/column  530,2  (+20)

	//Get from Link Data Set (532,3-6)
	int *upIdNB;				//Id of intersection prior to current one
	int *upIdSB;				//Id of intersection prior to current one
	int *upIdEB;				//Id of intersection prior to current one
	int *upIdWB;				//Id of intersection prior to current one

	//Get from Link Data set (533,(3,4,5,6))
	int *lanesNB;			//Number of lanes in northbound street
	int *lanesSB;			//Number of lanes in southbound street
	int *lanesEB;			//Number of lanes in eastbound street
	int *lanesWB;			//Number of lanes in westbound street

	//Get from Link Data set (534, (3,4,5,6))
	string *nameNB;			//Name of northbound street
	string *nameSB;			//Name of southbound street
	string *nameEB;			//Name of eastbound street
	string *nameWB;			//Name of westbound street

	//Get from Link Data set (535,(3,4,5,6))
	int *distanceNB;		//Distance to the intersection id of the road previous to this intersection
	int *distanceSB;		//Distance to the intersection id of the road previous to this intersection
	int *distanceEB;		//Distance to the intersection id of the road previous to this intersection
	int *distanceWB;		//Distance to the intersection id of the road previous to this intersection
	
	//Get from Link Data set (536,3-6)
	int *speedLimitNB;		//Speed limit in this intersection going NB
	int *speedLimitSB;		//Speed limit in this intersection going SB
	int *speedLimitEB;		//Speed limit in this intersection going EB
	int *speedLimitWB;		//Speed limit in this intersection going WB
	
	
	

	/*

	D1 – Northbound Left Turn
	D2 – Southbound Thru/Right
	D3 – Westbound Left Turn
	D4 – Eastbound Thru
	D5 – Southbound Left Turn
	D6 – Northbound Thru
	D7 – Eastbound Left Turn
	D8 – Westbound Thru

	*/

	//Get from Phasing Data set (23246,(3 - 11)) (+24)
	double *minGreenD1;			// ? minimum seconds for a green light
	double *minGreenD2;			// ? minimum seconds for a green light
	double *minGreenD3;			// ? minimum seconds for a green light
	double *minGreenD4;			// ? minimum seconds for a green light
	double *minGreenD5;			// ? minimum seconds for a green light
	double *minGreenD6;			// ? minimum seconds for a green light
	double *minGreenD7;			// ? minimum seconds for a green light
	double *minGreenD8;			// ? minimum seconds for a green light
	double *minGreenD9;			// ? minimum seconds for a green light
	double *minGreenD10;			// ? minimum seconds for a green light
	double *minGreenD14;			// ? minimum seconds for a green light


	//Get from Phasing Data set (23247,(3 - 11))
	double *maxGreenD1;			// ? maximum seconds for a green light
	double *maxGreenD2;			// ? maximum seconds for a green light
	double *maxGreenD3;			// ? maximum seconds for a green light
	double *maxGreenD4;			// ? maximum seconds for a green light
	double *maxGreenD5;			// ? maximum seconds for a green light
	double *maxGreenD6;			// ? maximum seconds for a green light
	double *maxGreenD7;			// ? maximum seconds for a green light
	double *maxGreenD8;			// ? maximum seconds for a green light
	double *maxGreenD9;			// ? maximum seconds for a green light
	double *maxGreenD10;			// ? maximum seconds for a green light
	double *maxGreenD14;			// ? maximum seconds for a green light

	//Get from Phasing Data set (23251,(3 - 8))
	double *yellowD1;				// ? seconds for a yellow light
	double *yellowD2;				// ? seconds for a yellow light
	double *yellowD3;				// ? seconds for a yellow light
	double *yellowD4;				// ? seconds for a yellow light
	double *yellowD5;				// ? seconds for a yellow light
	double *yellowD6;				// ? seconds for a yellow light
	double *yellowD7;				// ? seconds for a yellow light
	double *yellowD8;				// ? seconds for a yellow light


	//Get from Phasing Data set (23252,(3 - 8))
	double *allRedD1;				// ? seconds for a red light in all directions
	double *allRedD2;				// ? seconds for a red light in all directions
	double *allRedD3;				// ? seconds for a red light in all directions
	double *allRedD4;				// ? seconds for a red light in all directions
	double *allRedD5;				// ? seconds for a red light in all directions
	double *allRedD6;				// ? seconds for a red light in all directions
	double *allRedD7;				// ? seconds for a red light in all directions
	double *allRedD8;				// ? seconds for a red light in all directions


	//Get from Phasing Data set (23255,(3 - 8))
	double *walkD1;				// ? seconds for a walk light 
	double *walkD2;				// ? seconds for a walk light 
	double *walkD3;				// ? seconds for a walk light 
	double *walkD4;				// ? seconds for a walk light 
	double *walkD5;				// ? seconds for a walk light 
	double *walkD6;				// ? seconds for a walk light
	double *walkD7;				// ? seconds for a walk light 
	double *walkD8;				// ? seconds for a walk light 
	double *walkD9;				// ? seconds for a walk light 
	double *walkD10;				// ? seconds for a walk light 
	double *walkD14;				// ? seconds for a walk light 

	//Get from Phasing Data set (23256,(3 - 8))
	double *dontWalkD1;			//? seconds for don't walk light
	double *dontWalkD2;			//? seconds for don't walk light
	double *dontWalkD3;			//? seconds for don't walk light
	double *dontWalkD4;			//? seconds for don't walk light
	double *dontWalkD5;			//? seconds for don't walk light
	double *dontWalkD6;			//? seconds for don't walk light
	double *dontWalkD7;			//? seconds for don't walk light
	double *dontWalkD8;			//? seconds for don't walk light


	//Get from Phasing Data set (23263,(3 - 8))
	double *yieldD1;			//? seconds for  yeild light
	double *yieldD2;			//? seconds for  yeild light
	double *yieldD3;			//? seconds for  yeild light
	double *yieldD4;			//? seconds for  yeild light
	double *yieldD5;			//? seconds for  yeild light
	double *yieldD6;			//? seconds for  yeild light
	double *yieldD7;			//? seconds for  yeild light
	double *yieldD8;			//? seconds for  yeild light
};


