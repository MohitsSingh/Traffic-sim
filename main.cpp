/******************
Contributors
Wesley Stutzman

********************/
#pragma once
#include "Includes.h"

//This main now can create an list of all the intersections data and is able to be called based on its id number
//In this example i have created and array of five values
//based on those five values i do five loops and print out all direcitons of and intersection in that data location
int main()
{
	cout << "Testing" << endl;
	IntersectionData myIntersectionData;

	cout << "Intersection Number:\t" << 1 << endl;
	cout << "NB Name:\t" << myIntersectionData.getNbName(1) << endl;
	cout << "SB Name:\t" << myIntersectionData.getSbName(1) << endl;
	cout << "EB Name:\t" << myIntersectionData.getEbName(1) << endl;
	cout << "WB Name:\t" << myIntersectionData.getWbName(1) << endl;

	int intersectionsToTest[5] {2, 3, 50, 345, 995};
	for (unsigned int i = 0; i < 5; i++)
	{
		cout << "Intersection Number:\t" << intersectionsToTest[i] << endl;
		cout << "NB Name:\t" << myIntersectionData.getNbName(intersectionsToTest[i]) << endl;
		cout << "SB Name:\t" << myIntersectionData.getSbName(intersectionsToTest[i]) << endl;
		cout << "EB Name:\t" << myIntersectionData.getEbName(intersectionsToTest[i]) << endl;
		cout << "WB Name:\t" << myIntersectionData.getWbName(intersectionsToTest[i]) << endl;
	}
	system("pause");
	return 0;
}