#include "Includes.h"

void print(Road[], int); //Prints the array.(array, sizeOFArray)

int main() {

   DataReader myDataReader;													
	myDataReader.readData("road-info1.csv");
	cout << "Rows:\t\t" << myDataReader.getRowSize() << endl;			
	cout << "Columns:\t" << myDataReader.getColumnSize() << endl;


	int count;  //Counter KC
	int width;
	Road roads[10];  //Array of Roads  KC
	Lane lane; bikeLane bikelane; turnLane turnlane;

	//streets[1].setSpeedLimit(65);
	
	for (count = 1; count < myDataReader.getRowSize(); count++) {    //Fills The array from the .csv file   KC
                                                                    //and sets values to the class variables.	   KC	
 		roads[count].setS(myDataReader.getDataCell(count, 1));        //Sets Street Name  KC
		                                                                         //Sets the number of lanes by converting  KC
		                                                                         //it from a string to a integer
		
 		roads[count].setlanes(atoi(myDataReader.getDataCell(count, 2).c_str()) );//Normal Lanes 2
		roads[count].setblanes(atoi(myDataReader.getDataCell(count, 3).c_str()));//Bike Lanes 3
		roads[count].settlanes(atoi(myDataReader.getDataCell(count, 4).c_str()));//Turn Lanes KC 4

      width = (lane.getWidth()*roads[count].getlanes()) + (bikelane.getWidth()*roads[count].getblanes()) + 
		(turnlane.getWidth()*roads[count].gettlanes());
		roads[count].setRoadWidth(width);                //Calculates and sets Road width based off of how many/ which type of lanes.

	}

	
   
	cout << roads[2].getRoadWidth() << "\n\n\n";

	print(roads, myDataReader.getRowSize());  

	return 0;

}

void print(Road p[],int x) { 
	for (int i = 1; i < x; i++) {
		cout << p[i].getS() << '\n';
		cout << p[i].getlanes() << '\n';
	}
}

