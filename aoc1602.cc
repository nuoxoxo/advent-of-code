/*
1 2 3
4 5 6
7 8 9
*/
/*
    1
  2 3 4
5 6 7 8 9
  A B C
    D
*/

#include "header.hpp"

int	main()
{
	string		s;

	vector<string>	man = {"123", "456", "789"};
	string		res;
	int		r, c;

	vector<string>	man2 = {"00100", "02340", "56789", "0ABC0", "00D00"};
	string		res2;
	int		rr, cc;

	rr = 2;
	cc = 2;
	r = 1;
	c = 1;
	while (cin >> s)
	{
		for (char l: s)
		{
			//	part 1

			if (l == 'U')
				--r;
			if (l == 'L')
				--c;
			if (l == 'R')
				++c;
			if (l == 'D')
				++r;
			r = r > 2 ? 2 : r;
			r = r < 0 ? 0 : r;
			c = c > 2 ? 2 : c;
			c = c < 0 ? 0 : c;

			//	part 2

			if (l == 'U')
			{
				if (rr - 1 > -1 && man2[rr - 1][cc] != '0')
					rr -- ;
			}
			if (l == 'D')
			{
				if (rr + 1 < 5 && man2[rr + 1][cc] != '0')
					rr ++ ;
			}
			if (l == 'L')
			{
				if (cc - 1 > -1 && man2[rr][cc - 1] != '0')
					cc -- ;
			}
			if (l == 'R')
			{
				if (cc + 1 < 5 && man2[rr][cc + 1] != '0')
					cc ++ ;
			}
		}
		res2 += man2[rr][cc];
		res += man[r][c];
	}
	cout << "Star 1: " << res << endl;
	cout << "Star 2: " << res2 << endl;
}
