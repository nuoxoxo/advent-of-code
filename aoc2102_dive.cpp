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

int	main(void)
{
	int		A, H, Ha, D, Da, x;
	std::string	s;

	A = D = H = Da = Ha = 0;
	while (std::cin >> s >> x)
	{
		if (s[0] == 'f')
		{
			H += x;
			Ha += x;
			Da += x * A;
		}
		else
		{
			if (s[0] == 'u')
				x = - x;
			D += x;
			A += x;
		}
	}
	std::cout << "Star 1: " << H * D << std::endl;
	std::cout << "Star 2: " << Ha * Da << std::endl;

	return (0);
}
