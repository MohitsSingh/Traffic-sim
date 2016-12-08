/***
WORK IN PROGRESS!!
***/
#pragma once
#include "Includes.h"
#include "TraficSignal.h"

LIGHTCOLOR TraficSignal::getLightColor(CARDINAL dir)
{
	switch (dir)
	{
	case NORTH:
		return curStraightColor[NORTH];
		break;
	case SOUTH:
		return curStraightColor[SOUTH];
		break;
	case EAST:
		return curStraightColor[EAST];
		break;
	case WEST:
		return curStraightColor[WEST];
		break;
	default:
		break;
	}
}

TraficSignal::TraficSignal()
{
	interType = LIGHT;
	curStraightColor[NORTH] = GREEN;
	curStraightColor[SOUTH] = GREEN;
	curStraightColor[EAST] = RED;
	curStraightColor[WEST] = RED;

	strightTimeCycles[GREEN] = 7;
	strightTimeCycles[YELLOW] = 3;
	strightTimeCycles[RED] = 10;
}

void TraficSignal::updateSignal()
{
	for (int i = 0; i < 4; i++)
	{
		curTime[i]--;
		if (curTime[i] <= 0)
		{
			switch (curStraightColor[i])
			{
			case RED:
				curStraightColor[i] = GREEN;
				curTime[i] = strightTimeCycles[GREEN];
				break;
			case YELLOW:
				curStraightColor[i] = RED;
				curTime[i] = strightTimeCycles[RED];
				break;
			case GREEN:
				curStraightColor[i] = YELLOW;
				curTime[i] = strightTimeCycles[YELLOW];
				break;
			}
		}
	}
}
