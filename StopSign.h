#pragma once
#include "Includes.h"
#include "Intersection.h"

class StopSign : public Intersection
{
private:
	deque <MapOBJ*> cars;

public:
	StopSign()
	{
		nLanes = 1;
		sLanes = 1;
		eLanes = 1;
		wLanes = 1;
		intersectionSize = nLanes + sLanes + eLanes + wLanes;
	}
	void interPush(MapOBJ* modes)  // put on queue and 
	{
		bool duplicate = false;
		if (cars.size() == 0)
		{
			cars.push_back(modes);
		}
		if (cars.size() >= 1)
		{
			for (unsigned int i = 0; i < cars.size(); i++)
			{
				if (cars[i]->getId() == modes->getId())
				{
					duplicate = true;
				}
			}
			if (duplicate)
			{
				cars.push_back(modes);
			}
		}
	}
	vector <MapOBJ*> interPop()
	{
		vector <MapOBJ*> carGo;
		if (cars.size() > 0)
		{
			MapOBJ* hold = cars[0];
			cars.pop_front();
			carGo.push_back(hold);
		}
		return carGo;
	}
}; 
