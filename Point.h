//Christine Sobolewski, Adam Gunnell, Jack Grebb
#pragma once
#include "Includes.h"
#include "Includes.h"
#include "MapOBJ.h"
#include "main.h"
#include "TransportMode.h"
#include "Vehicle.h"
#include "Bus.h"
#include "Car.h"
#include "Semi.h"
#include "Sportscar.h"
#include "Truck.h"
#include "Van.h"
#include <algorithm>

struct Point
{
	double x;
	double y;
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
	bool onSegment = false;
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
	{
		onSegment = true;
	}
	return onSegment;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r) 
{
	double val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;  // colinear

	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	// Find the four orientations needed for general and
	// special cases
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	// General case
	if (o1 != o2 && o3 != o4)
		return true;

	// Special Cases
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;

	// p1, q1 and p2 are colinear and q2 lies on segment p1q1
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;

	return false; // Doesn't fall in any of the above cases
}

//Jack Grebb and Adam Gunnell
//Close Enough to Use Crash Detector Fxn
//Find the distance between the two centers of the vehicle. If the distance between the two circles
//is less than the two raidus' added together than the two circles collide.
bool VehicleRadius(Vehicle* vehicle1, Vehicle* vehicle2)
{
	bool overlap = false; //True if the circles overlap, false if the circles don't
						  //Radius for Vehicle1 Circle
	double radius1 = 0.5 * sqrt((((*vehicle1).getWidth())*((*vehicle1).getWidth())) + (((*vehicle1).getLength())*((*vehicle1).getLength())));
	//Radius for Vehicle2 Circle
	double radius2 = 0.5 * sqrt(((vehicle2->getWidth())*((*vehicle2).getWidth())) + (((*vehicle2).getLength())*((*vehicle2).getLength())));

	double base = (*vehicle1).getX() - (*vehicle2).getX();  //Finds the difference between x-coordinates
	double height = (*vehicle1).getY() - (*vehicle2).getY();  //Finds difference between y-coordinates
	double gap = sqrt(base*base + height*height); //distance between the centers of the two vehicles

	if (gap < (radius1 + radius2))
	{
		overlap = true;
	}
	else
	{
		overlap = false;
	}

	return overlap;
}

//Christine Sobolewski
//Crash Detector
//Only detects a crash for two vehicles
bool DetectCrash(Vehicle* vehicle1, Vehicle* vehicle2, double theta1, double theta2)
//theta is the angle that the vehicle is facing (angle from east)
{
	bool crashed = false;

	double tempX1 = vehicle1->getLength() / 2;  //Temp x-coordinate for Vehicle 1
	double tempY1 = vehicle1->getWidth() / 2;     //Temp y-coordinate for Vehicle 1
	double tempX2 = vehicle2->getLength() / 2;  //Temp x-coordinate for Vehicle 2
	double tempY2 = vehicle2->getWidth() / 2;    //Temp y-coordinate for Vehicle 2


												 //Vehicle 1 Coordinates
	Point corner1;
	double rotatedX1 = tempX1*cos(theta1) - tempY1*sin(theta1);
	double rotatedY1 = tempX1*sin(theta1) + tempY1*cos(theta1);

	corner1.x = rotatedX1 + (*vehicle1).getX();
	corner1.y = rotatedY1 + (*vehicle1).getY();

	Point corner2;
	double rotatedX2 = tempX1*cos(theta1) + tempY1*sin(theta1);
	double rotatedY2 = tempX1*sin(theta1) - tempY1*cos(theta1);

	corner2.x = rotatedX2 + (*vehicle1).getX();
	corner2.y = rotatedY2 + (*vehicle1).getY();

	Point corner3;
	double rotatedX3 = tempX1*cos(theta1) + tempY1*sin(theta1);
	double rotatedY3 = -tempX1*sin(theta1) + tempY1*cos(theta1);

	corner3.x = rotatedX3 + (*vehicle1).getX();
	corner3.y = rotatedY3 + (*vehicle1).getY();

	Point corner4;
	double rotatedX4 = -tempX1*cos(theta1) + tempY1*sin(theta1);
	double rotatedY4 = -tempX1*sin(theta1) - tempY1*cos(theta1);

	corner4.x = rotatedX4 + (*vehicle1).getX();
	corner4.y = rotatedY4 + (*vehicle1).getY();


	//Vehicle 2 Coordinates
	Point corner5;
	double rotatedX5 = tempX2*cos(theta2) - tempY2*sin(theta2);
	double rotatedY5 = tempX2*sin(theta2) + tempY2*cos(theta2);

	corner5.x = rotatedX5 + (*vehicle2).getX();
	corner5.y = rotatedY5 + (*vehicle2).getY();

	Point corner6;
	double rotatedX6 = tempX2*cos(theta2) + tempY2*sin(theta2);
	double rotatedY6 = tempX2*sin(theta2) - tempY2*cos(theta2);

	corner6.x = rotatedX6 + (*vehicle2).getX();
	corner6.y = rotatedY6 + (*vehicle2).getY();

	Point corner7;
	double rotatedX7 = tempX2*cos(theta2) + tempY2*sin(theta2);
	double rotatedY7 = -tempX2*sin(theta2) + tempY2*cos(theta2);

	corner7.x = rotatedX7 + (*vehicle2).getX();
	corner7.y = rotatedY7 + (*vehicle2).getY();

	Point corner8;
	double rotatedX8 = -tempX2*cos(theta2) + tempY2*sin(theta2);
	double rotatedY8 = -tempX2*sin(theta2) - tempY2*cos(theta2);

	corner8.x = rotatedX8 + (*vehicle2).getX();
	corner8.y = rotatedY8 + (*vehicle2).getY();

	//Line Segment 1 : corner1 and corner2
	//Line Segment 2 : corner1 and corner3
	//Line Segment 3 : corner2 and corner4
	//Line Segment 4 : corner3 and corner4
	//Line Segment 5 : corner5 and corner6
	//Line Segment 6 : corner5 and corner7
	//Line Segment 7 : corner6 and corner8
	//Line Segment 8 : corner7 and corner8

	//Line Segment 1,2,3,4 intersect with 5,6,7,8
	Point v1[4];
	Point v2[4];

	v1[0] = corner1;
	v1[1] = corner2;
	v1[2] = corner3;
	v1[3] = corner4;

	v2[0] = corner5;
	v2[1] = corner6;
	v2[2] = corner7;
	v2[3] = corner8;

	//This runs 36 times. It accounts for the four edges, as well as, the diagonal lines.
	for (int i = 0; i <= 3 && !crashed; i++)
	{
		for (int j = 0; j <= 3 && !crashed && i != j; j++)
		{
			for (int x = 0; x <= 3 && !crashed; x++)
			{
				for (int y = 0; y <= 3 && !crashed && x != y; y++)
				{
					crashed = doIntersect(v1[i], v1[j], v2[x], v2[y]);
				}
			}
		}
	}
	return crashed;
}