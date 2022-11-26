#include "iostream"
#include "vector"

using	namespace std;

int	main()
{
	vector<int>	v;
	vector<int>	vv;
	int		n, i, r, rr;

	while (cin >> n)
		v.push_back(n);
	r = 0;
	i = 0;
	while (++i < (int) v.size())
	{
		if (v[i - 1] < v[i])
			++r;
		if (i > 1)
			vv.push_back(v[i - 1] + v[i - 2] + v[i]);
	}
	rr = 0;
	i = 0;
	while (++i < (int) vv.size())
	{
		if (vv[i - 1] < vv[i])
			++rr;
	}
	cout << "Star 1: " << r << endl;
	cout << "Star 2: " << rr << endl;
}
