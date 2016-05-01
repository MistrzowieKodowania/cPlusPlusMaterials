#include "bike.h"
#include "car.h"

int main(int argc, char** argv) 
{
	Car car = Car();
	Bike bike = Bike();
	
	cout << "Wheels: " << car.get_wheels_number() << endl;
	cout << "Wheels: " << bike.get_wheels_number() << endl;
}
