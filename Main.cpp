#pragma once
#include "Includes.h"
string colorToString(LIGHTCOLOR inColor)
{
	switch (inColor)
	{
	case RED:
		return "Red";
	case GREEN:
		return "Green";
	case YELLOW:
		return "Yellow";
	default:
		return "ERROR in ColorToString(*)";
	}
}
void main()
{
	TraficSignal sampleLight(12, 1, 1, 1, 1);
	cout << sampleLight.getLengthOfCycle() << endl;
	//set all lights red for 3 seconds
	int preCount = sampleLight.getLengthOfCycle();
	for (int i = preCount; i < preCount + 3; i++)
	{
		//sampleLight.setLightCycle(Direction, LightColor, Lane, SecondInterval);
		sampleLight.setLightCycle(NORTH, RED, 0, i);
		sampleLight.setLightCycle(SOUTH, RED, 0, i);
		sampleLight.setLightCycle(EAST, RED, 0, i);
		sampleLight.setLightCycle(WEST, RED, 0, i);
	}

	//set north and south green for 10 seconds
	preCount = sampleLight.getLengthOfCycle();
	for (int i = preCount; i < preCount + 10; i++)
	{
		sampleLight.setLightCycle(NORTH, GREEN, 0, i);
		sampleLight.setLightCycle(SOUTH, GREEN, 0, i);
		sampleLight.setLightCycle(EAST, RED, 0, i);
		sampleLight.setLightCycle(WEST, RED, 0, i);
	}

	//set north and south yellow for 3 seconds
	preCount = sampleLight.getLengthOfCycle();
	for (int i = preCount; i < preCount + 3; i++)
	{
		sampleLight.setLightCycle(NORTH, YELLOW, 0, i);
		sampleLight.setLightCycle(SOUTH, YELLOW, 0, i);
		sampleLight.setLightCycle(EAST, RED, 0, i);
		sampleLight.setLightCycle(WEST, RED, 0, i);
	}

	//set all lights to red for 3 seconds
	preCount = sampleLight.getLengthOfCycle();
	for (int i = preCount; i < preCount + 3; i++)
	{
		sampleLight.setLightCycle(NORTH, RED, 0, i);
		sampleLight.setLightCycle(SOUTH, RED, 0, i);
		sampleLight.setLightCycle(EAST, RED, 0, i);
		sampleLight.setLightCycle(WEST, RED, 0, i);
	}

	//now set east and wet green
	preCount = sampleLight.getLengthOfCycle();
	for (int i = preCount; i < preCount + 10; i++)
	{
		sampleLight.setLightCycle(NORTH, RED, 0, i);
		sampleLight.setLightCycle(SOUTH, RED, 0, i);
		sampleLight.setLightCycle(EAST, GREEN, 0, i);
		sampleLight.setLightCycle(WEST, GREEN, 0, i);
	}

	//set east and west to yellow
	preCount = sampleLight.getLengthOfCycle();
	for (int i = preCount; i < preCount + 3; i++)
	{
		sampleLight.setLightCycle(NORTH, RED, 0, i);
		sampleLight.setLightCycle(SOUTH, RED, 0, i);
		sampleLight.setLightCycle(EAST, YELLOW, 0, i);
		sampleLight.setLightCycle(WEST, YELLOW, 0, i);
	}


	//output the light cycle endlessly for the user to see
	//press CTRL+C to stop the program from running
	int time = 0;
	while (true)
	{
		if (time >= sampleLight.getLengthOfCycle())
			time = 0;
		sampleLight.setLightTime(time);
		system("cls");
		cout << "Time Cycle\t\t" << time << endl << endl;
		cout << "North Light Color:\t" << colorToString(sampleLight.getLightColor(NORTH, 0)) << endl;
		cout << "East Light Color:\t" << colorToString(sampleLight.getLightColor(EAST, 0)) << endl;
		cout << "South Light Color:\t" << colorToString(sampleLight.getLightColor(SOUTH, 0)) << endl;
		cout << "West Light Color:\t" << colorToString(sampleLight.getLightColor(WEST, 0)) << endl;
		time++;
		Sleep(500);
	}
	

	return;
}