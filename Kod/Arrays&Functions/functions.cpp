#include "functions.h"

// funkcja zwraca "int" - jest return na koñcu
// wyobraŸ sobie, ¿e prosisz kogoœ aby zrobi³ zadanie z matematyki
// ktoœ to robi i mówi Ci jaki jest wynik
// nie interesuje Ciê "jak" zrobi³ tylko wynik
// ta funkcja nie jest zgodna z dobrymi praktykami programistycznymi!!
// za d³uga, robi zbyt du¿o rzeczy
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
	
	int sum = sum_example(); // wywo³anie funkcji
	cout << "Your sum is: " << sum << endl;

	system("pause");

	print_menu( menu, MENU_ELEMENTS_NUMBER, submenu, submenu_elements ); // wywo³anie funkcji z argumentami

	return 0;
}

// definicja (jest za main ale dziêki deklaracji main j¹ widzi! bez deklaracji (w pliku functions.h!)
// main nie widzi tej funkcji bo jest ni¿ej - b³¹d kompilacji)

// jak wygl¹da funkcja
// <typ zwracany> nazwa_funcji(<argumenty> .... )
// void - funkcja nic nie zwraca - nie ma return
// funkcja te¿ nie musi mieæ argumentów
// zobaczcie, ¿e tablic¹ jest menu oraz submenu (a jest inny zapis tych argumentów)
// jest to równowa¿ny zapis
void print_menu( string menu[], int menu_size, string* submenu, int submenu_size)
{
	for ( int i = 0; i < menu_size; i++ )
	{
		cout << menu[i] << endl;
		if ( menu[i] == "readfile" )
		{
			for ( int j = 0; j < submenu_size; j++ )
			{
				cout << "\t" << *(submenu + j) << endl; // tutaj odwo³ujemy siê do tablicy poprzez wskaŸnik!
				                                        // zobaczcie, ¿e przesuwamy wskaŸnik o j elementów
				                                        // dodaj¹c * przed pobieramy wartoœæ
				cout << "\t" << submenu[j] << endl; // zamiast przesuwania wskaŸnika mo¿emy odwo³ywaæ siê
				                                    // poprzez [] wstawiaj¹c indeks tablicy - numer elementu
				                                    // *(submenu + j) jest równowa¿ne z submenu[j]
			}
		}
	}
}

