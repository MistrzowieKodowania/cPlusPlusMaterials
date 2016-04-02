
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
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

bool compare_events (Event& first, Event& second);
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

bool compare_events (Event& first, Event& second)
{
	return first.name < second.name;	
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
