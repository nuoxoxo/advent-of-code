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
#include "vector"

std::string	find_rate(std::vector<std::string>);
std::string	flip_rate(std::string);
std::string	find_life(std::vector<std::string>, std::string, int);
char		find_extr(std::vector<std::string>, int, int);

int	main()
{
	std::vector<std::string>        diagno;
	std::string                     s, rate, oxy, co2;
	int                             consume, support;

	while (std::cin >> s)
		diagno.push_back(s);
	rate = find_rate(diagno);
	consume = stoi(rate, 0, 2) * stoi(flip_rate(rate), 0, 2);
	oxy = find_life(diagno, rate, 0);
	co2 = find_life(diagno, rate, 1);
	support = stoi(oxy, 0, 2) * stoi(co2, 0, 2);
	//
	std::cout << "Star 1: " << consume << std::endl;
	std::cout << "Star 2: " << support << std::endl;
}

//

std::string	find_life(std::vector<std::string> dx, std::string s, int opt)
{
	std::vector<std::string>	res = dx;
	int				len = (int) s.length();
	int				pos = -1, i;

	len = (int) s.length();
	res = dx;
	pos = -1;
	while (++pos < len)
	{
		std::vector<std::string>	temp;

		i = -1;
		while (++i < (int) res.size())
		{
			if (res[i][pos] == find_extr(res, pos, opt))
				temp.push_back(res[i]);
		}
		if (res.size() == 1)
			break;
		res = temp;
	}

	return (res[0]);
}

char	find_extr(std::vector<std::string> dx, int pos, int o)
{
	int	size, res, i;

	size = (int) dx.size();
	res = 0;
	i = -1;
	while (++i < size)
	{
		if (dx[i][pos] == '0')
			++res;
	}
	if (!o)
		return (res > size / 2 ? '0' : '1');
	return (res <= size / 2 ? '0' : '1');
}

std::string	find_rate(std::vector<std::string> dx)
{
	std::vector<int>	cons;
	std::string		rate;
	int			linecount, x, i;

	i = -1;
	while (++i < (int) dx[0].length())
		cons.push_back(dx[0][i] - '0');
	i = 0;
	while (++i < (int) dx.size())
	{
		x = -1;
		while (++x < (int) dx[i].length())
			cons[x] += dx[i][x] - '0';
	}
	linecount = (int) dx.size();
	i = -1;
	while (++i < (int) cons.size())
	{
		if (cons[i] > linecount / 2)
			rate += '1';
		else
			rate += '0';
	}

	return (rate);
}

std::string	flip_rate(std::string s)
{
	std::string	res;
	int		i;

	i = -1;
	while (++i < (int) s.length())
	{
		if (s[i] - '0')
			res += '0';
		else
			res += '1';
	}

	return (res);
}
