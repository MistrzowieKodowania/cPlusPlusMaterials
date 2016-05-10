#include "bike.h"
#include "car.h"

#include <vector>

int main(int argc, char** argv) 
{
	Vehicle* car = new Car();  // obiekt pochodny umieszczany jest we wskaŸniku
	Vehicle* bike = new Bike(); // do obiektu bazowego - to jest polimorfizm
	Vehicle* car2 = new Car();  // obiekt pochodny umieszczany jest we wskaŸniku


	vector<Vehicle*> vehicles; // dziêki temu mo¿emy utworzyæ kolekcjê
	vehicles.push_back(car); // która bêdzie mog³a zawieraæ
	vehicles.push_back(bike); // obiekty klasy pochodnej (mimo, ¿e s¹ ró¿nego typu)
	                          // a ju¿ kompilator zadba o to aby
	                        // wywo³ano w³aœciw¹ metodê
	vehicles.push_back(car2); // która bêdzie mog³a zaw
	
	// dziêki polimorfizmowi mo¿emy napisaæ
	// program bardziej uniwersalny i krótszy
	// np.:
	// ka¿dy pojazd mo¿na uruchomiæ
	// ale ka¿dy pojazd uruchamiamy inaczej
	// rower - peda³uj¹c
	// samochód - przekrêcaj¹c kluczyk i naciskaj¹c peda³ gazu
	// jeœli mamy firmê, która parkuje pojazdy
	// i chcemy napisaæ program, który to zrobi
	// wystarczy, ¿e dodamy ka¿dy pojazd do wspólnej kolejki
	// a nastêpnie ka¿dy element kolejki obs³u¿ymy w ten sam
	// sposób :)
	// jest to esencja programowania obiektowego
	// tworzymy "ramê" i dedykowane algorytmy dla ka¿dego elementu
	// umieszczonego w ramie. Ramy nie zmieniamy. Jest to INTERFEJS.              
	                          
	for ( int i = 0; i < vehicles.size(); i++ )
	{
		int wheels = vehicles[i]->get_wheels_number(); // wyœwietl liczbê kó³ pojazdu
		delete vehicles[i]; // zwolnij pamiêæ - zniszcz obiekt
		cout << "Wheels: " << wheels << endl;
	}
}
