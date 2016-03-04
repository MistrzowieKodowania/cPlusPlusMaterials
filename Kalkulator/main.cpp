#include "engine.h"
#include "examples.h"

int main()
{
	string operation;
	cout << "I'm calculator. Examples: " << endl;
	examples();
	system("pause");
	system("cls");
	cin.sync();
	while ( true )
	{
		cout << "What do you want to calculate?" << endl;
		cout << "You could use: +, sqrt as in the examples" << endl;
		cout << "Use Q/q to exit" << endl;
	
		getline(cin, operation);
		if ( operation == "Q" || operation == "q"  )
		{
			break;
		}
		
		Operation request = parse_operation(operation);
		system("cls");
		if ( request.sign != "+" && request.sign != "sqrt" )
		{	
			continue;
		}
		double result = run_operation( request );
		
		cout << "Your result: " << result << endl;
	}
}
