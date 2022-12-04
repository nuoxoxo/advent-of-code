#include "h.hpp"
#include "cstdio"

int	main()
{
	vector<string>	a;
	string		s;
	int	l,r,ll,rr, res = 0, r2 = 0;

	while (cin >> s)
	{
		sscanf(s.c_str(),"%d-%d,%d-%d",&l,&r,&ll,&rr);
		if ((l <= ll && r >= rr) || (ll <= l && rr >= r))
			res++;		
		//if ( (r >= ll && rr > r) || (ll <= r && l > ll)) // buggy
		if (r >= ll && l <= rr)
		{
			// cout << s << endl;
			r2++;
		}
		
	}
	cout << res << endl;
	cout << r2 << endl;
}
