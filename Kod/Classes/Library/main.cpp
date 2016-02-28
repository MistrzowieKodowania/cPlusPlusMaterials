#include "functions.h"
#define LIBRARY_SIZE 2


int main(int argc, char** argv) 
{
	Record library[LIBRARY_SIZE];
	
	set_record( library[0], "Jan", "Kowalski", 1, 5, 2015 );
	set_record( library[1], "Adam", "Nowak", 29, 12, 2015 );
	print(library, LIBRARY_SIZE);	
	sort_by_name(library, LIBRARY_SIZE);
	print(library, LIBRARY_SIZE);	
	
	cout << endl;
	cout << "Class" << endl;
	
	Record_Class library_class[LIBRARY_SIZE];
	library_class[0].set_record("Jan", "Kowalski", 1, 5, 2015);
	library_class[1].set_record("Adam", "Nowak", 29, 12, 2015);
	print(library_class, LIBRARY_SIZE);
	sort_by_name(library_class, LIBRARY_SIZE);
	print(library_class, LIBRARY_SIZE);
	
	return 0;
}
