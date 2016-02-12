#include "functions.h"

int sum_example()
{
	int* sequence;
	int sequence_size;
	int sum = 0;
	cout << "How many numbers you want to sum?" << endl;
	cin >> sequence_size;
	
	sequence = new int[sequence_size];
	cout << "Give me " << sequence_size << " integers" << endl;
	for ( int i = 0; i < sequence_size; ++i )
	{
		cin >> sequence[i];
	}
	cout << "Thanks." << endl;
	int i = 0;
	while( i < sequence_size)
	{
		int element = sequence[i++];  // what if ++i?
		cout << "Element " << element << endl;
		system("pause");
		sum += element;
	}
	delete [] sequence;
	
	return sum;
}

int main()
{
	string menu[MENU_ELEMENTS_NUMBER] = { "start", "readfile", "quit", "help" };
	string submenu[] = { "readimage", "readtext"};
	int submenu_elements = sizeof(submenu)/sizeof(submenu[0]);
	
	int sum = sum_example();
	cout << "Your sum is: " << sum << endl;

	system("pause");

	print_menu( menu, MENU_ELEMENTS_NUMBER, submenu, submenu_elements );

	return 0;
}


void print_menu( string menu[], int menu_size, string* submenu, int submenu_size)
{
	for ( int i = 0; i < menu_size; i++ )
	{
		cout << menu[i] << endl;
		if ( menu[i] == "readfile" )
		{
			for ( int j = 0; j < submenu_size; j++ )
			{
				cout << "\t" << *(submenu + j) << endl;
				cout << "\t" << submenu[j] << endl;
			}
		}
	}
}

