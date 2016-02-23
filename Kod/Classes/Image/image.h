#include "pixel.h" // do³¹czam pixel: w takich <> - biblioteki C++
                  // a w "" wszystkie inne
#include <cstdlib> // biblioteka C++ podobnie jak iostream

class Image
{
	public:
		
		Image( int width, int height ); // konstruktor
		~Image(); // destruktor
		
		void to_gray(grayscale_algorithm algorithm); // zmienia obrazek ca³y na omonochromatyczny
		void print(); // drukowanie obrazka na ekranie
	
	private:
		int width;
		int height;
		Pixel** image; // obraz to dwuwymiarowa tablica pikseli (dwie ** wiêc dwuwymiarowa tablica)
};
