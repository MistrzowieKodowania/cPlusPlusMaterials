#include "pixel.h"

Pixel::Pixel( int red, int green, int blue) : red(red), green(green), blue(blue)
{	
}

Pixel::~Pixel()
{
	
}
		
void Pixel::set_pixel(int red, int green, int blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}

int Pixel::get_red()
{
	return this->red;
}

int Pixel::get_green()
{
	return this->green;
}

int Pixel::get_blue()
{
	return this->blue;
}
	
bool Pixel::operator==( const Pixel& pixel )
{
	return this->blue == pixel.blue && this->red == pixel.red &&
	       this->green == pixel.green;
}

void Pixel::to_gray(grayscale_algorithm algorithm)
{
	switch( algorithm )
	{
		case AVERAGE:
			to_gray_average();
			break;
		case LIGHTNESS:
			to_gray_lightness();
			break;
			
		case LUMINOSITY:
			to_gray_luminosity();
			break;
			
		default:
			
			cout << "Unknown algorithm" <<  endl;
			break;
	}
}

void Pixel::print()
{
	cout << "r: " << red << " g: " << green << " b: " << blue << ";";
}
	
void Pixel::to_gray_average()
{
	int average = ( red + green + blue ) / 3;
	red = average;
	green = average;
	blue = average;
}

void Pixel::to_gray_lightness()
{
	
}

void Pixel::to_gray_luminosity()
{
	
}


