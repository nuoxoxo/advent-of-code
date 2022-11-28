#include "iostream"
#include "sstream"

using	namespace std;

int	main()
{
	string		s;
	int		r = 0;
	int		rr = 0;

	while (getline(cin, s) && !cin.eof())
	{
		int	a, b;
		char	c;
		string	pass;

		stringstream	ss(s);
		ss >> a;
		if (ss.peek() == '-')
			ss.ignore();
		ss >> b;
		ss >> c;
		if (ss.peek() == ':')
			ss.ignore();
		ss >> pass;

		int	i = -1;
		int	temp = 0;

		while (++i < (int) pass.length())
		{
			if (pass[i] == c)
				++temp;
		}
		if (temp < b + 1 && temp > a - 1)
			++r;

		// cout << s << endl;

		//	part 2

		--a;
		--b;
		if (c == pass[a] && c == pass[b])
			continue ;
		if (c == pass[a] || c == pass[b])
			++rr;
	}
	cout << "Star 1: " << r << endl;
	cout << "Star 2: " << rr << endl;
}
