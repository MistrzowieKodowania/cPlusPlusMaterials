#include <iostream>
using namespace std;

enum { EXIT, HORRIBLE, BAD, GOOD, EXCELLENT };

int main()
{
	int decision;
	bool exit = false;
	
	// while loop
	while (!exit)
	{
		cout << "What do you think about programming?" << endl;
		cout << "Choose one option: 1: horrible, 2: bad, 3: good, 4: excellent, 0: EXIT" << endl;
		cin >> decision;
		switch( decision )
		{
			case EXIT:
				exit = true; break;
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
	}
	
	system("pause");
	
	// do while
	int a = 10;
	cout << "Counting: ";
	do
	{
		cout << a << " ";
		a--;
	} while ( a > 0 );
	cout << endl;

	system("pause");

	// for
	cout << "Steps: ";
	for ( int step = 0; step < 10; step++ )
	{
		cout << step << " ";
	}
	cout << endl;
	
	return 0;
}
