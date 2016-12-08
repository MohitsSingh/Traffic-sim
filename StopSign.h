#pragma once
#include "Includes.h"
#include "Intersection.h"

class StopSign : public Intersection
{
private:
	deque <TransportMode*> cars;

public:
	StopSign()
	{
		nLanes = 1;
		sLanes = 1;
		eLanes = 1;
		wLanes = 1;
		intersectionSize = nLanes + sLanes + eLanes + wLanes;
		interType = STOPSIGN;
	}
	void interPush(TransportMode* modes)  // put on queue and 
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


vector <TransportMode*> interPop()
{
	int release = carDirection();
	vector <TransportMode*> carGo;
	switch(release)
	{
		case 0:
			TransportMode* hold = cars[0];
			cars.pop_front();
			carGo.push_back(hold);
		
		case 1:
			TransportMode* hold = cars[0];
			TransportMode* hold2 = cars[1];
			cars.pop_front();
			cars.pop_front();
			carGo.push_back(hold);
			carGo.push_back(hold2);
		
		case 2:
			TransportMode* hold = cars[0];
			TransportMode* hold2 = cars[1];
			TransportMode* hold3 = cars[2];
			cars.pop_front();
			cars.pop_front();
			cars.pop_front();
			carGo.push_back(hold);
			carGo.push_back(hold2);
			carGo.push_back(hold3);
		
		case 3:
			TransportMode* hold = cars[0];
			TransportMode* hold2 = cars[1];
			TransportMode* hold3 = cars[2];
			TransportMode* hold4 = cars[3];
			cars.pop_front();
			cars.pop_front();
			cars.pop_front();
			cars.pop_front();
			carGo.push_back(hold);
			carGo.push_back(hold2);
			carGo.push_back(hold3);
			carGo.push_back(hold4);

		case 4:
			TransportMode* hold = cars[0];
			TransportMode* hold2 = cars[2];
			cars[2] = cars[1];
			cars[1] = hold2;
			cars.pop_front();
			cars.pop_front();
			carGo.push_back(hold);
			carGo.push_back(hold2);
		case 5://not sure if i set this one up correctly jm
			TransportMode* hold = cars[0];
			TransportMode* hold2 = cars[3];
			cars[2] = cars[1];
			cars[1] = hold2;
			cars.pop_front();
			cars.pop_front();
			carGo.push_back(hold);
			carGo.push_back(hold2);
		case 6://not sure if i set this one up correctly jm
			TransportMode* hold = cars[0];
			TransportMode* hold2 = cars[1];
			TransportMode* hold3 = cars[3];
			cars.pop_front();
			cars.pop_front();
			cars.pop_front();
			carGo.push_back(hold);
			carGo.push_back(hold2);
			carGo.push_back(hold3);

	}
	return carGo;
}


int carDirection()
{
	int release = 0;
	if (cars.size() == 1)
	{
		release == 0;
	}
	//Start of the AI for controlling movement through the intersection. for testing anything else, change car size to 4 and comment out below.
	else if (cars.size() == 2)
	{
		if (cars[0]->getCardinalD <= 2)
		{                                         //Car1 is going straight or turning right and car2 is on opposite side
			if ((cars[0]->getDesieredD == cars[0]->getCardinalD || (cars[0]->getCardinalD + 1) == cars[0]->getDesieredD) && (cars[0]->getCardinalD + 2) == cars[1]->getCardinalD)
			{
				if (cars[1]->getDesieredD != (cars[0]->getCardinalD + 1))
				{
					release = 2;
				}
			}                                     //Car1 is heading N and turning W and car2 is heading south
			else if (cars[0]->getCardinalD == 1 && cars[0]->getDesieredD == 4 && cars[1]->getCardinalD == 3 && cars[1]->getDesieredD == 2)
			{
				release = 2;
			}                                      //Car1 is heading E and turning N and car2 is heading W
			else if (cars[0]->getCardinalD == 2 && cars[0]->getDesieredD == 1 && cars[1]->getCardinalD == 4 && cars[1]->getDesieredD == 3)
			{
				release = 2;
			}                                      //Car1 is going straight and car2 is to the left side
			else if (cars[0]->getDesieredD == cars[0]->getCardinalD && (cars[0]->getCardinalD + 1) == cars[1]->getCardinalD && (cars[1]->getCardinalD + 1) == cars[1]->getDesieredD)
			{
				release = 2;
			}                                      //Car1 is turning right and car2 is to the left
			else if ((cars[0]->getCardinalD + 1) == cars[0]->getDesieredD && (cars[0]->getCardinalD + 1) == cars[1]->getCardinalD && cars[1]->getCardinalD != cars[1]->getDesieredD)
			{
				release = 2;
			}                                      //Car1 is 
			else if (cars[0]->getCardinalD == 1 && cars[0]->getDesieredD == 4 && cars[1]->getCardinalD == 2 && cars[1]->getDesieredD == 3)
			{
				release = 2;
			}                                      //Car1 is turning left and car2 is to the left
			else if (cars[0]->getCardinalD == 2 && cars[0]->getDesieredD == 1 && cars[1]->getCardinalD == 3 && cars[1]->getDesieredD == 4)
			{
				release = 2;
			}                                      //Car1 is going straight and car2 is to the right
			else if (cars[0]->getDesieredD == 1 && cars[0]->getCardinalD == 1 && cars[1]->getCardinalD == 4 && cars[1]->getDesieredD = 3)
			{
				release = 2;
			}                                       //Car1 is going straight and car2 is to the right
			else if (cars[0]->getDesieredD == 2 && cars[0]->getCardinalD == 2 && cars[1]->getCardinalD == 1 && cars[1]->getDesieredD = 4)
			{
				release = 2;
			}

		}
		else if (cars[0]->getCardinalD > 2)
		{                                                 //Car1 is going straight and car2 is on oppoiste side
			if (cars[0]->getDesieredD == cars[0]->getCardinalD && (cars[0]->getCardinalD - 2) == cars[1]->getCardinalD)
			{
				if (cars[1]->getDesieredD != (cars[0]->getCardinalD + 1))
				{
					release = 1;
				}
			}                                                  //Car1 is turning right and car2 is on opposite side
			else if (cars[0]->getCardinalD == 3 && cars[0]->getDesieredD == 4 && (cars[0]->getCardinalD - 2) == cars[1]->getCardinalD && cars[1]->getDesieredD != 4)
			{
				release = 1;
			}                                                 //Car1 is turning right and car2 is on opposite side
			else if (cars[0]->getCardinalD == 4 && cars[0]->getDesieredD == 1 && (cars[0]->getCardinalD - 2) == cars[1]->getCardinalD && cars[1]->getDesieredD != 1)
			{
				release = 1;
			}                                               //Car1 is turning left and car2 is on opposite side
			else if ((cars[0]->getCardinalD - 1) == cars[0]->getDesieredD && (cars[0]->getCardinalD - 2) == cars[1]->getCardinalD)
			{
				if (cars[0]->getCardinalD == 3 && cars[1]->getDesieredD == 4)
				{
					release = 1;
				}															//car 1 is turning right 
				else if (cars[0]->getCardinalD == 4 && cars[1]->getDesieredD == 1)
				{
					release = 1;
				}
			}
		}																	//car 1 is going straight and car 2 is on the left
	
			else if (cars[0]->getCardinalD = 3 && cars[0]->getDesieredD = 3 && (cars[1]->getCardinalD = 4))
			{
				if (cars[1]->getDesieredD == 1)
				{
					release = 1;
				}
			}																//car 1 is going straight and car 2 is on the right
			else if (cars[0]->getCardinalD = 4 && cars[0]->getDesieredD = 4 && (cars[1]->getCardinalD = 1))
			{
				if (cars[1]->getDesieredD == 2)
				{
					release = 1;
				}
			}																//car 1 is turning right and car 2 is across
			else if (cars[0]->getCardinalD = 3 && cars[0]->getDesieredD = 4 && (cars[1]->getCardinalD = 1))
			{
				if (cars[1]->getDesieredD != 4)
				{
					release = 1;
				}	
			}																//car 1 is turning right and car 2 is on the left
			else if (cars[0]->getCardinalD = 4 && cars[0]->getDesieredD = 1 && (cars[1]->getCardinalD = 1))
			{
				if (cars[1]->getDesieredD != 1)
				{
					release = 1;
				}
			}
	}

		

	else if (cars.size() == 3 && cars[0]->getCardinalD == cars[0]->getDesieredD)
	{
		if (cars[0]->getDesieredD <= 2 && (cars[0]->getDesieredD + 2) == cars[1]->getDesieredD && (cars[0]->getDesieredD + 2) == cars[1]->getCardinalD)
		{
			release = 1;//editedjm
		}
		else if (cars[0]->getDesieredD > 2 && (cars[0]->getDesieredD - 2) == cars[1]->getDesieredD && (cars[0]->getDesieredD - 2) == cars[1]->getCardinalD)
		{
			release = 1;//editedjm
		}
		/*else if (cars[0]->getCardinalD == 1 && cars[0]->getDesieredD == 1 && cars[1]->getCardinalD = 2 && cars[1]->getDesieredD == 4)
		{
			if (cars[2]->getCardinalD == 3 && cars[2]->getDesieredD == 2)
			{
				release = 3;
			}
			else
			{
				release = 2;
			}
		}*/
	}
	else if (cars.size() == 3)
	{						//if car 1 is going straight and car 2 is turning right
		if (cars[0]->getCardinalD == 1 && cars[0]->getDesieredD == 1 && cars[1]->getCardinalD = 2 && cars[1]->getDesieredD == 3)
		{
			if (cars[2]->getCardinalD == 3 && cars[2]->getDesieredD == 4)
			{
				release = 2;//editedjm
			}
			else
			{
				release = 1;
			}
		}																		//if car 1 is going straight and car 2 is turning right
		else if (cars[0]->getCardinalD == 2 && cars[0]->getDesieredD == 2 && cars[1]->getCardinalD = 3 && cars[1]->getDesieredD == 4)
		{
			if (cars[2]->getCardinalD == 4 && cars[2]->getDesieredD == 1)
			{
				release = 2;
			}
			else
			{
				release = 1;
			}
		}																		//if car 1 is going straight and car 2 is turning right
		else if (cars[0]->getCardinalD == 3 && cars[0]->getDesieredD == 3 && cars[1]->getCardinalD = 4 && cars[1]->getDesieredD == 1)
		{
			if (cars[2]->getCardinalD == 1 && cars[2]->getDesieredD == 2)
			{
				release = 2;
			}
			else
			{
				release = 1;
			}
		}																		//if car 1 is going straight and car 2 is turning right
		else if (cars[0]->getCardinalD == 4 && cars[0]->getDesieredD == 4 && cars[1]->getCardinalD = 1 && cars[1]->getDesieredD == 2)
		{
			if (cars[2]->getCardinalD == 2 && cars[2]->getDesieredD == 3)
			{
				release = 2;
			}
			else
			{
				release = 1;
			}
		}																		//if car 1 and 2 are across from each other and going straight
		else if (cars[0]->getCardinalD == 1 && cars[0]->getDesieredD == 1 && cars[1]->getCardinalD = 3 && cars[1]->getDesieredD == 3)
		{
			release = 1;
		}																		//if car 1 and 2 are across from each other and going straight
		else if (cars[0]->getCardinalD == 2 && cars[0]->getDesieredD == 2 && cars[1]->getCardinalD = 4 && cars[1]->getDesieredD == 4)
		{
			release = 1;
		}																		//if car 1 and 2 are across from each other and going straight
		else if (cars[0]->getCardinalD == 3 && cars[0]->getDesieredD == 3 && cars[1]->getCardinalD = 1 && cars[1]->getDesieredD == 1)
		{
			release = 1;
		}																		//if car 1 and 2 are across from each other and going straight
		else if (cars[0]->getCardinalD == 4 && cars[0]->getDesieredD == 4 && cars[1]->getCardinalD = 2 && cars[1]->getDesieredD == 2)
		{
			release = 1;
		}																		//if car 1 is going straight and car 2 is turning left
		else if (cars[0]->getCardinalD == 1 && cars[0]->getDesieredD == 1 && cars[1]->getCardinalD = (cars[1]->getDesieredD + 3))
		{
			if (cars[2]->getCardinalD == 3 && cars[2]->getDesieredD == 4)
			{
				release = 4;
			}
			else
			{
				release = 1;
			}
		}																		//if car 1 is going straight and car 2 is turning left
		else if (cars[0]->getCardinalD == 2 && cars[0]->getDesieredD == 2 && cars[1]->getCardinalD = (cars[1]->getDesieredD + 3))
		{
			if (cars[2]->getCardinalD == 4 && cars[2]->getDesieredD == 1)
			{
				release = 4;
			}
			else
			{
				release = 1;
			}
		}																		//if car 1 is going straight and car 2 is turning left
		else if (cars[0]->getCardinalD == 3 && cars[0]->getDesieredD == 3 && cars[1]->getCardinalD = (cars[1]->getDesieredD + 3))
		{
			if (cars[2]->getCardinalD == 1 && cars[2]->getDesieredD == 2)
			{
				release = 4;
			}
			else
			{
				release = 1;
			}
		}																		//if car 1 is going straight and car 2 is turning left
		else if (cars[0]->getCardinalD == 4 && cars[0]->getDesieredD == 4 && cars[1]->getCardinalD = (cars[1]->getDesieredD + 3))
		{
			if (cars[2]->getCardinalD == 2 && cars[2]->getDesieredD == 3)
			{
				release = 4;
			}
			else
			{
				release = 1;
			}
		}																		//if car 1 is turning right and car 2 and 3 are not going the same direction
		else if (cars[0]->getCardinalD == 1 && cars[0]->getDesieredD == 2 && cars[1]->getDesieredD != 2)
		{
			{
				release = 1;

			}
		}																		//if car 1 is turning right and car 2 and 3 are not going the same direction
		else if (cars[0]->getCardinalD == 2 && cars[0]->getDesieredD == 3 && cars[1]->getDesieredD != 3)
		{
			{
				release = 1;

			}
		}																		//if car 1 is turning right and car 2 and 3 are not going the same direction
		else if (cars[0]->getCardinalD == 3 && cars[0]->getDesieredD == 4 && cars[1]->getDesieredD != 4)
		{
			{
				release = 1;

			}
		}																		//if car 1 is turning right and car 2 and 3 are not going the same direction
		else if (cars[0]->getCardinalD == 4 && cars[0]->getDesieredD == 1 && cars[1]->getDesieredD != 1)
		{
			{
				release = 1;

			}
		}																		//if car 1 is turning left
		else if (cars[0]->getCardinalD == 1 && cars[0]->getDesieredD == 4)
		{
			if (cars[1]->getCardinalD == 4 && cars[1]->getDesieredD == 1)
			{
				release = 1;
			}
			else if (cars[2]->getCardinalD == 4 && cars[2]->getDesieredD == 1)
			{
				release = 4;
			}
			else
			{
				release = 0;
			}
		}																		//if car 1 is turning left
		else if (cars[0]->getCardinalD == 2 && cars[0]->getDesieredD == 1)
		{
			if (cars[1]->getCardinalD == 1 && cars[1]->getDesieredD == 2)
			{
				release = 1;
			}
			else if (cars[2]->getCardinalD == 1 && cars[2]->getDesieredD == 2)
			{
				release = 4;
			}
			else
			{
				release = 0;
			}
		}																		//if car 1 is turning left
		else if (cars[0]->getCardinalD == 3 && cars[0]->getDesieredD == 2)
		{
			if (cars[1]->getCardinalD == 2 && cars[1]->getDesieredD == 3)
			{
				release = 1;
			}
			else if (cars[2]->getCardinalD == 2 && cars[2]->getDesieredD == 3)
			{
				release = 4;
			}
			else
			{
				release = 0;
			}
		}																		//if car 1 is turning left
		else if (cars[0]->getCardinalD == 4 && cars[0]->getDesieredD == 3)
		{
			if (cars[1]->getCardinalD == 3 && cars[1]->getDesieredD == 4)
			{
				release = 1;
			}
			else if (cars[2]->getCardinalD == 3 && cars[2]->getDesieredD == 4)
			{
				release = 4;
			}
			else
			{
				release = 0;
			}
		}
	}
	else if (cars.size() == 4)//if there are 4 cars in the queue
	{									//if car 1 is going straight
		if (cars[0]->getCardinalD == 1 && cars[0]->getDesieredD == 1)
		{
			if (cars[1]->getCardinalD == 3 && cars[1]->getDesieredD == 3)
			{
				release = 1;
			}
			else if (cars[2]->getCardinalD == 3 && cars[2]->getDesieredD == 3)
			{
				release = 4;
			}
			else if (cars[3]->getCardinalD == 3 && cars[3]->getDesieredD == 3)
			{
				release = 5;
			}																									//if the car across from 1 is not heading straight
			else if ((cars[1]->getCardinalD == 3 && cars[1]->getDesieredD != 3) || (cars[2]->getCardinalD == 3 && cars[2]->getDesieredD != 3) || (cars[3]->getCardinalD == 3 && cars[3]->getDesieredD != 3))
			{												
				if (cars[1]->getCardinalD == 3 && cars[1]->getDesieredD == 4)
				{
					if (cars[2]->getCardinalD == 2 && cars[2]->getDesieredD == 3)
					{
						release = 2;
					}
					else if (cars[3]->getCardinalD == 2 && cars[3]->getDesieredD == 3)
					{
						release = 6;
					}
					else
					{
						release = 1;
					}
				}
				else if (cars[1]->getCardinalD == 2 && cars[1]->getDesieredD == 3)
				{
					if (cars[2]->getCardinalD == 3 && cars[2]->getDesieredD == 4)
					{
						release = 2;
					}
					else if (cars[2]->getCardinalD == 3 && cars[2]->getDesieredD == 4)
					{
						release = 6;
					}
					else
					{
						release = 1;
					}
				}
			}
		}											//if car 1 is going straight 
		else if (cars[0]->getCardinalD == 2 && cars[0]->getDesieredD == 2)
		{
			if (cars[1]->getCardinalD == 4 && cars[1]->getDesieredD == 4)
			{
				release = 1;
			}
			else if (cars[2]->getCardinalD == 4 && cars[2]->getDesieredD == 4)
			{
				release = 4;
			}
			else if (cars[3]->getCardinalD == 4 && cars[3]->getDesieredD == 4)
			{
				release = 5;
			}																									//if the car across from 1 is not heading straight
			else if ((cars[1]->getCardinalD == 4 && cars[1]->getDesieredD != 4) || (cars[2]->getCardinalD == 4 && cars[2]->getDesieredD != 4) || (cars[3]->getCardinalD == 4 && cars[3]->getDesieredD != 4))
			{
				if (cars[1]->getCardinalD == 4 && cars[1]->getDesieredD == 1)
				{
					if (cars[2]->getCardinalD == 3 && cars[2]->getDesieredD == 4)
					{
						release = 2;
					}
					else if (cars[3]->getCardinalD == 3 && cars[3]->getDesieredD == 4)
					{
						release = 6;
					}
					else
					{
						release = 1;
					}
				}
				else if (cars[1]->getCardinalD == 3 && cars[1]->getDesieredD == 4)
				{
					if (cars[2]->getCardinalD == 4 && cars[2]->getDesieredD == 1)
					{
						release = 2;
					}
					else if (cars[2]->getCardinalD == 4 && cars[2]->getDesieredD == 1)
					{
						release = 6;
					}
					else
					{
						release = 1;
					}
				}
			}
		}														//if car 1 is going straight
		else if (cars[0]->getCardinalD == 3 && cars[0]->getDesieredD == 3)
		{
			if (cars[1]->getCardinalD == 1 && cars[1]->getDesieredD == 1)
			{
				release = 1;
			}
			else if (cars[2]->getCardinalD == 1 && cars[2]->getDesieredD == 1)
			{
				release = 4;
			}
			else if (cars[3]->getCardinalD == 1 && cars[3]->getDesieredD == 1)
			{
				release = 5;
			}																									//if the car across from 1 is not heading straight
			else if ((cars[1]->getCardinalD == 1 && cars[1]->getDesieredD != 1) || (cars[2]->getCardinalD == 1 && cars[2]->getDesieredD != 1) || (cars[3]->getCardinalD == 1 && cars[3]->getDesieredD != 1))
			{
				if (cars[1]->getCardinalD == 1 && cars[1]->getDesieredD == 2)
				{
					if (cars[2]->getCardinalD == 4 && cars[2]->getDesieredD == 1)
					{
						release = 2;
					}
					else if (cars[3]->getCardinalD == 4 && cars[3]->getDesieredD == 1)
					{
						release = 6;
					}
					else
					{
						release = 1;
					}
				}
				else if (cars[1]->getCardinalD == 4 && cars[1]->getDesieredD == 1)
				{
					if (cars[2]->getCardinalD == 1 && cars[2]->getDesieredD == 2)
					{
						release = 2;
					}
					else if (cars[2]->getCardinalD == 1 && cars[2]->getDesieredD == 2)
					{
						release = 6;
					}
					else
					{
						release = 1;
					}
				}									//if car 1 is going straight
				else if (cars[0]->getCardinalD == 4 && cars[0]->getDesieredD == 4)
				{
					if (cars[1]->getCardinalD == 2 && cars[1]->getDesieredD == 2)
					{
						release = 1;
					}
					else if (cars[2]->getCardinalD == 2 && cars[2]->getDesieredD == 2)
					{
						release = 4;
					}
					else if (cars[3]->getCardinalD == 2 && cars[3]->getDesieredD == 2)
					{
						release = 5;
					}																									//if the car across from 1 is not heading straight
					else if ((cars[1]->getCardinalD == 2 && cars[1]->getDesieredD != 2) || (cars[2]->getCardinalD == 2 && cars[2]->getDesieredD != 2) || (cars[3]->getCardinalD == 2 && cars[3]->getDesieredD != 2))
					{
						if (cars[1]->getCardinalD == 2 && cars[1]->getDesieredD == 3)
						{
							if (cars[2]->getCardinalD == 1 && cars[2]->getDesieredD == 2)
							{
								release = 2;
							}
							else if (cars[3]->getCardinalD == 1 && cars[3]->getDesieredD == 2)
							{
								release = 6;
							}
							else
							{
								release = 1;
							}
						}
					}
					else if (cars[1]->getCardinalD == 1 && cars[1]->getDesieredD == 2)
					{
						if (cars[2]->getCardinalD == 2 && cars[2]->getDesieredD == 3)
						{
							release = 2;
						}
						else if (cars[2]->getCardinalD == 2 && cars[2]->getDesieredD == 3)
						{
							release = 6;
						}
						else
						{
							release = 1;
						}
					}
				}
			}
		}		//if car 1 is turning left
		else if (cars[0]->getCardinalD == 1 && cars[0]->getDesieredD == 4)
		{
			if (cars[1]->getCardinalD == 4 && cars[1]->getDesieredD == 1)
			{
				release = 1;
			}
			else if(cars[2]->getCardinalD == 4 && cars[2]->getDesieredD == 1)
			{
				release = 4;
			}
			else if (cars[3]->getCardinalD == 4 && cars[3]->getDesieredD == 1)
			{
				release = 5;
			}
		}		//if car 1 is turning left
		else if (cars[0]->getCardinalD == 2 && cars[0]->getDesieredD == 1)
		{
			if (cars[1]->getCardinalD == 1 && cars[1]->getDesieredD == 2)
			{
				release = 1;
			}
			else if (cars[2]->getCardinalD == 1 && cars[2]->getDesieredD == 2)
			{
				release = 4;
			}
			else if (cars[3]->getCardinalD == 1 && cars[3]->getDesieredD == 2)
			{
				release = 5;
			}
		}		//if car 1 is turning left
		else if (cars[0]->getCardinalD == 3 && cars[0]->getDesieredD == 2)
		{
			if (cars[1]->getCardinalD == 2 && cars[1]->getDesieredD == 3)
			{
				release = 1;
			}
			else if (cars[2]->getCardinalD == 2 && cars[2]->getDesieredD == 3)
			{
				release = 4;
			}
			else if (cars[3]->getCardinalD == 2 && cars[3]->getDesieredD == 3)
			{
				release = 5;
			}
		}		//if car 1 is turning left
		else if (cars[0]->getCardinalD == 4 && cars[0]->getDesieredD == 3)
		{
			if (cars[1]->getCardinalD == 3 && cars[1]->getDesieredD == 4)
			{
				release = 1;
			}
			else if (cars[2]->getCardinalD == 3 && cars[2]->getDesieredD == 4)
			{
				release = 4;
			}
			else if (cars[3]->getCardinalD == 3 && cars[3]->getDesieredD == 4)
			{
				release = 5;
			}
		}		//if car 1 is turning right
		else if (cars[0]->getCardinalD == 1 && cars[0]->getDesieredD == 2)
		{
			if (cars[1]->getDesieredD != 2)
			{
				release = 1;
			}
		}		//if car 1 is turning right
		else if (cars[0]->getCardinalD == 2 && cars[0]->getDesieredD == 3)
		{
			if (cars[1]->getDesieredD != 3)
			{
				release = 1;
			}
		}		//if car 1 is turning right
		else if (cars[0]->getCardinalD == 3 && cars[0]->getDesieredD == 4)
		{
			if (cars[1]->getDesieredD != 4)
			{
				release = 1;
			}
		}		//if car 1 is turning right
		else if (cars[0]->getCardinalD == 4 && cars[0]->getDesieredD == 1)
		{
			if (cars[1]->getDesieredD != 1)
			{
				release = 1;
			}
		}		//if all cars are turning right
		else if ((cars[0]->getCardinalD == cars[0]->getDesieredD + 1) && (cars[1]->getCardinalD == cars[1]->getDesieredD + 1) && (cars[2]->getCardinalD == cars[2]->getDesieredD + 1) && (cars[3]->getCardinalD == cars[3]->getDesieredD + 1))
		{
			release = 3;
		}
	}
}

}; 
