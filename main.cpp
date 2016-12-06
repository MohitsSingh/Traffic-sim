#include "Includes.h"
#include "Point.h"

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
//Crash Detector
//Only detects a crash for two vehicles
bool DetectCrash(Vehicle* vehicle1, Vehicle* vehicle2, double theta1, double theta2)
//theta is the angle that the vehicle is facing (angle from east)
{
	bool crashed = false;

	double tempX1 = vehicle1->getLength() / 2;  //Temp x-coordinate for Vehicle 1
	double tempY1 = vehicle1->getWidth()/2;     //Temp y-coordinate for Vehicle 1
	double tempX2 = vehicle2->getLength() / 2;  //Temp x-coordinate for Vehicle 2
	double tempY2 = vehicle2->getWidth() /2;    //Temp y-coordinate for Vehicle 2
	

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
		for (int j = 0; j <= 3 && !crashed && i!=j; j++)
		{
			for (int x = 0; x <= 3 && !crashed; x++)
			{
				for (int y = 0; y <= 3 && !crashed  && x!=y; y++)
				{
					crashed = doIntersect(v1[i], v1[j], v2[x], v2[y]);
				}
			}
		}
	}
	return crashed;
} 

int main()
{
	Bus* bus = new Bus(0.0, 0.0);
	Car* car = new Car(10.0, 9.0);
	bool crash = DetectCrash(bus, car, 90*PI/180, 135*PI/180);
	if (crash == true)
	{
		cout << "Bus and Car have crashed." << endl;
		cout << "Bus: " << (*bus).getX() << "   " << (*bus).getY() << endl;
		cout << "Car: " << (*car).getX() << "   " << (*car).getY() << endl;
	}
	else if (crash == false)
	{
		cout << "Bus and Car have not crashed." << endl;
		cout << "Car: " << (*bus).getX() << "   " << (*bus).getY() << endl;
		cout << "Bus: " << (*car).getX() << "   " << (*car).getY() << endl;
	}

	//int count = 0;   //Counting the number of times DetectCrash Runs
	for (int i = 0; i < 70; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			Bus* bus = new Bus(i, j);
			Car* car = new Car(j, i);
			if (VehicleRadius(bus, car) == true)
			{
				bool crash = DetectCrash(bus, car, 90 * PI / 180, 135 * PI / 180);
				//count++;
			}
		}
	}
	//cout << count << endl;
	system("pause");
	return 0;
}
