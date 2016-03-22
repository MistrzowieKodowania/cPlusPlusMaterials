#include "image.h" // do³¹czam bibliotekê i klasê image

// steganografia (agent wywiadu)
// tekst do ukrycia:
//To jest tajemnica
//T -> to jest bajt -> 0xAB -> 1010 1011
//o
// 
//j
//..

//kolor to te¿ bajt
// je¿eli kolor = 0xFF (bia³y)
// to ukrywaj¹c 0 (bit) dostaniemy 0xFE
// z 1111 1111 zrobi nam siê
// 1111 1110


int main()
{	
	Image* image = new Image("lena.bmp"); // utworzenie obiektu obrazu z leny
	image->to_gray(AVERAGE); // zamiana obrazka na monochromatyczny
	image->print("lena-gray.bmp");  // zapisanie na dysku
	
	delete image;
	return 0;
}
