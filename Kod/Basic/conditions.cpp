
#include <iostream>
enum { HORRIBLE=1, BAD, GOOD, EXCELLENT }; // typ wyliczeniowy (kolejne liczby naturalne) - nie musi mieæ nazwy
/* enum { HORRIBLE=1, BAD, GOOD, EXCELLENT }; - HORRIBLE = 1, BAD = 2, GOOD = 3 ....
enum { HORRIBLE, BAD, GOOD, EXCELLENT }; HORRIBLE = 0, BAD = 1, GOOD = 2 ....
enum { HORRIBLE=1, BAD=3, GOOD=2, EXCELLENT=4 }; wiadomo ;) */
using namespace std;

int main()
{
	int value;
	int decision;
	
	// 1
	cout << "Give me an integer less than 10 please..." << endl;
	cin >> value;
	if ( value < 10 )
	{
		cout << "Correct!" << endl;
	}
	else
	{
		cout << "Incorrect. Too high!" << endl;
	}
	
	// 2
	cout << "Give me an integer between 10 and 20 please..." << endl;
	cin >> value;
	if ( value < 10 )
	{
		cout << "Incorrect. Too low!" << endl;
	}
	else if ( value > 10 && value < 20 )
	{
		cout << "Correct!" << endl;
	}
	else
	{
		cout << "Incorrect. Too high!" << endl;
	}
	
	// 3
	cout << "Give me an integer lower than 10 or higher than 20 please..." << endl;
	cin >> value;
	value < 10 || value > 20 ? cout << "Correct." << endl : cout << "Incorrect!" << endl;
	// sk³adnia operatora ? tzw. trójargumentowego:   warunek ? kod gdy sukces : kod gdy pora¿ka
	// value < 10 || value > 20 - warunek
	// cout << "Correct." << endl - kod gdy sukces
	// cout << "Incorrect!" << endl - kod gdy pora¿ka
	// || - operator logiczny lub
	// && - operator logiczny and
	
	// 4
	cout << "What do you think about programming?" << endl;
	cout << "Choose one option: 1: horrible, 2: bad, 3: good, 4: excellent" << endl;
	cin >> decision;
	switch( decision )
	{
		case HORRIBLE: // zmienna enumeracyjna - wyliczeniowa
		               // typ wyliczeniowy = kod czytelniejszy (pozbawiony tzw. magic numbers)
                               // kod dobrej jakoœci => kod bez magic numbers
			cout << "Go and play games." << endl; break;
		case BAD:
			cout << "Try Scratch." << endl; break;
		case GOOD:
			cout << "Look at C++ my padawan" << endl;
			cout << "Additional line" << endl; break; // w case mo¿na napisaæ wiele linii, a¿ do break. break
                                                                  // break przerywa wykonanie "case"
                                                                  // bez break program "idzie dalej" wykonuj¹c wszystko po kolei
		case EXCELLENT:
			cout << "Thank you my master" << endl; break;
		default: // else
			cout << "Try one more time" << endl; break;
	}
	
	return 0;
}
