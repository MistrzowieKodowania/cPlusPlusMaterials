#include "image.h"

Image::Image( string filepath )
{
	image = NULL;
	header = NULL;
	read_image(filepath);
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

void Image::print(string filepath)
{
	fstream writer;
	writer.open(filepath.c_str(), ios::out | ios::binary);	
	writer.write(header, headersize);

	for ( int i = 0; i < this->height; i++ )
	{
		for ( int j = 0; j < this->width; j++ )
		{
			unsigned char red = image[i][j].get_red();
			unsigned char green = image[i][j].get_green();
			unsigned char blue = image[i][j].get_blue();
			
			writer << red << green << blue;
		}
	}
	writer.close();
}

// http://www.dragonwins.com/domains/getteched/bmp/bmpfileformat.htm
// http://www.fileformat.info/format/bmp/egff.htm
// https://en.wikipedia.org/wiki/BMP_file_format
void Image::read_image(string filepath)
{
	ImageReader* imagereader = new ImageReader(filepath);
	width = imagereader->get_width();
	height = imagereader->get_height();
	headersize = imagereader->get_header_size();
	header = new char[headersize];
	for ( int i = 0; i < headersize; i++ )
	{
		header[i] = imagereader->get_header_byte(i);
	}
	
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
