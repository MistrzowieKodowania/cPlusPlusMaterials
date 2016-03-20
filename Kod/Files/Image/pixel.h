#include <iostream>
using namespace std;
typedef enum { AVERAGE, LIGHTNESS, LUMINOSITY } grayscale_algorithm; // definicja typu, mo¿e zmieniæ nazwê typu na inn¹
/* typedef int liczba_calkowita // zamiast int u¿ywamy liczba_calkowita */



class Pixel // definicja klasy, klasa nazywa siê Pixel
            // stworzyliœmy typ (a typ w C++ to np. char)
{
	public: // wszystko co jest poni¿ej bêdzie publiczne. wszyscy bêd¹ mogli tego u¿ywæ
		    // s¹ widoczne w innych funkcjach i obiektach
		// char red; // by³aby widoczna na zewn¹trz
		  
		    
		Pixel() {}; // konstruktor (nazywa siê tak samo jak klasa)
		Pixel( unsigned char red, unsigned char green, unsigned char blue); // konstruktor
		~Pixel(); // destruktor, nazywa siê tak jak klasa ale ma znak tyldy na pocz¹tku
		
		void set_pixel(unsigned char red, unsigned char green, unsigned char blue); // metoda ustawia piksel na wybrane wartoœci RGB
		void set_red(unsigned char red); // metoda: ustawia kolor czerwony R
		void set_green(unsigned char green); // ustawia kolor zielony czyli G
		void set_blue(unsigned char blue); // ustawia kolor niebieski B
		unsigned char get_red(); // metoda: zwraca kolor czerwony R
		unsigned char get_green(); // zwraca kolor zielony czyli G
		unsigned char get_blue(); // zwraca kolor niebieski B
	
		bool operator==( const Pixel& pixel ); // operator porównania (specjalny)
		                                       // const - sta³a, & - referencja (coœ jk wskaŸnik)
		void to_gray(grayscale_algorithm algorithm); // zamiana na skalê szaroœci, monochromatyczny
		                                             // dziêki temu, ¿e wczeœniej u¿yliœmy typedef mo¿emy 
													 // tutaj u¿yæ grayscale_algorithm maj¹c na myœli ten enum
		void print(); // wydrukowanie na ekranie, ale nie obrazka tylko tablicy
	
	protected: // metody chronione
	           // na zajêciach nr. 6 wiêcej
	           // metody chronione s¹ niepubliczne
		void to_gray_average();    // uœrednianie (R + G + B) / 3 = szary piksel
		void to_gray_lightness();  // inny algorytm
		void to_gray_luminosity(); // inny algorytm
	
	private: // rzeczy prywatne
	         // nikt nie ma dostêpu oprócz metod, które s¹ w tej klasie
			 	
		unsigned char red;
		unsigned char green;
		unsigned char blue;
};

// struktra patrz ni¿ej
struct Pixel_struct
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

/*
// wszystko co jest wewn¹trz struktury jest publiczne! coœ podobnego do klasy
// pochodzi z C
// u¿ywamy po to aby skorzystaæ ze zmiennych i jednoczeœnie je zgrupowaæ
// zgrupowaæ, ale nie ograniczyæ dostêpu
typedef struct Pixel_struct
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
} Pixel_struct;

Pixel_struct nazwa;
nazwa.red
*/
