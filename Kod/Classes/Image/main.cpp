#include "image.h"

int main()
{
	Image* image = new Image(4, 4);
	
	cout << "Before to gray:" << endl;
	image->print();
	image->to_gray(AVERAGE);
	
	cout << endl << "After to gray:" << endl;
	image->print();
	
	delete image;
	return 0;
}
