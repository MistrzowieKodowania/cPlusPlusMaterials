
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
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

int main()
{
	string event;
	vector<Event> events;

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
	
	if ( !events.empty() )
		cout << "Your calendar: " << endl;
	
	for( int i = 0; i < events.size(); i++ )
		print_event(events[i]);
	
	system("pause");
	
	for( vector<Event>::iterator it = events.begin();
		 it != events.end(); it++ )
	{
		print_event(*it);
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

