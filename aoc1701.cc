#include "iostream"

using	namespace std;

int	main()
{
	string		s;
	int		i;
	int		end, tt = 0;
	int		half, t2 = 0;

	cin >> s;
	end = s.length() - 1;
	i = 0;
	while (1)
	{
		if (i == end && s[0] == s[0])
		{
			tt += s[i] - '0';
			break ;
		}
		if (i ^ end && s[i + 1] == s[i])
		{
			tt += s[i] - '0';
		}
		++i;
	}
	i = -1;
	half = s.length() / 2;
	while (++i < half)
	{
		if (i + half <= end && s[i] == s[i + half])
		{
			t2 += (s[i] - '0') * 2;
		}
	}
	cout << "Star 1: " << tt << endl;
	cout << "Star 2: " << t2 << endl;
}

