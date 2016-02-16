#define MENU_ELEMENTS_NUMBER 4 // sta³a, rozwi¹zuje problem magic numbers

#include <iostream>
#include <string>

using namespace std;


int main()
{
	                                    // 0          1          2         3
	string menu[MENU_ELEMENTS_NUMBER] = { "start", "read file", "quit", "help" }; // od razu rozmiar
	string submenu[] = { "readimage", "readtext"}; // w [] nie ma wartoœci, ale program wie ¿e rozmiar to 2
	
	/*
	int a;
	int abc;
	string menu[]
	string abc[];
	*/
	
	// tablice indeksujemy od 0!!!!!
	for ( int i = 0; i < MENU_ELEMENTS_NUMBER; i++ )
	{
		cout << menu[i] << endl; // wyswietla kolejne elementy tablicy menu
		if ( menu[i] == "read file" ) // tutaj wyœwietlanie tablicy submenu
		{
			int submenu_elements = sizeof(submenu)/sizeof(submenu[0]); 
			// string zawsze zajmuje w pamiêci X bajtów
			// sizeof(submenu) -> ile bajtów zajmuje ca³a tablica!
			// sizeof(submenu[0]) -> X
			for ( int j = 0; j < submenu_elements; ) // pêtla for nie musi mieæ wszystkich "elementów" pomiêdzy œrednikami
			{
				cout << "\t" << submenu[j++] << endl;
			}
			// 1 krok pêtli
			// je¿eli j = 0 to, element który czytamy jest elementem 2 tablicy,
			// bo ++j wykona siê na samym pocz¹tku
			// ++j wykona siê "przed"
			// j++ wykona siê "po"
			
			
			/*
			for ( ;;)
			{
				
			}
			to wy¿ej równa siê temu ni¿ej
			while(true)
			{
			
			}
			*/
		}
	}
	
	system("pause");
	
	int* sequence = NULL; // * - wskaŸnik (adres), na pocz¹tku pusty
	int sequence_size;
	int sum = 0;
	cout << "How many numbers you want to sum?" << endl;
	cin >> sequence_size;
	
	// new ¿eby utworzyæ tablicê dynamiczn¹
	sequence = new int[sequence_size]; // przypisujemy do wskaŸnika jakiœ element pamiêci
	cout << "Give me " << sequence_size << " integers" << endl;
	for ( int i = 0; i < sequence_size; ++i )
	{
		cin >> sequence[i]; // liczby wrzucane s¹ do "worka cukierków" 
	}
	cout << "Thanks." << endl;
	int i = 0;
	int* identifier = sequence; // nic tutaj siê nie kopiuje, tworzê nowy identyfikator -> sequence, identifier dowolna nazwa 
	while( i < sequence_size)
	{
		int element = identifier[i++];  // what if ++i?
		cout << "Element " << element << endl;
		system("pause");
		sum += element; // sum += element to jest to samo co sum = sum + element 
	}
	cout << "Your sum is: " << sum << endl;
	delete [] sequence; // delete ¿eby j¹ usun¹æ
	
	return 0;
}
