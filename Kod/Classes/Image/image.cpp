#include "image.h"

Image::Image( int width, int height ) : width(width), height(height)
{
	image = new Pixel*[height]; // dynamiczna tablica pikseli
	for ( int i = 0; i < height; i++ )
	{
		image[i] = new Pixel[width]; // dynamiczna tablica pikseli
		for (int j = 0; j < width; j++) 
		{
			int red = rand() % 255; // rand() z cstdlib - po prostu losuje liczby
			int blue = rand() % 255; 
			int green = rand() % 255;
			
			image[i][j].set_pixel(red, green, blue); // na pikselu (image[i][j]) wywo³ujê metodê
		}
	}
}

Image::~Image() // destruktor usuwa jak nie jest potrzebny
{
	// usuwam tablicê
	for ( int i = 0; i < height; i++ )
	{
		delete [] image[i];
	}
	delete image;
}

void Image::to_gray(grayscale_algorithm algorithm)
{
	for ( int i = 0; i < height; i++ )
	{
		for ( int j = 0; j < width; j++ )
		{
			image[i][j].to_gray(algorithm); // wywo³anie na pikselu metody to_gray - czyli zamieniamy na szary
			                                // image[i][j] - element tablicy, który jest klasy pixel (tak jak liœæ na drzewie)
			                                // zamiast obliczaæ œredni¹, zmieniaæ wartoœci po prostu wywo³ujemy metodê
		}
	}
}

void Image::print()
{
	for ( int i = 0; i < height; i++ )
	{
		for ( int j = 0; j < width; j++ )
		{
			image[i][j].print(); // a tutaj wywo³ujemy metodê print dla piksela (w ten sposób wyœwietli nam siê
			                     // napis
			                     // r: ... g: ... b: ...
			                     // i nie musimy niczego dodatkowego pisaæ!
			cout << " ";
		}
		cout << endl;
	}
}
