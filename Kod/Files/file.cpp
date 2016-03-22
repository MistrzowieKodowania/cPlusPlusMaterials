#include <iostream>
#include <string>
#include <fstream> // biblioteka do wczytawania pliku
using namespace std;

// http://www.cplusplus.com/doc/tutorial/files/
// input validation -> Additional
int main()
{
	string* test = new string("To te¿ siê zapisze\nabc");
	
	// fstream => int, string (typ)
	fstream writer; // zapisywanie do pliku (obiekt) o dowolnej nazwie
	cout << "Zapisywanie do pliku" << endl;
	writer.open ("example.txt", ios::out | ios::app); // otworzenie pliku do zapisu i dodawania na koniec pliku
                                           // ios::out -> tryb zapisu, ale bez ios::app plik bêdzie tworzony na nowo (stary zostanie nadpisany)
	writer << "Zapiszê to do pliku. Ja nie potrafiê?\n";
	// cout << "Zapiszê to do pliku. Ja nie potrafiê?\n";
	//writer.write( test->c_str(), test->size()); // zapisywanie do pliku wybran¹ liczbê znaków z tekstu
	writer.close();
	writer << "Zapiszê to do pliku. Ja nie potrafiê?\n"; // to ju¿ siê nie wykona boplik jest zamkniêty
	system("pause");
	
	fstream reader;
	reader.open("plik.txt", ios::in);
	if ( reader.is_open() )
	{
		cout << "Zadzialalo" << endl;	
	} 
	
	string line;
	// funkcja getline wczytuje linie ale bez znaków nowej linii
	while ( getline (reader,line) ) // wczytywanie po linijkach
	{
		cout << line << endl;
	}	

/*
	char buffer[200]; 
	while ( reader.getline(buffer, 200) ) // gdyby linia by³a d³u¿sza ni¿ 200 znaków nie zosta³aby wczytana
	{
		cout << buffer << "\n";
	}
*/	
	/*
	char c;
	while ( reader.get(c) ) // tutaj enter siê wczytuje i ka¿dy znak
	{
		cout << c;
	}*/
	
	/*
	char c;
	while ( reader >> c ) // tutaj enter siê nie wczytuje
	{
		cout << c;
	}
	*/
			
	reader.close(); // zamkniêcie pliku
	
	delete test;
	return 0;
}
