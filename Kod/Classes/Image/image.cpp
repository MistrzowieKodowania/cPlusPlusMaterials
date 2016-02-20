#include "image.h"

Image::Image( int width, int height ) : width(width), height(height)
{
	image = new Pixel*[height];
	for ( int i = 0; i < height; i++ )
	{
		image[i] = new Pixel[width];
		for (int j = 0; j < width; j++) 
		{
			int red = rand() % 255;
			int blue = rand() % 255;
			int green = rand() % 255;
			
			image[i][j].set_pixel(red, green, blue);	
		}
	}
}

Image::~Image()
{
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
			image[i][j].to_gray(algorithm);
		}
	}
}

void Image::print()
{
	for ( int i = 0; i < height; i++ )
	{
		for ( int j = 0; j < width; j++ )
		{
			image[i][j].print();
			cout << " ";
		}
		cout << endl;
	}
}
