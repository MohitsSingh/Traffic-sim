#pragma once
#include <string>
using namespace std;
class Road {


private:
	//string name;
	string nameNB, nameSB, nameWB, nameEB;
	//int lanesNB, lanesSB, lanesEB, lanesWB;
	//int distanceNB, distanceSB, distanceEB, distanceWB;
	int speedLimitNB, speedLimitSB, speedLimitEB, speedLimitWB;

	int lanes, tlanes, blanes;
	int roadWidth;
	double longitude, latitude;

	bool NS;
	bool EW;

public:

	Road();
	~Road();

	//Setters

	//void setName(string);

	/*void setLanesNB(int input);
	void setLanesSB(int input);
	void setLanesEB(int input);
	void setLanesWB(int input);*/

	void setNameNB(string input);
	void setNameSB(string input);
	void setNameEB(string input);
	void setNameWB(string input);

	/*
	void setDistanceNB(int input);
	void setDistanceSB(int input);
	void setDistanceEB(int input);
	void setDistanceWB(int input);*/

	void setSpeedLimitNB(int input);
	void setSpeedLimitSB(int input);
	void setSpeedLimitEB(int input);
	void setSpeedLimitWB(int input);

	void setNS(bool);
	void setEW(bool);

	//Getters

	/*string getName();

	int getLanesNB();
	int getLanesSB();
	int getLanesEB();
	int getLanesWB();
	*/
	string getNameNB();
	string getNameSB();
	string getNameEB();
	string getNameWB();

/*	int getDistanceNB();
	int getDistanceSB();
	int getDistanceEB();
	int getDistanceWB();
	*/
	int getSpeedLimitNB();
	int getSpeedLimitSB();
	int getSpeedLimitEB();
	int getSpeedLimitWB();

	bool getNS();
	bool getEW();
};

