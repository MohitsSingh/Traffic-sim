#pragma once
#include "Includes.h"
#include <queue> 
#include <vector>

bool stopGo(Car &obj, int count)
{
	//int /*car.getCount()*/ count = 1;
	int count2 = 0;
	bool canMove = true;
	deque <int> cars;
	if (cars.size() == 0)
	{
		cars.push_back(count);
	}
	if (cars.size() == 1)
	{
		cars.pop_front();
		canMove = true;
	}
	if (cars.size() > 0)
	{
		for (int i = 0; i < cars.size(); i++)
		{
			if (/*car*/ count == cars[i] && i != 0)
			{
				canMove = false;
			}
			else if (/*car*/ count != cars[i])
			{
				count2++;
			}
			if (count2 == cars.size())
			{
				cars.push_back(4);
				canMove = false;
				cars.pop_front();
				count2 = 0;
			}
		}
	}
	//cout << cars[0] << endl;
	return  canMove;
}

void main()
{
	Car myCar;
	bool canMove = true;
	myCar.setCurrentSpeed(5);
	cout << myCar.getCurrentSpeed() << endl;
	Intersection myInt = Intersection(1, 1);
	myCar.setLatitude(1);
	myCar.setLongitude(1);
	
	if (myCar.getLongitude() == myInt.getXLoc() && myCar.getLatitude() == myInt.getYLoc())
	{
		canMove = stopGo(myCar, 1);
	}
	cout << canMove << endl;
	/*FourWayStop fourWayIntersection(12, 3, 3, 3, 3);

	cout << "Number of lanes going north:\t" << fourWayIntersection.getNumberOfLanes(NORTH) << endl;
	cout << "North Light Color\t\t";
	switch (fourWayIntersection.checkLight(NORTH, 0))
	{
	case RED:
		cout << "Red";
		break;
	case GREEN:
		cout << "Green";
		break;
	case YELLOW:
		cout << "Yellow";
		break;
	default:
		cout << "INVALID OUTPUT CHECK foutWayIntersection.checkLight()!!!";
		break;
	}
	cout << endl;
		Intersection(int inputIntersectionID, int nbLanes, int ebLanes, int sbLanes, int wbLanes);

	if (b == 0 && c == 0)
	{
		Intersection myInt(0, 0);
		int sign = myInt.getTypeSign();
		if (sign == 1)
		{
			myCar.setCurrentSpeed(0);
		}

	}
	
	cout << myCar.getCurrentSpeed() << endl;
	cout << b << endl;*/
	cout << "you got to the end" << endl;
	system("pause");
	return;
}