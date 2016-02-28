#include "record_class.h"

// konstruktor
// konstruktor argumentowy
Record_Class::Record_Class( string name_1, string surname_1, int day_1, int month_1, int year_1 ) : name(name_1), surname(surname_1),
            day(day_1), month(month_1), year(year_1) // lista inicjalizacyjna, pocz¹tek tej listy oznaczany jest : tu¿ po konstruktorze
                                               // dotyczy tylko konstruktorów!
{
	/*
	zamiast listy inicjalizacyjnej mo¿emy ustawiæ wszystko tutaj!
	np. 
	this->name = name_1; // this to wskaŸnik na "ten" obiekt
	this->surname = surname_1; // poniewa¿ this jest wskaŸnikiem to do elementów obiektu odwo³ujemy sikê poprzez ->,
	                           // a nie poprzez kropkê tak jak wczeœniej pokazywa³em
	
	innym sposbem by³oby wywo³anie metody set_record
	this->set_record(name_1, surname_1, day_1, month_1, year_1);
	*/	
}

// konstruktor domyœlny
// ten musi byæ zawsze zaimplementowany
Record_Class::Record_Class()
{
	cout << "Build" << endl;
}

// destruktor
Record_Class::~Record_Class()
{
	cout << "Destroy" << endl;
}

// oznaczamy sk¹d pochodzi metoda u¿ywaj¹c
// nazwa_klasy::metoda
void Record_Class::set_record( string name, string surname, int day, int month, int year )
{
	this->name = name; // mo¿emy u¿ywaæ this (wskaŸnik dlatego ->)
	this->surname = surname; // ale nie musimy mo¿emy u¿yæ po prostu nazwy z klasy
	this->day = day;
	this->month = month;
	this->year = year;
}


void Record_Class::print_record()
{
	cout << "Name: " << name << " ";
	cout << "Surname: " << surname << " ";
	cout << "Day: " << day << " ";
	cout << "Month: " << month << " ";
	cout << "Year: " << year << " " << endl;
}

bool Record_Class::operator>(Record_Class const & record)
{
	return this->name > record.name; // jest to metoda z klasy
	                                // to mo¿liwe jest pobranie prywatnej! wartoœci "name"
	                                // record.name
}
