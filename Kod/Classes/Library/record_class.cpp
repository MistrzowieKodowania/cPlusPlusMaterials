#include "record_class.h"

Record_Class::Record_Class( string name, string surname, int day, int month, int year ) : name(name), surname(surname),
            day(day), month(month), year(year)
{
	
}

Record_Class::Record_Class()
{
	
}

Record_Class::~Record_Class()
{
	
}

void Record_Class::set_record( string name, string surname, int day, int month, int year )
{
	this->name = name;
	surname = surname;
	day = day;
	month = month;
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
	return this->name > record.name;
}
