#include "Includes.h"

int main()
{
#if TSIM_CONSTRUCTOR_OUTPUT == 1
	cout << "In main\n";
#endif
	Car myCar;
	Car policeCar(true);
	Van myVan;
	Van ambulance(true);
	Sportscar myBaby;
	Bus myBus;
	
	cout << endl << endl;
	cout << "Car example:\n" << myCar;
	cout << "Policecar example:\n" << policeCar;
	cout << "Van example:\n" << myVan;
	cout << "Ambulance example:\n" << ambulance;
	cout << "Sportscar example:\n" << myBaby;
	cout << "Bus example:\n" << myBus;

	cout << endl;
	system("pause");
	return 0;
}