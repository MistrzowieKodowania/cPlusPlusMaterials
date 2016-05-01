#include "bike.h"

Bike::Bike() : Vehicle(2)
{
	cout << "Bike constructed" << endl;
}

int Bike::get_wheels_number()
{
	cout << "Bike" << endl;
	return Vehicle::get_wheels_number();
}

Bike::~Bike()
{
	cout << "Bike destructed" << endl;
}
