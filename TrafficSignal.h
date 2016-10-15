#pragma once
class Signal
{
private:
	bool fixedSign;					//type of control at intersection
	bool lightedSignal;				//type of control at intersection	
	double latitude;				//center of intersection position
	double longitude;				//center of intersection position
	int numberOfPossDirections;		//number of road direction at internsection

	class ElecControlled
	{
		string intersectionName;
		double controlledDirection;				//compass reading when facing that direction from middle (1-360 360=North)
		double direction;						//compass converted to radians
		bool twoWayTraffic;						//true on two way streets
		bool twoWaySlaveToOppDir;				//true if you want to slave opposite directions signal
		int directionToSlaveTo;					//enter the direction number starting with 1
		bool leftTurnArrow;						//true if there is a left arrow
		bool leftDoubleTurn;					//true if its a double lane left
		bool rightTurnArrow;					//true if there is right turn arrow
		bool timeTriggeredCycle;				//false for sensor triggered signal, true for timed signal
		bool crosswalk;							//true if there are crosswalk signals
		int redTime;							//red light time in seconds
		int ylwTime;							//yellow light time in seconds
		int grnTime;							//green light time in seconds
		int walkTime;							//walk time
		int walkWarningTime;					//walk warning time
		int dontWalk;							//dont walk time
	};

	class SignControlled
	{
		string intersectionName;
		int signType;							//stop, yield, etc.
		int directionNumber;					//number the possible choices
		double controlledDirection;				//radians east is zero
		bool twoWayTraffic;						//true on two way streets

	};




public:
	Signal();
	Signal::Signal(bool signControled);
	void Signal::setLongitude(double inputLongitude);
	void Signal::setlatitude(double inputlatitude);
	void Signal::setNumberOfPossDirections(int dir);

	/*void Signal::Signal() : SignControlled(string str));

	void Signal::SignControlled : setIntersectionName(string str)*/


	~Signal();

};






