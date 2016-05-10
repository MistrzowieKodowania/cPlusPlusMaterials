#include "vehicle.h"

class Bike : public Vehicle // dziedziczenie, : public Vehicle
{
	public:
		Bike();
		~Bike();
		int get_wheels_number();
		
	// tego nie ma	
	//private: 
	//	int wheels;
};
