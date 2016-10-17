// Matt Johnson 10-16

#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

int main()
{
	/* Reminders of all options at stoplight. 
	char nbT; North Bound Through
	char nbR; North Bound Right
	char nbL; North Bound Left
	char sbT; South Bound Through
	char sbR; South Bound Right
	char sbL; South Bound Left
	char wbT; West Bound Through
	char wbR; West Bound Right
	char wbL; West Bound Left
	char ebT; East Bound Through
	char ebR; East Bound Right
	char ebL; East Bound Left */

	// One loop will cycle all lights green once. 
	// There is no right turn light in this intersection. The right turn can happen at any time as long as there are no cars and turning is clear.
	// Do we want the red arrow displayed on every change?

	for (int i = 0; i < 10; i++) // Limited the loop for testing purposes. 
	{
		cout << "Green Arrow North Bound Left\n"; // Green Left Turn North/South
		cout << "Green Arrow South Bound Left\n";
		cout << "Red Arrow  East Bound Left\n";
		cout << "Red Arrow  West Bound Left\n";
		cout << "Red Light  North Bound Through\n"; // Left turn set. Can add right turn greens if wanted
		cout << "Red Light  South Bound Through\n";
		cout << "Red Light  East Bound Through\n";
		cout << "Red Light  West Bound Through\n";
		
	sleep_until(system_clock::now() + 5s); // Time North/South Left Turns

		cout << "Yellow Arrow North Bound Left"; // Yellow Left Turn North/South
		cout << "Yellow Arrow South Bound Left";
		cout << "Red Arrow  East Bound Left\n";
		cout << "Red Arrow  West Bound Left\n";
		cout << "Red Light  North Bound Through\n"; 
		cout << "Red Light  South Bound Through\n";
		cout << "Red Light  East Bound Through\n";
		cout << "Red Light  West Bound Through\n\n";
		sleep_until(system_clock::now() + 5s); // 

	/* Red arrows are optional. can pause on red, or go direcctly from yellow arrow to green through lights. This is optional. 
		
		cout << "Red Arrow  North Bound Left\n";
		cout << "Red Arrow  South Bound Left\n";
		cout << "Red Arrow  East Bound Left\n";
		cout << "Red Arrow  West Bound Left\n";
		cout << "Red Light  North Bound Through\n"; // all lights red
		cout << "Red Light  South Bound Through\n";
		cout << "Red Light  East Bound Through\n";
		cout << "Red Light  West Bound Through\n\n";
	sleep_until(system_clock::now() + 2s); // Time delay on all red before next set of Green lights
	*/

	northSouth:  // use for a goto statement can jump to here if there is a emergency vehicle. 
		
		cout << "Red Arrow  North Bound Left\n";
		cout << "Red Arrow  South Bound Left\n";
		cout << "Red Arrow  East Bound Left\n";
		cout << "Red Arrow  West Bound Left\n";
		cout << "Green Light  North Bound Through\n"; // Start loop with green for North South Directions
		cout << "Green Light  South Bound Through\n";
		cout << "Red Light  East Bound Through\n"; // Cross street stays red
		cout << "Red Light  West Bound Through\n\n";
	sleep_until(system_clock::now() + 5s);  // Time green North/South
		
		
		cout << "Red Arrow  North Bound Left\n";
		cout << "Red Arrow  South Bound Left\n";
		cout << "Red Arrow  East Bound Left\n";
		cout << "Red Arrow  West Bound Left\n";
		cout << "Yellow Light  North Bound Through\n";
		cout << "Yellow Light  South Bound Through\n";
		cout << "Red Light  East Bound Through\n"; // cross street stays red
		cout << "Red Light  West Bound Through\n\n";
	sleep_until(system_clock::now() + 5s); // Time for yellow on North/South
		
		cout << "Red Arrow  North Bound Left\n"; // all lights red
		cout << "Red Arrow  South Bound Left\n";
		cout << "Red Arrow  East Bound Left\n";
		cout << "Red Arrow  West Bound Left\n";
		cout << "Red Light  North Bound Through\n"; 
		cout << "Red Light  South Bound Through\n";
		cout << "Red Light  East Bound Through\n"; 
		cout << "Red Light  West Bound Through\n\n";
	sleep_until(system_clock::now() + 2s); // Time All Red
		
eastWest:  // Use for a goto statement

		cout << "Red Arrow  North Bound Left\n"; // Green Left Turn East/West
		cout << "Red Arrow  South Bound Left\n";
		cout << "Green Arrow  East Bound Left\n";
		cout << "Green Arrow  West Bound Left\n";
		cout << "Red Light  North Bound Through\n";
		cout << "Red Light  South Bound Through\n";
		cout << "Red Light  East Bound Through\n";
		cout << "Red Light  West Bound Through\n\n";
	sleep_until(system_clock::now() + 5s); //

		cout << "Red Arrow  North Bound Left\n"; // Yellow Left Turn East/West
		cout << "Red Arrow  South Bound Left\n";
		cout << "Yellow Arrow  East Bound Left\n";
		cout << "Yellow Arrow  West Bound Left\n";
		cout << "Red Light  North Bound Through\n";
		cout << "Red Light  South Bound Through\n";
		cout << "Red Light  East Bound Through\n";
		cout << "Red Light  West Bound Through\n\n";
	sleep_until(system_clock::now() + 3s); // Time delay on yellow arrows

	// Same as north south, do we want to display red left arrows. 
	/*
		cout << "Red Arrow  North Bound Left\n"; // All Red Safty pause
		cout << "Red Arrow  South Bound Left\n";
		cout << "Red Arrow  East Bound Left\n";
		cout << "Red Arrow  West Bound Left\n";
		cout << "Red Light  North Bound Through\n";
		cout << "Red Light  South Bound Through\n";
		cout << "Red Light  East Bound Through\n";
		cout << "Red Light  West Bound Through\n\n";
	sleep_until(system_clock::now() + 2s); // Time Delay on all red safty pause
	*/
	
		cout << "Red Arrow  North Bound Left\n";
		cout << "Red Arrow  South Bound Left\n";
		cout << "Red Arrow  East Bound Left\n";
		cout << "Red Arrow  West Bound Left\n";
		cout << "Green Light  East Bound Through\n";
		cout << "Green Light  West Bound Through\n";
		cout << "Red Light  North Bound Through\n"; 
		cout << "Red Light  South Bound Through\n\n";
	sleep_until(system_clock::now() + 5s); // Time Green East/West

		cout << "Red Arrow  North Bound Left\n";
		cout << "Red Arrow  South Bound Left\n";
		cout << "Red Arrow  East Bound Left\n";
		cout << "Red Arrow  West Bound Left\n";
		cout << "Yellow Light  East Bound Through\n";
		cout << "Yellow Light  West Bound Through\n";
		cout << "Red Light  North Bound Through\n";
		cout << "Red Light  South Bound Through\n\n";
	sleep_until(system_clock::now() + 5s); // Time Yellow East/West

		cout << "Red Arrow  North Bound Left\n";
		cout << "Red Arrow  South Bound Left\n";
		cout << "Red Arrow  East Bound Left\n";
		cout << "Red Arrow  West Bound Left\n";
		cout << "Red Light  North Bound Through\n"; // all lights red
		cout << "Red Light  South Bound Through\n";
		cout << "Red Light  East Bound Through\n";
		cout << "Red Light  West Bound Through\n\n";
	sleep_until(system_clock::now() + 2s); // Time All Red

	}

emergencyVehicle:
	cout << "Red Arrow  North Bound Left\n";
	cout << "Red Arrow  South Bound Left\n";
	cout << "Red Arrow  East Bound Left\n";
	cout << "Red Arrow  West Bound Left\n";
	cout << "Red Light  North Bound Through\n"; // all lights red
	cout << "Red Light  South Bound Through\n";
	cout << "Red Light  East Bound Through\n";
	cout << "Red Light  West Bound Through\n\n";
	sleep_until(system_clock::now() + 10s); // Time All Red for emergency vehicle
	goto northSouth; // after emergency vehicle lights reset to beginning of light cycle. I see issue with this when trying to sync up multiple lights accross the city.


	system("pause");
	return 0;
}

// stop light code for sensor light, changes depending on number of vehicles. timers may need to be adjusted. 
// The light is for heavier traffic, as far as this could go. could do a stay green in the main direction and then switch fast for any car that approches. options that need to decided by class. 
/*
#include<iostream>
#include<ctime>
#include<thread>
#include<chrono>

using namespace std;

int main()
{
	int num_vehicles;
	int t;
	int max_time;
	int timer;                //I need to initialize timer in such a way and as such an entity that its keeps resizing itself .
	int add;

	while (1)
	{
		cout << "Enter the number of vehicles at the red light: ";  // think can use a getter to auto fill this info
		cin >> num_vehicles;
		cout << "\n";

		if (num_vehicles<30) 
			timer = num_vehicles;

		else if (num_vehicles >= 30)
		{
			timer = num_vehicles / 2;
			add = num_vehicles / 2;
		}

		cout << "The red light turns green for " << num_vehicles << " number of time steps.\n\n";

		if (t = 0)
		{
			cout << "Total waiting time for first car at current red light since entry into system: 0";
		}

		else if (t = 1)
		{
			cout << "Total waiting time for first car at current red light since entry into system: "; cout << "\n\n"; //timer for first green light
		}

		else if (t = 2)
		{
			cout << "Total waiting time for first car at current red light since entry into system: "; cout << "\n\n"; //timer for first green light+second green light
		}

		else
		{
			cout << "Total waiting time for first car at current red light since entry into system: "; cout << "\n\n"; //sum of timers for last three green lights
		}

		t++;

		cout << "Moving to the next traffic light in clockwise order.\n\n\n\n";
	}
	system ("pause");
	return 0; */