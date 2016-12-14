//Christine Sobolewski, Adam Gunnell, Jack Grebb
#pragma once
#include "Semi.h"

//Christine Sobolewski
Semi::Semi()
{
	setAcceleration(59);  //units?
	setMaxSpeed(74);  //units?
	setWeight(55000); //units?
	setLength(21); // meters
	setWidth(3); // meters
	setOversized(true);
}

Semi::~Semi()
{
}
