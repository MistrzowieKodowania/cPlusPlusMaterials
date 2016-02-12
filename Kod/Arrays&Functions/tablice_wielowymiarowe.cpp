#define SQUARE_SIZE 4

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int math_square[SQUARE_SIZE][SQUARE_SIZE];
	
	for ( int i = 0; i < SQUARE_SIZE; i++ )
	{
		for ( int j = 0; j < SQUARE_SIZE; j++ )
		{
			math_square[i][j] = (i+1)*(j+1);
		}
	}
	
	cout << "Your array:" << endl;
	for ( int i = 0; i < SQUARE_SIZE; i++ )
	{
		for ( int j = 0; j < SQUARE_SIZE; j++ )
		{
			int width = SQUARE_SIZE*SQUARE_SIZE / 10 + 1; // number of digits
			cout << setfill(' ') << setw(width + 1) << math_square[i][j]; // +1 : white space
		}
		cout << endl;
	}
	
	system("pause");
	
	int** array;
	array = new int*[SQUARE_SIZE];
	for ( int i = 0; i < SQUARE_SIZE; i++ )
	{
		array[i] = new int[SQUARE_SIZE];
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
