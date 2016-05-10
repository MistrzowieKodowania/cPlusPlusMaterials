#include "vehicle.h"

class Bike : public Vehicle
{
	public:
		Bike();
		~Bike();
		int get_wheels_number();
	// czegoœ takiego ni¿ej nie musimy dodawaæ
	// poniewa¿ wheels jest "protected" w klasie bazowej
	// dziêki temu klasa pochodna wie o istnieniu wheels i mo¿e z tego korzystaæ
	//private:
	//	int wheels;
};
