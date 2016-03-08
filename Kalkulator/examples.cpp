#include "examples.h"

double sum( double a, double b )
{
	return a + b;
}

double square_root( double a )
{
	return sqrt(a);
}

void examples()
{
	double a, b, result;
	cout << "I can calculated any sum. Check me ;)" << endl;
	cout << "Give me two numbers:" << endl;
	
	cin >> a >> b;
	result = sum( a, b );
	cout << "Your sum is: " << result << endl;
	
	cout << "Now I do something worse. I calculate square root. Do you believe me?" << endl;
	cout << "Give me one number:" << endl;
	cin >> a;
	result = square_root(a);
	cout << "Square root is: " << result << endl;
}

/*
int main()
{
	examples();	

	return 0;
}
*/
