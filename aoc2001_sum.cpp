/* ************************************************************************** */
/*                                                                            */
/*                            \\             /`/``                            */
/*                            ~\o o_       0 0\                               */
/*                            / \__)      (u  ); _  _                         */
/*                     / \/ \/  /           \  \/ \/ \                        */
/*                    /(   . . )            (         )\                      */
/*                   /  \_____/              \_______/  \                     */
/*                       []  []               [[] [[]    *.                   */
/*                       []] []]              [[] [[]                         */
/*                                                                            */
/* ****************************************************************** nuo *** */

#include "iostream"
#include "utility"
#include "vector"
#include "map"
#include "set"

int	main()
{
	std::map<int, std::pair<int, int>>::iterator	it;
	std::map<int, std::pair<int, int>>		m;
	std::vector<int>				v;
	std::set<int>					s;
	int						sum1, sum2, n, i, j;

	while (std::cin >> n)
	{
		i = 2020 - n;
		if (std::find(s.begin(), s.end(), i) == s.end())
			s.insert(n);
		else
			sum1 = n * i;
		v.push_back(n);
	}
	i = -1;
	while (++i < (int) v.size() - 1)
	{
		j = i;
		while (++j < (int) v.size())
		{
			n = v[i] + v[j];
			m.insert(std::pair<int, std::pair<int, int>>
				(n, std::make_pair(v[i], v[j])));
		}
	}
	i = -1;
	while (++i < (int) v.size())
	{
		it = m.find( 2020 - v[i] );
		if (it != m.end())
			sum2 = v[i] * it->second.first * it->second.second;
	}
	std::cout << "Star 1 : " << sum1 << std::endl;
	std::cout << "Star 2 : " << sum2 << std::endl;
}
