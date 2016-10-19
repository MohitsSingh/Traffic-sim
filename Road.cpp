#include "Road.h"

#include <string>
#include <iostream>
#include <fstream>


Road::Road(){
   speedLimit = 0;
	
	lanes = 0;
	blanes = 0;
	tlanes = 0;

	name = " ";

	longitude = 0.0;
	latitude = 0.0;

}


Road::~Road()
{
}
