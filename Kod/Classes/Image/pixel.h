#include <iostream>
using namespace std;
typedef enum { AVERAGE, LIGHTNESS, LUMINOSITY } grayscale_algorithm;

class Pixel
{
	public:
		
		Pixel() {};
		Pixel( int red, int green, int blue);
		~Pixel();
		
		void set_pixel(int red, int green, int blue);
		int get_red();
		int get_green();
		int get_blue();
	
		bool operator==( const Pixel& pixel );
		void to_gray(grayscale_algorithm algorithm);
		void print();
	
	protected:
		void to_gray_average();
		void to_gray_lightness();
		void to_gray_luminosity();
	
	private:
				
		int red;
		int green;
		int blue;
};
