
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm> // tutaj jest sortowanie
using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

struct Event
{
	string name;
	Date date;	
};

// to nam porówna dwa wydarzenia
bool compare_events (Event& first, Event& second);

// pomocnicza funkcja do wczytanie wydarzeñ od u¿ytkownika
void read_calendar(vector<Event>& events);
bool check(string& birth);
Date create(string& birth);

void print_date(Date& date)
{
	cout << "\tDay: " << date.day;
	cout << " Month: " << date.month;
	cout << " Year: " << date.year << endl;
}
void print_event(Event& event)
{
	cout << "Name: " << event.name;
	print_date(event.date);
}

bool compare_dates( Date& first, Date & second );

// do porównywania wydarzeñ
bool compare_events (Event& first, Event& second)
{
	// sortowanie wzglêdem nazwy
	// porównujemy ze sob¹ nazwy
//	return first.name < second.name;	
	
	return compare_dates(first.date, second.date);
}

bool compare_dates( Date& first, Date & second )
{
	// coœ implementujemy
	return first.year < second.year ||
	    (first.year == second.year && first.month < second.month) ||
	    (first.year == second.year && first.month == second.month && first.day < second.day);
}

int main()
{
	string event;
	vector<Event> events;
	read_calendar(events);
		
	if ( !events.empty() )
	{
		cout << "Your calendar: " << endl;

		for( int i = 0; i < events.size(); i++ )
			print_event(events[i]);
	
		// sortowanie
		sort( events.begin(), events.end(), compare_events );
		
		cout << "Your sorted calendar: " << endl;
		for( int i = 0; i < events.size(); i++ )
			print_event(events[i]);
	}
	
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

void read_calendar(vector<Event>& events)
{
	while(1)
	{
		string date;
		string name;
		do
		{
			cout << "Give me imporant dates as: <name> dd.mm.yyyy" << endl;
			cout << "Quit to finish" << endl;
					
			cin >> name;
			if ( name == "Quit" || name == "quit" )
				break;
				
			getline(cin, date);
			
		} while( ! check(date) );

		if ( name == "Quit" || name == "quit" )
			break;
			
		Date important = create(date);
		Event event = { name, important };
		events.push_back(event);		
	}	
}
