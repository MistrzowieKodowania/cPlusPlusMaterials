#include <iostream>
#include <string>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

struct Record
{
	string name;
	string surname;

	Date deadline;	
};
