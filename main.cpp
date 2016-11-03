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
	cout << "NB Name:\t" << myIntersectionData.getNameNB(1) << endl;
	cout << "SB Name:\t" << myIntersectionData.getNameSB(1) << endl;
	cout << "EB Name:\t" << myIntersectionData.getNameEB(1) << endl;
	cout << "WB Name:\t" << myIntersectionData.getNameWB(1) << endl;

	int intersectionsToTest[5] {1, 2, 15, 998,51};
	for (unsigned int i = 0; i < 5; i++)
	{
		cout << "Intersection Number:\t" << intersectionsToTest[i] << endl;
		cout << "NB Name:\t" << myIntersectionData.getNameNB(intersectionsToTest[i]) << endl;
		cout << "SB Name:\t" << myIntersectionData.getNameSB(intersectionsToTest[i]) << endl;
		cout << "EB Name:\t" << myIntersectionData.getNameEB(intersectionsToTest[i]) << endl;
		cout << "WB Name:\t" << myIntersectionData.getNameWB(intersectionsToTest[i]) << endl;
		cout << "allred: \t" << myIntersectionData.getAllRedD4(intersectionsToTest[i]) << endl;
	}
	cout << "end";
	
	//for (i = 0; i(not end of file); i++)
	//{
	//	myintersectionData.get(eachfile)
	//}




	system("pause");
	return 0;
}