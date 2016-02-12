#define MENU_ELEMENTS_NUMBER 4

#include <iostream>
#include <string>

using namespace std;


int main()
{
	string menu[MENU_ELEMENTS_NUMBER] = { "start", "readfile", "quit", "help" };
	string submenu[] = { "readimage", "readtext"};
	
	for ( int i = 0; i < MENU_ELEMENTS_NUMBER; i++ )
	{
		cout << menu[i] << endl;
		if ( menu[i] == "readfile" )
		{
			int submenu_elements = sizeof(submenu)/sizeof(submenu[0]);
			for ( int j = 0; j < submenu_elements; )
			{
				cout << "\t" << submenu[j++] << endl;
			}
		}
	}
	
	system("pause");
	
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
	cout << "Your sum is: " << sum << endl;
	delete [] sequence;
	
	return 0;
}
