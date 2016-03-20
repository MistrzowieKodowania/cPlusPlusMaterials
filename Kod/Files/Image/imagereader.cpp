#include "ImageReader.h"

ImageReader::ImageReader(string filepath)
{
	data = NULL;
	read_image(filepath);
}

ImageReader::~ImageReader()
{
	if ( data )
	{
		delete [] data;
	}
}

int ImageReader::get_header_size()
{
	return BMP_HEADER_SIZE + BMP_IMAGE_HEADER_SIZE;
}

int ImageReader::get_data_size()
{
	if ( data )
	{
		return this->width * this->height * COLORSIZE;
	}
	else
		return 0;
}

int ImageReader::get_width()
{
	return this->width;
}

int ImageReader::get_height()
{
	return this->height;
}

char ImageReader::get_header_byte(int index)
{
	if ( index < get_header_size() )
		return this->header[index];
	else
		return 0;
}

unsigned char ImageReader::get_data_byte(int index)
{
	if ( index < get_data_size() )
		return this->data[index];
	else
		return 0;	
}


unsigned char ImageReader::get_data_byte(int row, int col, ImageColor color)
{
	if ( row < get_height() && col < get_width() )
	{
		return this->data[(row*get_width() + col)*COLORSIZE + color];
	}	
	else
		return 0;	
}

int ImageReader::hex2int(char* array, int size)
{
	unsigned int value = 0;
	for ( int i = 0; i < size; i++ )
	{
		unsigned int byte = (unsigned int)array[i] << BYTE_BITS*i;
		value += byte;
	}
	return value;
}

// http://www.dragonwins.com/domains/getteched/bmp/bmpfileformat.htm
// http://www.fileformat.info/format/bmp/egff.htm
// https://en.wikipedia.org/wiki/BMP_file_format
void ImageReader::read_image(string filepath)
{
	fstream reader;
	reader.open(filepath.c_str(), ios::in | ios::binary);
	if (reader.is_open())
	{
		// Wczytanie nag³ówka pliku - 14 bajtów (nic z tym nie trzeba robiæ)		
		reader.read( this->header, BMP_HEADER_SIZE);
		
		// Wczytanie nag³ówka obrazu (tutaj bêdzie rozmiar)
		reader.read( &this->header[BMP_HEADER_SIZE], BMP_IMAGE_HEADER_SIZE );
		
		this->width = hex2int( &this->header[BMP_HEADER_SIZE + BMP_WIDTH_OFFSET], BMP_WIDTH_SIZE);
		this->height = hex2int( &this->header[BMP_HEADER_SIZE + BMP_HEIGHT_OFFSET], BMP_HEIGHT_SIZE);
		this->data = new unsigned char[this->width*this->height*COLORSIZE];
		
		char byte;
		int counter = 0;
		while( reader.get(byte) )
		{
			unsigned char color = (unsigned char)byte;			
			this->data[counter++] = color;
		}
	}
	else
	{
		cout << "Error! No image" << endl;
	}
	
	reader.close();
}
