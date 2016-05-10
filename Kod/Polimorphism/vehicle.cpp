#include "vehicle.h"

Vehicle::Vehicle( int wheels ) : wheels(wheels) // konstruktor z list¹ inicjalizacyjn¹
{
	cout << "Vehicle constructed" << endl;
}

Vehicle::~Vehicle()
{
	cout << "Vehicle destructed" << endl;
}
