#ifndef _ENGINE_H
#define _ENGINE_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef enum { SUM, SQUARE_ROOT, OPERATIONS_COUNT
} OperationCategory; 

struct Operation
{
	string sign;
	OperationCategory category;
	vector<double> numbers;	
};

Operation parse_operation( string operation );
double run_operation( Operation& operation );

#endif /* _ENGINE_H */
