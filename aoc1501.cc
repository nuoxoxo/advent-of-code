#include "iostream"

using	namespace std;

int	main()
{
	string	s;
	int	r = 0;
	int	p = 0, ok = 0, r2 = 0;
	cin >> s;
	for (char c: s)
	{
		++p;
		r = c == '(' ? r + 1 : r - 1;
		if (!ok && r == -1)
		{
			r2 = p;
			ok = 1;
		}
	}
	cout << "Star 1: " << r << endl;
	cout << "Star 2: " << r2 << endl;
}
