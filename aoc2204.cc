#include "iostream"
#include "vector"
#include "cstdio"

using	namespace std;

int	main()
{
	vector<string>	a;
	string		s;
	int		l, r, ll, rr, r1 = 0, r2 = 0;

	while (cin >> s)
	{
		sscanf(s.c_str(),"%d-%d,%d-%d",&l,&r,&ll,&rr);
		if ((l <= ll && r >= rr) || (ll <= l && rr >= r))
			r1++;		

		//	Part 2

		//if ( (r >= ll && rr > r) || (ll <= r && l > ll)) // buggy

		if (r >= ll && l <= rr)
		{
			// cout << s << endl;
			r2++;
		}
		
	}
	cout << "Star 1: " << r1 << endl;
	cout << "Star 2: " << r2 << endl;
}
