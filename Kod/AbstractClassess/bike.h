#include "vehicle.h"

class Bike : public Vehicle
{
	public:
		Bike();
		~Bike();
		int get_wheels_number();
};
