#include "Pedestrian.h"


Pedestrian::Pedestrian()
{
#if TSIM_CONSTRUCTOR_OUTPUT == 1
	cout << "Default constructor for Pedestrian called.\n";
#endif
	width = 12;		//inches
	length = 12;	//inches
}


Pedestrian::~Pedestrian()
{
}
