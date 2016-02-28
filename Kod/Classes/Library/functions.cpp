#include "functions.h"

// & - referencjê
// referencja u¿yta jako argument funkcji powoduje, ¿e 
// ten argument nie jest kopiowany
// domyœlnie przekazuj¹c coœ do funkcji
// system operacyjny kopiuje wartoœæ tego czegoœ z komórki pamiêci
// do innej komórki pamiêci
// 
// u¿ywaj¹c referencji nie kopiujemy tylko dzia³amy dok³adnie na tej
// samej pamiêci!
void set_record( Record& record, string name, string surname, int day, int month, int year )
{
	record.name = name;
	record.surname = surname;
	record.deadline.day = day;
	record.deadline.month = month;
	record.deadline.year = year;
}

void sort_by_name( Record library[], int size )
{
	bubble_sort_by_name(library, size);
}

void bubble_sort_by_name(Record library[], int size)
{
	for ( int i = 0; i < size; i++ )
	{
		for ( int j = 1; j < size; j++ )
		{
			if ( library[j - 1].name > library[j].name )
			{
				// zamieñ pozycje
				Record previous = library[ j - 1 ];
				library[j - 1 ] = library[j];
				library[j] = previous;
			}
		}
	}
}

void sort_by_name( Record_Class library[], int size )
{
	bubble_sort_by_name(library, size);
}

void bubble_sort_by_name(Record_Class library[], int size)
{
	for ( int i = 0; i < size; i++ )
	{
		for ( int j = 1; j < size; j++ )
		{
			if ( library[j - 1] > library[j] ) // u¿ycie operatora wiêkszoœci
			{
				// zamieñ pozycje
				Record_Class previous = library[ j - 1 ]; // tutaj nasz obiekt jest kopiowany
				library[j - 1 ] = library[j];
				library[j] = previous; // tutaj te¿ siê kopiuje
			}
			// tutaj wywo³uje siê destruktor "previous"
			// tylko raz - poniewa¿ zamiana jest wykonywana tylko raz!
		}
	}
}

void print( Record library[], int size ) 
{
	cout << "----------------------------------" << endl;
	for ( int i = 0; i < size; i++ )
	{
		cout << "Name: " << library[i].name << " ";
		cout << "Surname: " << library[i].surname << " ";
		cout << "Day: " << library[i].deadline.day << " ";
		cout << "Month: " << library[i].deadline.month << " ";
		cout << "Year: " << library[i].deadline.year << " " << endl;
	}
	cout << "----------------------------------" << endl;
}

void print( Record_Class library[], int size ) 
{
	cout << "------------Class--------------------" << endl;
	for ( int i = 0; i < size; i++ )
	{
		library[i].print_record();
	}
	cout << "----------------------------------" << endl;
}
