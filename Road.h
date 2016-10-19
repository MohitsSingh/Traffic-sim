#pragma once
#include <string>
using namespace std;
class Road {
	
private:
	string name;

	int lanes, tlanes, blanes;
	int speedLimit;
	int roadWidth;

	double longitude, latitude;
	

public:
	Road();
	~Road();

	void setS(string s) { 
		name = s; 
	}
	
	string getS() {
		return name;
	}
	void setRoadWidth(int x) {
		roadWidth = x;
	}
	void setlanes(int x) {
		lanes = x;
	}
	void setblanes(int x) {
		blanes = x;
	}
	void settlanes(int x) {
		tlanes = x;
	}
	void setSpeedLimit(int x) {
		speedLimit = x;
	}
	
	void setLatitude(double x) {
		latitude = x;
	}
	void setLongitude(double x) {
		longitude = x;
	}

	int getlanes() {
		return lanes;
	}
	int getblanes() {
		return blanes;
	}
	int gettlanes() {
		return tlanes;
	}
	int getRoadWidth() {
		return roadWidth;
	}
	int getSpeedLimit() {
		return speedLimit;
	}
	double getLongitude() {
		return longitude;
	}
	double getLatitude() {
		return latitude;
	}


};

