#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// funkcja do wczytywania pliku
// zwraca wektor zawieraj¹cy wszystkie linijki plików
vector<string> read_file(string nazwa_pliku)
{
	fstream reader;
	vector<string> lines;
	// sprawdŸmy adres wektora w pamiêci
	cout << "Adres wektora z read_file linijka 13: " << &lines << endl << endl;
	
	reader.open (nazwa_pliku.c_str(), ios::in); // istotne jest to, ¿e "open" wymaga
	                                            // typu const char*, a nie string
	                                            // dlatego u¿ywamy metody c_str()
	                                            // aby zamieniæ string na const char*
	if (reader.is_open())
	{
	string line;
	while (getline(reader,line))
		lines.push_back(line);
	}
	reader.close();
	return lines;
}

// funkcja do wczytywania pliku
// drugi sposób - wynik zapisywany w wektorze przekazywanym
// przez referencjê
// mo¿na jeszcze przez wskaŸnik - do eksperymentowania
// wtedy zadzia³a podobnie jak ta funkcja, ale napiszemy trochê wiêcej kodu
// a co siê stanie jak przeka¿emy wektor do funkcji przez wartoœæ?
// czyli tak:
// void read_file(string nazwa_pliku, vector<string> lines) 
// do poeksperymentowania (usuñ symbol & z funkcji poni¿ej)
// dlaczego tak siê sta³o?
void read_file(string nazwa_pliku, vector<string>& lines)
{
	cout << "Adres wektora z read_file linijka 31: " << &lines << endl << endl;

	fstream reader;
	reader.open (nazwa_pliku.c_str(), ios::in);
	if (reader.is_open())
	{
	string line;
	while (getline(reader,line))
		lines.push_back(line);
	}
	reader.close();
}

int main()
{
	vector<string> lines;
	string nazwa_pliku;
	getline(cin,nazwa_pliku);
	
	// pierwszy sposób na wczytanie pliku
	// funkcja zwraca wektor
	// co to znaczy zwrócenie wektora?
	// jak to wygl¹da w pamiêci komputera?
	// w pamiêci wygl¹da to tak, ¿e 
	// vector<string> z linijki 13 w funkcji read_file
	// ma zarezerwowany swój w³asny obszar oraz
	// vector<string> z linijki poni¿ej ma w³asny
	// elementy z pamiêci przeznaczonej dla wektora
	// z linijki 13 s¹ kopiowane do tego poni¿ej
	// Zwracanie wektora przez wartoœæ (nie wskaŸnik i nie referencjê!)
	// oznacza kopiowanie
	// eksperymenty:
	// co by by³o gdyby zwracaæ wskaŸnik na wektor z linijki 13?
	// czy mo¿emy zwróciæ referencjê?
	//
	// podpowiedŸ: ¿ywotnoœæ zmiennych w pamieci jest ograniczona do bloku
	// funkcja jest osobnym blokiem, a wiêc po wyjœciu z funkcji wektor z linijki
	// 13 mo¿e "znikn¹æ" lub zostaæ swobodnie nadpisany przez system operacyjny
	lines = read_file(nazwa_pliku);
	
	cout << "Adres wektora z main linijka 70: " << &lines << endl << endl;
	
	for ( int i = 0; i < lines.size(); i++ )
		cout << lines[i] << endl;
	cout << endl << endl;
	
	// ale nie musimy kopiowaæ danych (co czasem mo¿e obni¿aæ szybkoœæ dzia³ania programu)
	vector<string> lines2;
	
	// tutaj korzystamy z funkcji w której przekazujemy referencjê
	// wektor z funkcji jest dok³adnie tym samym co z linijki 72
	// wk³adamy elementy do "otwartego" wektora i nic nie kopiujemy
	// kod bêdzie szybszy
	read_file(nazwa_pliku, lines2);
	
	cout << "Adres wektora z main linijka 79: " << &lines2 << endl << endl;
	
	for ( int i = 0; i < lines2.size(); i++ )
		cout << lines2[i] << endl;
}
