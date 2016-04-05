
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Zgrupowanie trzech liczb ca³kowitych
// struktura to taka prymitywna klasa
// tak jakby klasa której wszystkie elementy s¹ publiczne
struct Date
{
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int seconds;
};

// argumentami funkcji s¹ dwie daty (a nie np. 6 liczb ca³kowitych)
int years(Date& user, Date& today);
bool check(string& birth);
Date create(string& birth);

// drukowanie daty na ekranie
void print_date(Date& date)
{
	cout << "Day: " << date.day;
	cout << " Month: " << date.month;
	cout << " Year: " << date.year << endl;
}

int main()
{
	// Inicjalizujemy datê
	Date today = { 5, 4, 2016 };
	string birth;
	
	cout << "Give me your birth date as dd.mm.yyyy" << endl;
	do
	{
		getline(cin, birth); // wczytanie ca³ej linijki.
	} while( ! check(birth) );
	
	Date user = create(birth);
	int user_years = years(user, today);
	cout << "Today is: " << endl;
	print_date(today);
	
	cout << "Your birth date is: " << endl;
	print_date(user);
	cout << "You have: " << user_years << " years" << endl;
	return 0;
}

bool check(string& birth)
{
	// 12.04.2016
	// 12.4.2016
	return true;
}

Date create(string& birth)
{
	stringstream st(birth);
	// st to tak jakby "cout" lub "cin"
	// st to strumieñ, do którego w³o¿yliœmy nasz napis
	// i mo¿emy go czytaæ tymi samymi metodami co w "cin"
	Date user;
	st >> user.day;
	st.ignore(1); // ignorowanie kropki
	st >> user.month; // wczytujê kolejny int
	st.ignore(1); // ignorujê kropkê
	st >> user.year;
	
	return user;
}

int years(Date& user, Date& today)
{
	int yyears = today.year - user.year;
	
	int years = today.month < user.month || 
	(user.month == today.month && today.day < user.day ) ?
	yyears - 1 : yyears;
	
	return years;
}
