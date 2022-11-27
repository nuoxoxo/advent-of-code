#include "header.hpp"

int	main()
{
	string	s;
	int	l;
	int	ok2;
	int	ok3;
	int	count;
	int	r2, r3;

	r2 = r3 = 0;
	while (cin >> s)
	{
		ok2 = 0;
		ok3 = 0;
		l = 'a' - 1;
		while (++l < 'z' + 1)
		{
			if (ok2 && ok3)
				break ;
			count = 0;
			if (!ok2)
			{
				for (char c : s)
				{
					if (ok2)
						break ;
					if (l == c)
						++count;
				}
				if (!ok2 && count == 2)
				{
					++ok2;
					++r2;
				}
			}
			if (!ok3)
			{
				count = 0;
				for (char c : s)
				{
					if (l == c)
						++count;
				}
				if (count == 3)
				{
					++ok3;
					++r3;
				}
			}
		}
	}
	//cout << r2 << '*' <<  r3 << endl;
	cout << "Star 1: " << r2 * r3 << endl;
}
