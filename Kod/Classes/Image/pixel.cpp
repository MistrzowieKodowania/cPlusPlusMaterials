#include "pixel.h"

// Pixel:: - ta "funkcja" nale¿y do klasy Pixel (jest to sk³adnia konieczna w przypadku metod
// tutaj równie¿ jedna z mo¿liwoœci przypisywania wartoœci do zmiennych w konstruktorze
// po metodzie czyli po tym: Pixel::Pixel( int red, int green, int blue)
// mamy:
// : red(red), green(green), blue(blue)
// jest to przypisanie wartoœci do zmiennych prywatnych: red, green, blue
// mo¿na zamiast tego napisaæ pomiêdzy klamerkami
// red = red;
// green = green;
// albo
// this->red = red
// this->green = green
// wszystko jest równowa¿ne
Pixel::Pixel( int red, int green, int blue) : red(red), green(green), blue(blue)
{	
}

// destruktor piksela (nic nie musi robiæ)
// destruktor niszczy obiekt - zwalnia pamiêæ
// jeœli przydzieliliœmy pamiêæ dynamicznie np. utworzyliœmy dynamiczn¹ tablicê
// w konstruktorze to destruktor powinien j¹ zwolniæ!
// w przeciwnym przypadku bêdziemy mieli wyciek pamiêci
Pixel::~Pixel()
{
	
}
		
// metoda klasy Pixel
void Pixel::set_pixel(int red, int green, int blue)
{
	// this (wskaŸnik), a poniewa¿ wskaŸnik to u¿ywamy ->
	this->red = red;      // zmieniaj¹c this->red zmieniamy prywatn¹ zmienn¹ red (patch pixel.h)
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
	
// operator porównania
// const Pixel& pixel - referencja (nie kopiujemy obiektu pixel do nowego obszaru w pamiêci
// dziêki temu jest to szybsze! i nie musimy kopiowaæ np. tablicy dynamicznej
bool Pixel::operator==( const Pixel& pixel )
{
	return this->blue == pixel.blue && this->red == pixel.red &&
	       this->green == pixel.green; // a to zwyk³e porównanie (operator porównania ma za zadanie porównaæ dwa obiekty
	                                   // tak jak porównujemy liczby
	                                   // dziêki implementacji tego operatora mo¿emy napisaæ:
	                                   // Pixel pixel_a = Pixel(3,3,3);
	                                   // Pixel pixel_b = Pixel(3,3,3);
	                                   // if ( pixel_a == pixel_b) 
	                                   // ...
}

void Pixel::to_gray(grayscale_algorithm algorithm)
{
	switch( algorithm )
	{
		case AVERAGE:
			to_gray_average(); // wywo³anie metody chronionej (niepublicznej)
			                   // tutaj mo¿emy, bo to wnêtrznoœci klasy Pixel (a nie œwiat zewnêtrzny np. funkcja main)
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
	// to samo co:
	// int average = ( this->red + this->green + this->blue ) / 3;
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


