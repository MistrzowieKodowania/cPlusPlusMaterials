#include "engine.h"
#include "examples.h"

Operation parse_operation( string operation )
{	
	istringstream soperation(operation);
	Operation descriptor;
	
    while (!soperation.eof())
    {
    	string sub;
		soperation >> sub;

    //     cout << "Substring: " << sub << endl;
    //     system("pause");
        
 		if ( sub == "+" || sub == "sqrt" ) // operators
		{
			descriptor.sign = sub;
			sub == "+" ? descriptor.category = SUM : descriptor.category = SQUARE_ROOT;
		}
		else // numbers
		{
			double number;
			istringstream nparser(sub);
			nparser >> number;
			descriptor.numbers.push_back(number);
		}
    }
    
    return descriptor;
}

double run_operation( Operation& operation )
{
	switch ( operation.category )
	{
		case SUM:
			return sum( operation.numbers[0], operation.numbers[1] );
		case SQUARE_ROOT:
			return square_root( operation.numbers[0] );
		default:
			cout << "Unknown operation" << endl;
			return 0;
	} 
}
