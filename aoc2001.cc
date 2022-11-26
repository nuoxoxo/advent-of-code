#include "iostream"
#include "vector"
#include "set"
#include "map"

using	namespace std;

int	main()
{
	vector<int>	a;
	set<int>	s;
	int		res = 0;
	int		n;

	while (cin >> n)
	{
		int	dif = 2020 - n;

		if (find(a.begin(), a.end(), dif) != a.end())
		{
			res = dif * n;
			// break ;
		}
		else
		{
			s.insert(n);
		}
		a.push_back(n);
	}

	map<int, pair<int, int>>		mp;
	map<int, pair<int, int>>::iterator	it;

	int	i = -1;
	int	res2 = 0;

	while (++i < (int) a.size() - 1)
	{
		int	j = i;

		while (++j < (int) a.size())
		{
			n = a[i] + a[j];
			mp.insert(pair<int, pair<int, int>>(2020 - n, {a[i], a[j]}));
		}
	}
	i = -1;
	while (++i < (int) a.size())
	{
		it = mp.find(a[i]);
		if (it != mp.end())
		{
			res2 = a[i] * it->second.first * it->second.second;
		}
	}
	cout << "Star 1: " << res << endl;
	cout << "Star 1: " << res2 << endl;
}
