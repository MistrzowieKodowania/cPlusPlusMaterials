#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// http://www.cplusplus.com/doc/tutorial/files/
// input validation -> Additional

int main()
{
	fstream writer;
	cout << "Zapisywanie do pliku" << endl;
	writer.open ("example.txt", ios::out);  
	writer << "Zapiszê to do pliku. Ja nie potrafiê?\n";
	writer.close();
	system("pause");
	
	fstream reader;
	reader.open("plik.txt", ios::in);
	if (reader.is_open())
	{
		
		string line;
		while ( getline (reader,line) ) // wczytywanie po linijkach
		{
			cout << line << "\n";
		}
		
		/*char buffer[200]; 
		while ( reader.getline(buffer, 200) )
		{
			cout << buffer << "\n";
		}*/
		
		/*
		char c;
		while ( reader.get(c) )
		{
			cout << c;
		}*/
		/*
		char c;
		while ( reader >> c )
		{
			cout << c;
		}
		*/
		
		reader.close();
	}
	else
	{
		cout << "Error! " << endl;
		system("pause");
		exit(1);
	}
	
	return 0;
}
