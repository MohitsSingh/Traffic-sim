//*******************************************************************************************
//@author Wesley Stutzman
//
//reading in all data from a .csv file
//reads in with a dynamic array to hold any amound of information
//information can then be grabed from the class in a y/x row/column formation
//(if anyone would rather it be x/y you can feel free to change it)
//classes can then be built on this to grab information from certain pockets of the file
//*******************************************************************************************
#pragma once
#include "Includes.h"

DataReader::DataReader()
{}
DataReader::DataReader(string inFileName)
{
	readData(inFileName);
}
DataReader::~DataReader()
{
	
		delete []data;
}
//get data from an y/x cell
//will not take numbers less then zero and the max size of the grid
string DataReader::getDataCell(int inRow, int inColumn)
{
	if (inRow < 1 || inColumn < 1 || inRow > row + 1 || inColumn > column + 1)
		return "INVALID CELL";						//FIXME throw an exception here later
	if (data[inRow - 1][inColumn - 1] == "")
		return "0";
	return data[inRow - 1][inColumn - 1];			//furns the number zero based
}
//return the number of rows
int DataReader::getRowSize()
{
	return row;										
}
//return the number of columns
int DataReader::getColumnSize()
{
	return column;									
}
//read in a file based on its name
//creates an array the size of the sheat
//then fills it with all the information
void DataReader::readData(string inFileName)
{
	
	createArray(inFileName);						//create the array to hold all data
	cout << "Reading Data" << endl;
	ifstream inFile(inFileName);					//open the file
	string line;									//create a string to hold in the line ur going to read in
	int curRow = 0;									//keep track of ur location
	int curCol = 0;									//*
	while (getline(inFile, line))					//loop while there is lines to input
	{
		curCol = 0;									//reset ur column to zero "shows start of a new line"
		stringstream readLine(line);				//create the line into a strteam so we can read it in by ','
		string chunk = "";							//be ready to store each cell of data as chunks
		while (getline(readLine, chunk, ','))		//loop through each row and seperate the cells by ','
			data[curRow][curCol++] = chunk;			//store each pece of data in its cell can ++ to the next cell
		curRow++;									//move to the next row
	}
	inFile.close();									//always close the file when you are done
	}
//creates a 2d array of the spread sheat storing each item as a string
void DataReader::createArray(string inFileName)
{
	cout << "Creating Array To Hold Data" << endl;
	ifstream inFile(inFileName);					//opens a file
	string chunk;									//creates the chunk to read in
	int size = 0;									//holds the size of row and column as its counted
	getline(inFile, chunk);							//read in the first line
	for (unsigned int i = 0; i < chunk.size(); i++)			//read through a line of the string
		if (chunk[i] == ',')						//if there is a comma then add one to size
			size++;
	column = size + 1;								//set the number of columns to the number of commas in the code
	size = 0;										//reset size to one sinze we all ready read in the first line
	while (getline(inFile, chunk))					//read in how many lines are inside the file
		size++;
	row = size + 1;									//save how many rows where in the file				
	//**create the array**							//**create the array**
	data = new string*[row];						//define data[x];
	for (int i = 0; i < row; i++)					//define each row as the column length
		data[i] = new string[column];				//define data[i][y];
	inFile.close();									//make sure to close the file when you are done

	}
