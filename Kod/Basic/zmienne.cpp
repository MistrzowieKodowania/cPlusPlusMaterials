#include <iostream>
using namespace std;

/* Program przedstawiający sposób tworzenia zmiennych w C++ */

int main()
{
	short a = 128;
	int b = 123456; 
	long c = 123456L;
	
	// sizeof(int)
	
	float f = 1.23;
	double e = 1.23456789;

	cout << "Short: " << a <<" Integer: ";
	cout << b << " Long: " << c << " Float: " << f << " Double: " << e;
	cout << endl;

	return 0;
}
