#ifndef IMAGE_READER
#define IMAGE_READER

#include <fstream> // wczytywanie pliku
#include <string>
#include <iostream>
using namespace std;

#define BMP_HEADER_SIZE 14
#define BMP_IMAGE_HEADER_SIZE 40
#define BMP_WIDTH_OFFSET 4
#define BMP_WIDTH_SIZE 4
#define BMP_HEIGHT_OFFSET 4
#define BMP_HEIGHT_SIZE 4
#define BYTE_BITS 8

class ImageReader
{
	public:
		ImageReader(string filepath);
		~ImageReader();
		typedef enum { RED, GREEN, BLUE, COLORSIZE } ImageColor;
		
		int get_header_size();
		int get_data_size();
		int get_width();
		int get_height();
		char get_header_byte(int index);
		unsigned char get_data_byte(int index);
		unsigned char get_data_byte(int row, int col, ImageColor color);
		
	protected:	
		int hex2int(char* array, int size);
		void read_image(string filepath);
		
	private:
		
		int height;
		int width;
		char header[BMP_HEADER_SIZE + BMP_IMAGE_HEADER_SIZE];
		unsigned char* data;
};

#endif
