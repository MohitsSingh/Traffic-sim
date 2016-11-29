#include "Road.h"

#include <string>
#include <iostream>
#include <fstream>


Road::Road(){
	NS = false;
	EW = false;
}


Road::~Road()
{

}
/*
void Road::setName(string input) {
	name = input;
}
void Road::setLanesNB(int input) {
	lanesNB = input;
}
void Road::setLanesSB(int input) {
	lanesSB = input;
}
void Road::setLanesEB(int input) {
	lanesEB = input;
}
void Road::setLanesWB(int input) {
	lanesWB = input;
}
*/
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
/*
void Road::setDistanceNB(int input) {
	distanceNB = input;
}
void Road::setDistanceSB(int input) {
	distanceSB = input;
}
void Road::setDistanceEB(int input) {
	distanceEB = input;
}
void Road::setDistanceWB(int input) {
	distanceWB = input;
}*/

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
/*
int Road::getLanesNB() {
	return lanesNB;
}
int Road::getLanesSB() {
	return lanesSB;
}
int Road::getLanesEB() {
	return lanesEB;
}
int Road::getLanesWB() {
	return lanesWB;
}

string Road::getName() {
	return name;
}*/
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
/*
int Road::getDistanceNB() {
	return distanceNB;
}
int Road::getDistanceSB() {
	return distanceSB;
}
int Road::getDistanceEB() {
	return distanceEB;
}
int Road::getDistanceWB() {
	return distanceWB;
}*/

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


/*void Road::setRoadWidth(int x) {
	roadWidth = x;
}
void Road::setlanes(int x) {
	lanes = x;
}
void Road::setblanes(int x) {
	blanes = x;
}
void Road::settlanes(int x) {
	tlanes = x;
}

void Road::setLatitude(double x) {
	latitude = x;
}
void Road::setLongitude(double x) {
	longitude = x;
}

int Road::getlanes() {
	return lanes;
}
int Road::getblanes() {
	return blanes;
}
int Road::gettlanes() {
	return tlanes;
}
int Road::getRoadWidth() {
	return roadWidth;
}

double Road::getLongitude() {
	return longitude;
}
double Road::getLatitude() {
	return latitude;
}*/

void Road::setNS(bool input) {
	NS = input;
}

bool Road::getNS() {
	return NS;
}

void Road::setEW(bool input) {
	EW = input;
}

bool Road::getEW() {
	return EW;
}