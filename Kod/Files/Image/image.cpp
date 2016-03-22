#include "image.h"

Image::Image( string filepath ) // konstruktor obiektu obrazka z pliku
{
	image = NULL;
	header = NULL;
	read_image(filepath); // wczytujê obrazek z pliku
}

Image::Image( int width, int height ) : width(width), height(height)
{
	header = NULL;
	image = new Pixel*[height]; // dynamiczna tablica pikseli
	for ( int i = 0; i < height; i++ )
	{
		image[i] = new Pixel[width]; // dynamiczna tablica pikseli
		for (int j = 0; j < width; j++) 
		{
			unsigned char red = rand() % 255; // rand() z cstdlib - po prostu losuje liczby
			unsigned char blue = rand() % 255; 
			unsigned char green = rand() % 255;
			
			image[i][j].set_pixel(red, green, blue); // na pikselu (image[i][j]) wywo³ujê metodê
		}
	}
}

Image::~Image() // destruktor usuwa jak nie jest potrzebny
{
	// usuwam tablicê
	if ( image )
	{
		for ( int i = 0; i < height; i++ )
		{
			delete [] image[i];
		}
		delete image;
	}
		
	// usuwam nag³ówek jeœli istnieje
	if ( header )
	{
		delete [] header;
	} 
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
	}
}

// zapis obrazka do pliku
void Image::print(string filepath)
{
	fstream writer; // utowrzenie obiektu pisz¹cego do pliku
	writer.open(filepath.c_str(), ios::out | ios::binary);	// w trybie binarnym (bo obrazek to plik binarny)
	writer.write(header, headersize); // zapisujê ca³y nag³ówek (niezmieniony)

	// zapisujê zmieniony obrazek (kolejne bajty - kolory z wierszy i kolumn)
	for ( int i = 0; i < this->height; i++ )
	{
		for ( int j = 0; j < this->width; j++ )
		{
			unsigned char red = image[i][j].get_red();
			unsigned char green = image[i][j].get_green();
			unsigned char blue = image[i][j].get_blue();
			
			writer << red << green << blue; // zapisywanie kolorów w kolejnoœci RGB
		}
	}
	writer.close();
}

// plik BMP sk³ada siê z nag³ówka (header) i kolorów
// w nag³ówku przechowywane s¹ informacje np. o rozmiarze obrazka
// ale nie tylko. Nag³ówek BMP ma sta³y rozmiar i standardow¹ strutkurê
// dziêki temu wiemy, ¿e na danej pozycji nag³ówka mamy zapisany rozmiar obrazka
// wiêcej o pliku BMP tutaj:
// http://www.dragonwins.com/domains/getteched/bmp/bmpfileformat.htm
// http://www.fileformat.info/format/bmp/egff.htm
// https://en.wikipedia.org/wiki/BMP_file_format
void Image::read_image(string filepath)
{
	// jak skorzystaæ z gotowego kodu wczytywania obrazka
	// ta linijka ni¿ej wczytuje obrazek
	ImageReader* imagereader = new ImageReader(filepath);
	
	// pozosta³e linijki to robi¹ to czego potrzebujemy
	// czyli g³ównie kopiuj¹ nag³ówek i kolory do odpowiednich miejsc
	// w obiekcie klasy Image
	width = imagereader->get_width();
	height = imagereader->get_height();
	headersize = imagereader->get_header_size();
	header = new char[headersize];
	
	// Skopiowanie nag³ówka (poniewa¿ nie chcemy nadpisywaæ oryginalnego obrazka)
	for ( int i = 0; i < headersize; i++ )
	{
		header[i] = imagereader->get_header_byte(i);
	}
	
	// Skopiwanie kolorów do obiektu klasy Pixel
	image = new Pixel*[height]; // dynamiczna tablica pikseli
	for ( int i = 0; i < height; i++ )
	{
		image[i] = new Pixel[width]; // dynamiczna tablica pikseli	
		for ( int j = 0; j < width; j++ )
		{
			image[i][j].set_red(imagereader->get_data_byte(i,j,ImageReader::RED));
			image[i][j].set_blue(imagereader->get_data_byte(i,j,ImageReader::BLUE));
			image[i][j].set_green(imagereader->get_data_byte(i,j,ImageReader::GREEN));
		}
	}
	
	delete imagereader;
}
