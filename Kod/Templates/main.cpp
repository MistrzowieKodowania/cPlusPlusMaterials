#include "array.h"

int main(int argc, char** argv) 
{
	Array<int, 10> intarray;
	Array<double, 10> doublearray;
	
	for ( int i = -1; i < 11; i++ )
	{
		try // w taki sposób obs³uguje siê wyj¹tki (try - sprawdzanie czy instrukcja
		                                            // wykona siê poprawnie
		{
			cout << "element intarray: " << intarray[i] << endl;
			cout << "element doublearray: " << doublearray[i] << endl;
		}
		catch (exception& e) // catch - ³apanie b³êdów
		{
			cout << e.what() << endl; // a tutaj mo¿emy wyœwietliæ komunikat
			                          // i nie wychodziæ albo wyjœæ albo
			                        // cokolwiek np. wyczyœciæ pamiêæ
		}
	}
}
