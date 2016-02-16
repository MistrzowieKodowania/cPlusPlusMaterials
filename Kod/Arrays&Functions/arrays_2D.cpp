#define SQUARE_SIZE 4

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int math_square[SQUARE_SIZE][SQUARE_SIZE]; //tablica dwuwymiarowa statyczna
	
	for ( int i = 0; i < SQUARE_SIZE; i++ )
	{
		for ( int j = 0; j < SQUARE_SIZE; j++ )
		{
			math_square[i][j] = (i+1)*(j+1); // uzupe³nianie tablicy
		}
	}
	
	cout << "Your array:" << endl;
	for ( int i = 0; i < SQUARE_SIZE; i++ )
	{
		for ( int j = 0; j < SQUARE_SIZE; j++ )
		{
			int width = SQUARE_SIZE*SQUARE_SIZE / 10 + 1; // number of digits
			// setfill, setw (³adne formatowanie z biblioteki iomanip - poczytajcie ;) )
			cout << setfill(' ') << setw(width + 1) << math_square[i][j]; // +1 : white space
		}
		cout << endl;
	}
	
	system("pause");
	
	int** array; // wskaŸnik na dwa wymiary wiêc 2 gwiazdki, gdyby 3 wymiary by³yby 3 gwiazdki
	array = new int*[SQUARE_SIZE]; // tworzymy wiersze
	// tutaj dostaniemy coœ takiego (po powy¿szym new):
	// zobaczcie, ¿e jest tam "*" przy new int -> to bardzo wa¿ne
	// tworzymy w ten sposób adresy, ale nie ma tam jeszcze ¿adnych elementów
	// stan developerski mieszkania ;)
	// [0] -> ...... nic ......
	// [1] -> ...... nic ......
	// [2] -> ...... nic ......
	// [3] -> ...... nic ......
	for ( int i = 0; i < SQUARE_SIZE; i++ )
	{
		array[i] = new int[SQUARE_SIZE]; 
		// tutaj ju¿ tak:
		// [0] -> [0] [1] [2] ...
		// [1] -> [0] [1] [2] ...
		// [2] -> [0] [1] [2] ...
		// [3] -> [0] [1] [2] ...
		for ( int j = 0; j < SQUARE_SIZE; j++ )
		{
			array[i][j] = i+j;
		}
	}

	cout << "Your array:" << endl;
	for ( int i = 0; i < SQUARE_SIZE; i++ )
	{
		for ( int j = 0; j < SQUARE_SIZE; j++ )
		{
			int width = SQUARE_SIZE*SQUARE_SIZE / 10 + 1; // number of digits
			cout << setfill(' ') << setw(width + 1) << array[i][j]; // +1 : white space
		}
		cout << endl;
	}	
	
	return 0;
}
