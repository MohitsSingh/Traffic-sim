#pragma once
#include "includes.h"

/*  This program takes the csv file created from the link data spreadsheet and reads it into
linkArray.  Right now it assumes public variables, but that may be changed.

The dubious part involves the datareader.  I am not sure how that works and can be called.  I know 
Wes will explain it to me on October 23.

*/

int main()
{
	linkData linkArray[1000];

	int jump = 20;			//set jump variable to get to next dataset
	int k = 4;				//row of intersection ID number
	int l = 5;				//row of number of lanes data
	int m = 6;				//row  of Name data
	int n = 7;				//row of distance number
	int o = 8;				//row of speed data
	int i;

	// fix the above with right dataset




	for (i = 0; i < 1000; i++)
	{
		//row of intersection ID number
		linkArray[i].ID = dataReader(k, 2);

		linkArray[i].lanesNB = dataReader(l, 3);		//read in lanes data
		linkArray[i].lanesSB = dataReader(l, 4);
		linkArray[i].lanesEB = dataReader(l, 5);
		linkArray[i].lanesWB = dataReader(l, 6);

		linkArray[i].nameNB = dataReader(m, 3);		//read in name data
		linkArray[i].nameSB = dataReader(m, 4);
		linkArray[i].nameEB = dataReader(m, 5);
		linkArray[i].nameWB = dataReader(m, 6);

		linkArray[i].upIDNB = dataReader(k, 3);
		linkArray[i].upIDSB = dataReader(k, 4);
		linkArray[i].upIDEB = dataReader(k, 5);
		linkArray[i].upIDWB = dataReader(k, 6);

		linkArray[i].distanceNB = dataReader(n, 3);		//Distance to the intersection id of the road previous to this intersection
		linkArray[i].distanceSB = dataReader(n, 4);
		linkArray[i].distanceEB = dataReader(n, 5);
		linkArray[i].distanceWB = dataReader(n, 6);

		linkArray[i].speedLimitNB = dataReader(o, 3);	//Speed limit in this intersection going NB
		linkArray[i].speedLimitSB = dataReader(o, 4);
		linkArray[i].speedLimitEB = dataReader(o, 5);
		linkArray[i].speedLimitWB = dataReader(o, 6);

		k, l, m, n, o += jump;  //jump to next intersection dataset

	}

	return 0;

}





	


	}
}