
#include "Includes.h"

void print(Road);//Prints a road object. KC

int main() {
	
	DataReader DataNS;
	DataNS.readData("NS.csv");  //Reads in Data from csv KC
	
	DataReader DataEW;
	DataEW.readData("EW.csv");  
	
	/*cout << "NS Rows: " << DataNS.getRowSize() << endl;
	cout << "NS Columns: " << DataNS.getColumnSize() << endl;
	
	//Test to check row number KC

	cout << "EW Rows: " << DataEW.getRowSize() << endl;
	cout << "EW Columns: " << DataEW.getColumnSize() << endl;*/

	Road *NSroads;
	Road *EWroads;
	NSroads = new Road[DataNS.getRowSize()]; //Array of North and South Bound Roads KC
	EWroads = new Road[DataEW.getRowSize()]; //Array of East and West Bound Roads KC

	int count;  //Counter KC

	RightLane Rightlane; LeftLane LeftLane; // They all have a width of 3 however these lanes are regular lanes. KC

	RightBikeLane RightBikeLane; LeftBikeLane LeftBikeLane; //Various lanes for different widths KC

	RightTurnLane RightTurnlane; LeftTurnLane LeftTurnLane;


	for (count = 1; count <  DataNS.getRowSize(); count++) { //Fills the array of roads with data KC

		NSroads[count].setNameNB(DataNS.getDataCell(count, 1));
		NSroads[count].setNameSB(DataNS.getDataCell(count, 1));

		NSroads[count].setSpeedLimitNB(atoi(DataNS.getDataCell(count, 2).c_str()));
		NSroads[count].setSpeedLimitSB(atoi(DataNS.getDataCell(count, 2).c_str()));

		NSroads[count].setNS(true);
		NSroads[count].setEW(false);
		
	}
	
	for (count = 1; count <  DataEW.getRowSize(); count++) {

		EWroads[count].setNameEB(DataEW.getDataCell(count, 1));
		EWroads[count].setNameWB(DataEW.getDataCell(count, 1));

		EWroads[count].setSpeedLimitEB(atoi(DataEW.getDataCell(count, 2).c_str()));
		EWroads[count].setSpeedLimitWB(atoi(DataEW.getDataCell(count, 2).c_str()));

		EWroads[count].setEW(true);
		EWroads[count].setNS(false);
	}

	for (int i = 1; i < DataNS.getRowSize(); i++) { //Prints each road object out KC
		print(NSroads[i]);
	}
	system("pause");

	cout << endl << endl;

	for (int i = 1; i < DataEW.getRowSize(); i++) {
		print(EWroads[i]);
	}
	
	system("pause");
	cout << endl;
	cout << "Example Right Lane Width: " << Rightlane.getWidth() << endl; // Example of Lane Width KC
	cout << endl;
	return 0;
}

void print(Road p) {
	
	if (p.getEW() == true) {  //If its a East/West Road then it will print the EB and WB Data Values KC
		cout << "NAME East Bound: " << " " << p.getNameEB() << endl;
		cout << "NAME West Bound: " << " " << p.getNameWB() << endl << endl;


		cout << "SpeedLimit East Bound: " << " " << p.getSpeedLimitEB() << endl;
		cout << "SpeedLimit West Bound: " << " " << p.getSpeedLimitWB() << endl << endl;

	}
	else if (p.getNS() == true) {  //If its a North/South Road then it will print the NB and SB Data Values
		cout << "NAME North Bound: " << " " << p.getNameNB() << endl;
		cout << "NAME South Bound: " << " " << p.getNameSB() << endl << endl;


		cout << "SpeedLimit North Bound: " << " " << p.getSpeedLimitNB() << endl;
		cout << "SpeedLimit South Bound: " << " " << p.getSpeedLimitSB() << endl << endl;

	}

	else
		cout << "error" << endl; //If the road isnt NS or EW then its an error KC
	
}



