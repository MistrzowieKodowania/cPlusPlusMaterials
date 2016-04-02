
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

int years(Date& user, Date& today);
bool check(string& birth);
Date create(string& birth);
void print_date(Date& date)
{
	cout << "Day: " << date.day;
	cout << " Month: " << date.month;
	cout << " Year: " << date.year << endl;
}

int main()
{
	Date today = { 5, 4, 2016 };
	string birth;
	
	cout << "Give me your birth date as dd.mm.yyyy" << endl;
	do
	{
		getline(cin, birth);
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

	return true;
}

Date create(string& birth)
{
	stringstream st(birth);
	Date user;
	st >> user.day;
	st.ignore(1);
	st >> user.month;
	st.ignore(1);
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
