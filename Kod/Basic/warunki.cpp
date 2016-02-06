
#include <iostream>
enum { HORRIBLE=1, BAD, GOOD, EXCELLENT };
using namespace std;

int main()
{
	int value;
	int decision;
	
	// 1
	cout << "Give me an integer less than 10 please..." << endl;
	cin >> value;
	if ( value < 10 )
	{
		cout << "Correct!" << endl;
	}
	else
	{
		cout << "Incorrect. Too high!" << endl;
	}
	
	// 2
	cout << "Give me an integer between 10 and 20 please..." << endl;
	cin >> value;
	if ( value < 10 )
	{
		cout << "Incorrect. Too low!" << endl;
	}
	else if ( value > 10 && value < 20 )
	{
		cout << "Correct!" << endl;
	}
	else
	{
		cout << "Incorrect. Too high!" << endl;
	}
	
	// 3
	cout << "Give me an integer lower than 10 or higher than 20 please..." << endl;
	cin >> value;
	value < 10 || value > 20 ? cout << "Correct." << endl : cout << "Incorrect!" << endl;
	
	// 4
	cout << "What do you think about programming?" << endl;
	cout << "Choose one option: 1: horrible, 2: bad, 3: good, 4: excellent" << endl;
	cin >> decision;
	switch( decision )
	{
		case HORRIBLE:
			cout << "Go and play games." << endl; break;
		case BAD:
			cout << "Try Scratch." << endl; break;
		case GOOD:
			cout << "Look at C++ my padawan" << endl; break;
		case EXCELLENT:
			cout << "Thank you my master" << endl; break;
		default:
			cout << "Try one more time" << endl; break;
	}
	
	return 0;
}
