//@author Wesley Stutzman
#pragma once
#include "Includes.h"

//place the .csv file in the same location as the exicutable for the program
int main()
{
	cout << "Testing" << endl;
	IntersectionData myIntersectionData;
	
	cout << myIntersectionData.getNbName(5) << endl;

	system("pause");

	////DataReader myDataReader("TraficData.csv");								//same as next 2 lines
	//DataReader myDataReader;													//create the class
	//myDataReader.readData("TraficData.csv");									//input in the csv file
	//cout << "Rows:\t\t" << myDataReader.getRowSize() << endl;					//number of rows
	//cout << "Columns:\t" << myDataReader.getColumnSize() << endl;				//number of columns
	//cout << myDataReader.getDataCell(0, 0) << endl;								//invalid location
	//cout << myDataReader.getDataCell(1, 1) << endl;								//first line
	//cout << myDataReader.getDataCell(myDataReader.getRowSize(), 1) << endl;		//last line
	//system("pause");
	return 0;
}