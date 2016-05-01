#ifndef _VEHICLE_H // dziêki temu (ifndef i define) mo¿emy korzystaæ z tego
#define _VEHICLE_H // pliku nag³ówkowego wielokrotnie bez obawy ¿e w kodzie
                   // zostanie on wstawiony wielokrotnie (co da b³¹d: redefinition of class ...)

#include <iostream>
using namespace std;

// klasa bazowa dla wszystkich pojazdów
class Vehicle
{
	public:
		Vehicle( int wheels ); // konstruktor
		~Vehicle(); // destruktor wywo³ywany jak obiekt ulega zniszczeniu
		int get_wheels_number(); // zwróæ liczbê kó³ pojazdu
		
	private:
		int wheels; // liczba kó³
};

#endif /* _VEHICLE_H */
