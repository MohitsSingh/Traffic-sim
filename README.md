# Instructions to access the Fort Collins city data in your code

Here are the getters you can use to access the data.  They reside in the class IntersectionData.  To get a particular intersection’s data, call these getters with the inputId of that intersection number.

For example:    
1.Define an instance of IntersectionData, say myIntersectionData in main.   

IntersectionData myIntersectionData;    

2.The following statement will get intersection #1 data into the variable "identity" for the northbound street name,  

identity = myIntersectionData.getNameNB(1);   

This sequence call would result in the string “College” being placed in the variable name.    

----------------
LINK DATA // Data from the Link Section of the csv file  

// UpId is the intersection number prior to current intersection in the given direction
int getUpIdNB(int inputId);					
int getUpIdSB(int inputId);					
int getUpIdEB(int inputId);					
int getUpIdWB(int inputId);					

// Number of lanes in the given direction	
int getLanesNB(int inputID);			
int getLanesSB(int inputID);				
int getLanesEB(int inputID);			
int getLanesWB(int inputID);				

// Name of the streets in the given direction	
string getNameNB(int inputId);			
string getNameSB(int inputId);			
string getNameEB(int inputId);			
string getNameWB(int inputId);				

// Distance in feet from the prior intersection to the current intersection in the given direction	
int getDistanceNB(int inputId);		
int getDistanceSB(int inputId);		
int getDistanceEB(int inputId);		
int getDistanceWB(int inputId);

// Speed limit in current intersection in the given direction	
int getSpeedLimitNB(int inputId);		
int getSpeedLimitSB(int inputId);		
int getSpeedLimitEB(int inputId);		
int getSpeedLimitWB(int inputId);		

------------
PHASING DATA // Data from the Phasing Section of the csv file		

// columns  
D1 – Northbound Left Turn					
D2 – Southbound Thru/Right				
D3 – Westbound Left Turn				
D4 – Eastbound Thru					
D5 – Southbound Left Turn					
D6 – Northbound Thru					
D7 – Eastbound Left Turn					
D8 – Westbound Thru					

// minimum seconds for a green light in the given direction		
double getMinGreenD1(int inputId);			
double getMinGreenD2(int inputId);			
double getMinGreenD3(int inputId);			
double getMinGreenD4(int inputId);			
double getMinGreenD5(int inputId);			
double getMinGreenD6(int inputId);			
double getMinGreenD7(int inputId);			
double getMinGreenD8(int inputId);			
double getMinGreenD9(int inputId);			
double getMinGreenD10(int inputId);			
double getMinGreenD14(int inputId);			

// maximum seconds for a green light in the given direction		
double getMaxGreenD1(int inputId);			
double getMaxGreenD2(int inputId);			
double getMaxGreenD3(int inputId);			 
double getMaxGreenD4(int inputId);			
double getMaxGreenD5(int inputId);			
double getMaxGreenD6(int inputId);			
double getMaxGreenD7(int inputId);			
double getMaxGreenD8(int inputId);			
double getMaxGreenD9(int inputId);			
double getMaxGreenD10(int inputId);			
double getMaxGreenD14(int inputId);			

// seconds for a yellow light in the given direction		
double getYellowD1(int inputId);			
double getYellowD2(int inputId);		
double getYellowD3(int inputId);		
double getYellowD4(int inputId);		
double getYellowD5(int inputId);		
double getYellowD6(int inputId);		
double getYellowD7(int inputId);		
double getYellowD8(int inputId);		

// seconds when all the lights are red in a given direction		
double getAllRedD1(int inputId);		
double getAllRedD2(int inputId);		
double getAllRedD3(int inputId);		
double getAllRedD4(int inputId);		
double getAllRedD5(int inputId);		
double getAllRedD6(int inputId);		
double getAllRedD7(int inputId);		
double getAllRedD8(int inputId);		

// seconds for a walk light in a given direction		
double getWalkD1(int inputId);				
double getWalkD2(int inputId); 			
double getWalkD3(int inputId); 					
double getWalkD4(int inputId); 				
double getWalkD5(int inputId); 				
double getWalkD6(int inputId);				
double getWalkD7(int inputId); 				
double getWalkD8(int inputId); 			
double getWalkD9(int inputId); 				
double getWalkD10(int inputId);			 
double getWalkD14(int inputId);				 

// seconds for don't walk light in a given direction		
double getDontWalkD1(int inputId);			
double getDontWalkD2(int inputId);		
double getDontWalkD3(int inputId);		
double getDontWalkD4(int inputId);		
double getDontWalkD5(int inputId);		
double getDontWalkD6(int inputId);		
double getDontWalkD7(int inputId);		
double getDontWalkD8(int inputId);		

// seconds for  yield light in a given direction		
double getYieldD1(int inputId);			
double getYieldD2(int inputId);			
double getYieldD3(int inputId);		
double getYieldD4(int inputId);		
double getYieldD5(int inputId);		
double getYieldD6(int inputId);		
double getYieldD7(int inputId);		
double getYieldD8(int inputId);  	

---------------------

contributers: Andrew, Jackie
