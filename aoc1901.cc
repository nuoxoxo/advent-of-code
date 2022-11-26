#include "iostream"

using	namespace std;

int	main()
{
	int	n;
	int	temp;
	int	r = 0;
	int	r2 = 0;

	while (cin >> n)
	{
		r += n / 3 - 2;
		while (n > -1)
		{
			temp = n / 3 - 2;
			if (temp < 1)
				break ;
			r2 += temp;
			n = temp;
		}
	}
	cout << "Star 1: " << r << endl;
	cout << "Star 2: " << r2 << endl;
}
