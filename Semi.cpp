#include "Semi.h"


Semi::Semi()
{
	cout << "Default constructor for Semi called.\n";

	setAcceleration(59);   		// seconds to 97kph
	setMaxSpeed(119);  		// kph
	setWeight(55000); 		// pounds
	setLength(21); 			// meters
	setWidth(3); 			// meters
	setOversized(true);
}

Semi::~Semi()
{
}
