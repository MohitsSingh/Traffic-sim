#pragma once
#include "Includes.h"

class IntersectionData {
private:
	void readLinkData();
	DataReader *myDataReader;
	int numberOfIntersections;
	DataClasses *myData;

public:
	IntersectionData();
	string getNbName(int inputIntersectionId);
};


