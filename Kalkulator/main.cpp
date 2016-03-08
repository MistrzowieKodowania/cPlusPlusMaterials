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
	
		getline(cin, operation); // pozwala nam czytaæ linie razem ze spacjami!
		if ( operation == "Q" || operation == "q"  )
		{
			break;
		}
		
		Operation request = parse_operation(operation); // parsujemy operacjê - sprawdzamy jczym ona jest
		system("cls");
		if ( request.sign != "+" && request.sign != "sqrt" ) // sprawdzamy czy u¿ytkownik wybra³ sumê lub pierwiastek prawid³owo
		{	
			continue; // przenosi nas na pocz¹tek pêtli
		}
		double result = run_operation( request ); // wykonujemy operacjê (sumy lub pierwiastka)
		
		cout << "Your result: " << result << endl;
	}
}
