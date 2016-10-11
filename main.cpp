#include "Includes.h"

int main()
{
	cout << "In main\n";
	//Vehicle myCar;
	//Location spot;
	Car myCar;
	Car policeCar(true);
	Van myVan;
	Van ambulance(true);
	
	cout << endl << endl<< myCar;
	cout << policeCar;
	cout << myVan;
	cout << ambulance;

	cout << endl;
	system("pause");
	return 0;
}