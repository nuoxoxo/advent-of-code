#include "iostream"
#include "vector"

using	namespace std;

int	main()
{
	string		tmp;
	int		res;

	vector<int>	v;
	vector<int>	vv;
	int		n;
	int		i = 0;
	int		fq = 0;
	int		ok = 0;
	int		c;

	res = 0;
	while (cin >> tmp)
	{
		n = stoi(tmp);
		res += n;
		v.push_back(n);
	}
	n = 0;
	c = 0;
	while (!ok)
	{
		n += v[i];
		if (find(vv.begin(), vv.end(), n) != vv.end())
		{
			fq = n;
			ok = 1;
		}
		vv.push_back(n);
		++i;
		if (i == (int) v.size())
			i = 0;
		++c;
	}
	cout << "Star 1: " << res << endl;
	cout << "Star 2: " << fq << endl;
	cout << "(total steps taken: " << c << ")" << endl;
}
