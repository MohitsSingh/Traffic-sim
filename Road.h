#pragma once
#include <string>
using namespace std;
class Road {


private:

	string nameNB, nameSB, nameWB, nameEB;
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

	void setNameNB(string input);
	void setNameSB(string input);
	void setNameEB(string input);
	void setNameWB(string input);

	void setSpeedLimitNB(int input);
	void setSpeedLimitSB(int input);
	void setSpeedLimitEB(int input);
	void setSpeedLimitWB(int input);

	void setNS(bool);
	void setEW(bool);

	void setWidth(int x);

	//Getters

	string getNameNB();
	string getNameSB();
	string getNameEB();
	string getNameWB();

	int getSpeedLimitNB();
	int getSpeedLimitSB();
	int getSpeedLimitEB();
	int getSpeedLimitWB();

	bool getNS();
	bool getEW();

	int getWidth();
};

