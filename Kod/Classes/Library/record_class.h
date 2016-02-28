#include <iostream>
#include <string>
using namespace std;

// to ju¿ jest klasa!
class Record_Class // s³owo kluczowe class, a potem dowolna nazwa klasy
{
	public: // tutaj mamy s³owo kluczowe public - oznaczaj¹ce, ¿e zaczyna siê lista metod (rzeczy)  publicznych
		Record_Class(); // konstruktor bezargumentowy, ten konkstruktor jest domyœlny - musi istnieæ jego implementacja
		Record_Class( string name_1, string surname_1, int day_1, int month_1, int year_1 ); // konstruktor z argumnetami
		~Record_Class();
		void set_record( string name, string surname, int day, int month, int year ); // metoda
		void print_record(); // metoda
		bool operator>(Record_Class const & record); // operator porównania >
		// przeci¹¿anie operatora
		// obiekt_1 > obiekt_2
		// obiekt_1 -> by³by tym 'naszym', czyli wskazywany przez wskaŸnik "this"
		// obiekt_2 -> by³by tym "record" z listy argumentów

	private:
		// zwyczajowo w jêzyku C++ wszelkie zmienne s¹ prywatne - niewidoczne na zewn¹trz
		string name;
		string surname;
		int day;
		int month;
		int year;	
};
