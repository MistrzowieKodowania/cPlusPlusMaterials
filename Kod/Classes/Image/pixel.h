#include <iostream>
using namespace std;
typedef enum { AVERAGE, LIGHTNESS, LUMINOSITY } grayscale_algorithm; // definicja typu, mo¿e zmieniæ nazwê typu na inn¹
/* typedef int liczba_calkowita // zamiast int u¿ywamy liczba_calkowita */



class Pixel // definicja klasy, klasa nazywa siê Pixel
            // stworzyliœmy typ (a typ w C++ to np. int)
{
	public: // wszystko co jest poni¿ej bêdzie publiczne. wszyscy bêd¹ mogli tego u¿ywæ
		    // s¹ widoczne w innych funkcjach i obiektach
		// int red; // by³aby widoczna na zewn¹trz
		  
		    
		Pixel() {}; // konstruktor (nazywa siê tak samo jak klasa)
		Pixel( int red, int green, int blue); // konstruktor
		~Pixel(); // destruktor, nazywa siê tak jak klasa ale ma znak tyldy na pocz¹tku
		
		void set_pixel(int red, int green, int blue); // metoda ustawia piksel na wybrane wartoœci RGB
		int get_red(); // metoda: zwraca kolor czerwony R
		int get_green(); // zwraca kolor zielony czyli G
		int get_blue(); // zwraca kolor niebieski B
	
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
			 	
		int red;
		int green;
		int blue;
};

// struktra patrz ni¿ej
struct Pixel_struct
{
	int red;
	int green;
	int blue;
};

/*
// wszystko co jest wewn¹trz struktury jest publiczne! coœ podobnego do klasy
// pochodzi z C
// u¿ywamy po to aby skorzystaæ ze zmiennych i jednoczeœnie je zgrupowaæ
// zgrupowaæ, ale nie ograniczyæ dostêpu
typedef struct Pixel_struct
{
	int red;
	int green;
	int blue;
} Pixel_struct;

Pixel_struct nazwa;
nazwa.red
*/
