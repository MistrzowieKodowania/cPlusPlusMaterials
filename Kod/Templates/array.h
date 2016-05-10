#include <iostream>
#include <string>
#include <cstdlib>
#include "outofrange.h"
using namespace std;

// szablon wymaga jednego pliku
// dziwne konstrukcje: "template<class ...>"
// powtórzone przy metodzie (jej implementacji)
template<class Type, int size>
class Array
{
	public:
		Array();
		~Array();
		
		// operator indeksowania
		Type operator[](int i);

	private:
		Type* array;
};

template<class Type, int size> Array<Type, size>::Array()
{
	array = new Type[size];
	for ( int i = 0; i < size; i++ )
	{
		array[i] = i + (Type)1.5;
	}
}

template<class Type, int size> Array<Type, size>::~Array()
{
	delete [] array;
}
		
template<class Type, int size> Type Array<Type, size>::operator[](int i)
{
	if ( i < size && i >= 0)
		return array[i];
	else
		throw OutOfRange(i);
}
