//*********************************************************
//@author Wesley Stutzman
//
//This class is incharge of reading in all there data from a .csv file
//create a dynamic 2d array so you can pass any size file into it
//if we make multiple files later we can read any of them with this class
#pragma once
#include "Includes.h"

class DataReader
{
public:
	DataReader();								//default constructor
	DataReader(string inFileName);				//create class and read in all information from the file on create
	~DataReader();
	string getDataCell(int row, int column);	//this is in y/x format
	int getRowSize();							//returns row size
	int getColumnSize();						//returns column size
	void readData(string inFileName);			//reads in all data from the spread sheat and stores it inside an array
private:
	int row;									//holds the number of rows
	int column;									//holds the number of columns
	string **data;								//holds all there data in cells data[y][x]
	void createArray(string inFileName);		//file name
};
