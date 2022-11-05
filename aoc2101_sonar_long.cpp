#include <iostream>
#include <vector>

using	namespace std;

int	single(vector<int>);
int	triple(vector<int>);

int	main(void)
{
	vector<int>	dp;
	int		d, r1, r2;

	while (std::cin >> d)
		dp.push_back(d);
	r1 = single(dp);
	r2 = triple(dp);
	cout << "Star 1: " << r1 << endl;
	cout << "Star 2: " << r2 << endl;
}

//

int	triple(std::vector<int> dp)
{
	int	count;
	int	last3;
	int	curr3;
	int	i;

	last3 = dp[0] + dp[1] + dp[2];
	count = 0;
	i = 0;
	while (++i < (int) dp.size() - 2)
	{
		curr3 = dp[i] + dp[i + 1] + dp[i + 2];
		if (curr3 > last3)
			++count;
		last3 = curr3;
	}

	return (count);
}

int	single(std::vector<int> dp)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (++i < (int) dp.size())
		if (dp[i] > dp[i - 1])
			++count;
	return (count);
}
