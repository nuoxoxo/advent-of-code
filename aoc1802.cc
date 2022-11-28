#include "header.hpp"

int	main()
{
	string	s;
	int	l;
	int	ok2;
	int	ok3;
	int	count;
	int	r2, r3;

	vector<string>	v;

	r2 = r3 = 0;
	while (cin >> s)
	{
		v.push_back(s);

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

	bool	ok;
	int	i, j, k, idx;
	string	part2;


	i = -1;
	while (++i < (int) v.size() - 1)
	{
		j = i;
		while (++j < (int) v.size())
		{
			k = 0;
			count = 0;
			ok = false;
			while (k < (int) v[i].length())
			{
				if (v[i][k] != v[j][k])
				{
					count++;
					idx = k;
				}
				++k;
			}
			if (count ^ 1)
				continue ;
			ok = true;
			part2 = v[i].substr(0, idx);
			part2 += v[i].substr(idx + 1, (int) v[i].length() - 1 - idx);
			break ;
		}
		if (ok)
			break ;

	}

	// cout << r2 << '*' <<  r3 << endl; // part 1 debugger

	cout << "Star 1: " << r2 * r3 << endl;
	cout << "Star 2: " << part2 << endl;
}
