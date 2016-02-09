#include <iostream>
using namespace std;

int main()
{
	int b = 10;
	cout << "One more time: ";
	
	/*
        przyk³ad kodu w którym œrednik ma znaczenie!
	while ( b > 0 );
	{
		cout << b << " ";
		b--;
	}
	*/	

	// tak naprawdê mamy:
	while ( true) {
		
	}
	
	// kod ni¿ej nigdy siê nie wykona
	{
		cout << b << " ";
		b--;
	}
	cout << endl;
}
