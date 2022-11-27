#include "iostream"
#include "vector"
#include "cstdio" // sscanf
#include "algorithm" // minmax

using	namespace std;

int	main()
{
	string	s;
	int	l, w, h;
	int	r = 0;
	int	r2 = 0;

	while (cin >> s)
	{
		//	part 1

		std::sscanf(s.c_str(), "%dx%dx%d", & l, & w, & h);
		int	surf = l * w + w * h + h * l;
		int	side = minmax({l * w, w * h, h * l}).first;
		int	tmp = 2 * surf + side;
		r += tmp;

		//	part 2

		int	max = minmax({l, w, h}).second;
		int	peri = 2 * ((l + w + h) - max);
		int	tmp2 = l * w * h + peri;
		r2 += tmp2;

	}
	cout << "Star 1: " << r << endl;
	cout << "Star 2: " << r2 << endl;
}
