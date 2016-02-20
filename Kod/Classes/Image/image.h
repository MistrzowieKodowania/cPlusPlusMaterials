#include "pixel.h"
#include <cstdlib>

class Image
{
	public:
		
		Image( int width, int height );
		~Image();
		
		void to_gray(grayscale_algorithm algorithm);
		void print();
	
	private:
		int width;
		int height;
		Pixel** image;
};
