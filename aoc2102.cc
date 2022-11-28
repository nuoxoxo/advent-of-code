#include "iostream"

using	namespace std;

int	main()
{
	string	s;
	int	n;
	int	f = 0;
	int	d = 0;

	// part 2

	int	aim = 0;
	int	dd = 0;
	int	ff = 0;


	while (cin >> s >> n)
	{
		// cout << s << " :: " << n << endl;
		if (s[0] == 'd')
		{
			d += n;
			aim += n;
		}
		else if (s[0] == 'u')
		{
			d -= n;
			aim -= n;
		}
		else if (s[0] == 'f')
		{
			f += n;
			ff += n;
			dd += aim * n;
		}
	}
	cout << "Star 1: " << f * d << endl;
	cout << "Star 2: " << ff * dd << endl;
}
