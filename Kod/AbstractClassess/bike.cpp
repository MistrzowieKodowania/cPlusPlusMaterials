#include "bike.h"

Bike::Bike() : Vehicle(2)
{
	cout << "Bike constructed" << endl;
}

int Bike::get_wheels_number()
{
	cout << "Bike" << endl;
	return wheels;
}

Bike::~Bike()
{
	cout << "Bike destructed" << endl;
}
