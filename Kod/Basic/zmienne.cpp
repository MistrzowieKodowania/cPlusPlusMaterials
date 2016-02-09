#include <iostream>  // plik nag³ówkowy zawieraj¹cy funkcjê cout
using namespace std; // przestrzeñ nazw biblioteki standardowej

/* Program prezentuj¹cy zmienne w C++ */

int main()
{
	bool l = true;    // 1 bajt
	char s = 'a';     // 1 bajt
	short a = 128;    // minimum 2 bajty
	int b = 123456;   // minimum 2 bajty
	long c = 123456L; // minimum 4 bajty
		
	float f = 1.23;         // minimum 4 bajty
	double e = 1.23456789;  // minimum 8 bajtów

	cout << "Bool: " << l << " Rozmiar: " << sizeof(bool) << endl;
	cout << "Char: " << s << " Rozmiar: " << sizeof(char) << endl;
	cout << "Short: " << a << " Rozmiar: " << sizeof(short) << endl;
	cout << "Integer: " << b << " Rozmiar: " << sizeof(int) << endl;
	cout << "Long: " << c << " Rozmiar: " << sizeof(long) << endl;
	cout << "Float: " << f << " Rozmiar: " << sizeof(float) << endl;
	cout << "Double: " << e << " Rozmiar: " << sizeof(double) << endl;

	// dodatkowo przed nazw¹ typu zmiennej mo¿emy dopisaæ: "unsigned" - dla liczb dodatnich
	// signed - dla liczb ujemnych tzw. ze znakiem. domyœlnie zmienne s¹ "signed"
	// w przypadku gdyby do zmiennej unsigned przypisano liczbê ujemn¹
	// wartoœæ takiej zmiennej bêdzie nieprawid³owa, ale kompilator nie wska¿e b³êdu!

	/* rozmiar zmiennej jest istotny:
	   - przy tworzeniu programów na urz¹dzenia takie jak mikrokontrolery np. ATmega64 z 64 kB pamiêci
	     wbudowanej.
	   - w kryptografii czêsto musimy pos³ugiwaæ siê wielkimi liczbami: du¿o wiêkszymi ni¿ zakres long
	   - musimy o tym pamiêtaæ aby zapobiegaæ tzw. przepe³nieniu (overflow) - jest to czêsto jeden z powodów
	     dziwnego dzia³ania programu
	*/ 

	return 0;
}
