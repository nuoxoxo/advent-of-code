/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

#include <iostream>
#include <sstream>
#include <vector>

int	count_single(std::vector<int>);
int	count_triple(std::vector<int>);

int	main(void)
{
	std::vector<int>	size;
	int			dep, single, triple;

	while (std::cin >> dep)	size.push_back(dep);
	single = count_single(size);
	triple = count_triple(size);
	std::cout << "Star 1: " << single << std::endl;
	std::cout << "Star 2: " << triple << std::endl;

	return (0);
}

int	count_triple(std::vector<int> dp)
{
	int	count, last3, curr3, i;

	last3 = dp[0] + dp[1] + dp[2];
	i = count = 0;
	while (++i < (int) dp.size() - 2)
	{
		curr3 = dp[i] + dp[i + 1] + dp[i + 2];
		if ( curr3 > last3 )	count++;
		last3 = curr3;
	}

	return (count);
}

int	count_single(std::vector<int> dp)
{
	int	count, i;

	count = i = 0;
	while (++i < (int) dp.size())
		if (dp[i] > dp[i - 1])	count++;

	return (count);
}
