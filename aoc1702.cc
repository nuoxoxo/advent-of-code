#include "header.hpp"

int	main()
{
	string	s;
	int	r = 0;
	int	rr = 0;

	vector<vector<int>>	aa;

	while (getline(cin, s))
	{
		stringstream	ss(s);
		vector<int>	a;
		int		n;

		while (ss >> n)
		{
			a.push_back(n);
		}
		r += *max_element(a.begin(), a.end()) -
			*min_element(a.begin(), a.end());

		aa.push_back(a);
		
	}
	for (vector<int> b : aa)
	{
		int	i, j;

		sort(b.begin(), b.end());
		i = -1;
		while (++i < (int) b.size())
		{
			j = i;
			while (++j < (int) b.size())
			{
				if (j ^ i && b[j] % b[i] == 0)
				{
					rr += b[j] / b[i];
				}
			}
		}
	}
	cout << "Star 1: " << r << endl;
	cout << "Star 2: " << rr << endl;
}
