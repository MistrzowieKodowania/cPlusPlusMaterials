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
		//virtual double prognoza_zysk_firmy() = 0;
		virtual int get_wheels_number() = 0; // zwróæ liczbê kó³ pojazdu
		                                 // dziêki u¿yciu virtual kompilator bêdzie
		                                // wiedzia³, ¿e powinien odnosiæ siê do klasy pochodnej
		                                // poniewa¿ ma "=0" jest klas¹ abstrakcyjn¹
		                                // i nie trzeba tej metody implementowaæ!
		                                // jest to wtedy interfejs - czyli coœ co 
		                                // pokazuje jak wygl¹da klasa
		                                // ale nie ma ¿adnych algorytmów
		                                // jak coœ dziedziczy interfejs w C++
		                                // oznacza to, ¿e dana klasa jest zgodna z tym
		                                // interfejsem - kompilator wymusza implementacjê
		                                // wszystkich czysto abstrakcyjnyc (=0) metod
		                                // w klasie pochodnej!
		                                // mo¿emy w ten sposób wymusiæ od zespo³u
		                                // programistów pewn¹ architekturê jak¹ zaprojektowaliœmy
		                                // ka¿dy programista jest pewny, ¿e jeœli
		                                // klasa dziedziczy po interfejsie, to prêdzej
		                                // czy póŸniej wszsystkie te metody bêd¹ zaimplementowane
		                                // i bêdzie móg³ z nich bezpiecznie korzystaæ!
		
	protected: // jeœli jest chronione to klasy pochodne maj¹ swobodny dostêp
	        // ale na zewn¹trz (np. w main) tego nie widaæ
		int wheels; // liczba kó³
};

#endif /* _VEHICLE_H */
