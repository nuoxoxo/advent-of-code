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
/* ****************************************************************** nxu *** */

#include <iostream>

std::string look_and_say(std::string s);

int	main(int argc, char **argv)
{
	if (argc != 2)  return (0);

	std::string		line1;
	std::string		line2;
	std::string		s = argv[1];
	int         		t = 50;

	while (t)
	{
		line2 = look_and_say(s);
		if (t--)
			s = line2;
		if (t == 10)
			line1 = line2;
	}
	std::cout << "Star 1 : " << line1.length() << std::endl;
	std::cout << "Star 2 : " << line2.length() << std::endl;
	return (0);
}

std::string	look_and_say(std::string s)
{
	int		i;
	int		j;
	std::string	line;

	i = 0;
	while (s[i])
	{
		if (s[i + 1] && s[i] == s[i + 1])
		{
		    j = 1;
		    while (s[i] == s[i + j])
			j++;
		    line += j + 48;
		    line += s[i];
		    i += j;
		}
		else
		{
			line += '1';
			line += s[i];
			i += 1;
		}
	}
	return (line);
}
