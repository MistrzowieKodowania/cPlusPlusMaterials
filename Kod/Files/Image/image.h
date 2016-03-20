#include "pixel.h" // do³¹czam pixel: w takich <> - biblioteki C++
                  // a w "" wszystkie inne
#include "imagereader.h"
#include <cstdlib> // biblioteka C++ podobnie jak iostream

class Image
{
	public:
	
		Image( string filepath ); // konstruktor wczytanie z pliku
		Image( int width, int height ); // konstruktor
		~Image(); // destruktor
		
		void to_gray(grayscale_algorithm algorithm); // zmienia obrazek ca³y na omonochromatyczny
		void print(); // drukowanie obrazka na ekranie
		void print(string filepath); // zapisanie obrazka na dysku
		
	protected:
		
		void read_image(string filepath);
			
	private:
			
		int width;
		int height;
		int headersize;
		char* header;
		Pixel** image; // obraz to dwuwymiarowa tablica pikseli (dwie ** wiêc dwuwymiarowa tablica)
};
