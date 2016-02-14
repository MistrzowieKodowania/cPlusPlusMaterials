#include <iostream>
using namespace std;
			
int main()
{
	// 1 solution
	int decision = 0;
	cout << "Give me an integer:" << endl; 
	while ( ! (cin >> decision) || ! cin.good() )
	{
		cout << "Not integer. Try one more time" << endl;
		cin.clear();
		cin.ignore();
	}
	
	cout << "Your decision: " << decision;
	
	return 0;
}
