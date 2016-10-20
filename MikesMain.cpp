#include "Includes.h"

int main()
{
	vector <Vehicle*> vehicleList;
	MapOBJ *map[MAX_CITY_X][MAX_CITY_Y];

	for (int i = 0; i < MAX_CITY_X; i++)
	{
		for (int j = 0; j < MAX_CITY_Y; j++)
		{
			map[i][j] = nullptr;
		}
	}

	vehicleList.push_back(new Vehicle(5, 5));
	vehicleList.push_back(new Vehicle(10, 5));
	vehicleList[0]->setCardinalD(CARDINAL::SOUTH);

	map[vehicleList[0]->getX()][vehicleList[0]->getY()] = vehicleList[0];
	map[vehicleList[1]->getX()][vehicleList[1]->getY()] = vehicleList[1];

	for (int i = 0; i < vehicleList.size; i++)
	{
		//move
	}

	cout << endl << endl;
	system("pause");
	return 0;
}