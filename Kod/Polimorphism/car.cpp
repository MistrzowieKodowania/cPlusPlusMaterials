#include "car.h"

Car::Car() : Vehicle(4)
{
	cout << "Car constructed" << endl;
}

int Car::get_wheels_number()
{
	cout << "Car ----- " << endl;
	return Vehicle::get_wheels_number();
}

Car::~Car()
{
	cout << "Car destructed" << endl;
}
