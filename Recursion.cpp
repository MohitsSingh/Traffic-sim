#include <iostream>
using namespace std;

char getNextLetter()
{
	char letter;
	cin >> letter;
	if (letter != 'q')
	{
		cout << getNextLetter();
	}
	return letter;
}


int main()
{
	cout << "Enter letters \n";
	cout << getNextLetter();


	cout << endl;
	system("pause");
	return 0;
}