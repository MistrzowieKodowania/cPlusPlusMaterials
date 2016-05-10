#include <exception> // biblioteki wyj¹tków
using namespace std;

// wyj¹tki - jak coœ z³ego siê dzieje mo¿emy zwróciæ wyj¹tek
// przechwyciæ go i zareagowaæ na b³¹d
class OutOfRange : public exception
{
	public:
		OutOfRange(int i) : i(i)
		{
		}
		
		virtual const char* what() const throw()
		{
			return "Out of range exception happended";
		}
  
  	private:
		int i;
};
