#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    char polish[64]; // ³añcuch znakowy (ale nie string, tablica - o nich wiêcej na 3 zajêciach)
	CharToOem("¹êŸæœ¿", polish); // funkcja z biblioteki windows.h: chyba najprostsze rozwi¹zanie problemu,
	                             // ale na Linuxie nie zadzia³a.
	cout << "polskie znaki: <<<< " << polish << " >>>>" << endl;
	
	/* W przypadku polskich znaków i innych znaków poza ASCII problem jest doœæ skomplikowany
	   mo¿na u¿ywaæ i warto u¿ywaæ gotowych bibliotek przeznaczonych do takich celów np. iconv
	   http://gnuwin32.sourceforge.net/packages/libiconv.htm
	   http://manpages.ubuntu.com/manpages/jaunty/man1/iconv.1.html
	   na pocz¹tku przygody warto jednak nie u¿ywaæ takich znaków (np. pisaæ programy po angielsku)
	   albo u¿ywaæ najprostszych rozwi¹zañ jak prezentowane wy¿ej
	*/
	
	return 0;
}
