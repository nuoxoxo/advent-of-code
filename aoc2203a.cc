#include "h.hpp"

int	main()
{
	vector<string>	v;
	string		ss;
	int		r = 0;
	int		r2 = 0;

	while (cin >> ss)
	{
		// for (char & c: ss)
		//	c = tolower(c);
		v.push_back(ss);
	}
	// for (string & s: v)
	int	x = -1;
	while (++x < (int) v.size())
	{
		string	s = v[x];
		int	len = (int) s.length();
		int	i, j;
		int	c;
		bool	ok = false, ok2 = false;


		i = -1;
		while (++i < len / 2 && !ok)
		{
			c = s[i];
			j = len / 2 - 1;
			while (++j < len && !ok)
			{
				if (c == s[j])
				{
					if (c <= 'z' && c >= 'a')
						r += c - 'a' + 1;
					else
						r += c - 'A' + 27;
					// cout << (char)c << endl;
					ok = true;
				}
			}
		}

		//	part 2

		if (x > (int) v.size() - 3 || x % 3)
			continue ;

		string	n = v[x + 1];
		string	nn = v[x + 2];

		cout << n << " - " << nn << endl;

		i = -1;
		ok = false;
		ok2 = false;
		while (++i < len && !(ok && ok2))
		{
			//string::iterator	it;
			size_t	it;
			
			ok = false;
			ok2 = false;

			c = s[i];
			it = n.find((char) c);
			// if (it != n.end())
			if (it ^ string::npos)
			{
				ok = true;
			}
			
			it = nn.find((char) c);
			
			// if (it != nn.end())
			if (it ^ string::npos)
			{
				ok2 = true;
			}
			if (ok && ok2)
			{
				cout << (char) c << endl;
				if (c <= 'z' && c >= 'a')
					r2 += c - 'a' + 1;
				else
					r2 += c - 'A' + 27;
			}
			cout << "r2: " << r2 << endl;
		}
	}
	cout << "Star 1: " << r << endl;
	cout << "Star 1: " << r2 << endl;
}
