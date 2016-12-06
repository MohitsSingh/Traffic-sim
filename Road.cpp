#include "Road.h"

#include <string>
#include <iostream>
//#include <fstream>

//Constructors
Road::Road()
{
	NS = false;
	EW = false;
}

Road::~Road()
{

}


//Setters
void Road::setWidth(int x)				//spencemw, added a setter for this variable
{
	roadWidth = x;
}


void Road::setNameNB(string input) {
	nameNB = input;
}
void Road::setNameSB(string input) {
	nameSB = input;
}
void Road::setNameEB(string input) {
	nameEB = input;
}
void Road::setNameWB(string input) {
	nameWB = input;
}

void Road::setSpeedLimitNB(int input) {
	speedLimitNB = input;
}
void Road::setSpeedLimitSB(int input) {
	speedLimitSB = input;
}
void Road::setSpeedLimitEB(int input) {
	speedLimitEB = input;
}
void Road::setSpeedLimitWB(int input) {
	speedLimitWB = input;
}

void Road::setNS(bool input) {
	NS = input;
}

void Road::setEW(bool input) {
	EW = input;
}


//Getters
int Road::getWidth()				//spencemw, added a getter for this variable
{
	return roadWidth;
}

string  Road::getNameNB() {
	return nameNB;
}
string Road::getNameSB() {
	return nameSB;
}
string Road::getNameEB() {
	return nameEB;
}
string Road::getNameWB() {
	return nameWB;
}

int Road::getSpeedLimitNB() {
	return speedLimitNB;
}
int Road::getSpeedLimitSB() {
	return speedLimitSB;
}
int Road::getSpeedLimitEB() {
	return speedLimitEB;
}
int Road::getSpeedLimitWB() {
	return speedLimitWB;
}

bool Road::getNS() {
	return NS;
}

bool Road::getEW() {
	return EW;
}