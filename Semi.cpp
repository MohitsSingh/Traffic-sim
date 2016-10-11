#include "Semi.h"


Semi::Semi()
{
	cout << "Default constructor for Semi called.\n";

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
