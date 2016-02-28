#include <iostream>
#include <string>
using namespace std;

class Record_Class
{
	public:
		Record_Class();
		Record_Class( string name, string surname, int day, int month, int year );
		~Record_Class();
		void set_record( string name, string surname, int day, int month, int year );
		void print_record();
		bool operator>(Record_Class const & record);

	private:
		string name;
		string surname;
		int day;
		int month;
		int year;	
};
