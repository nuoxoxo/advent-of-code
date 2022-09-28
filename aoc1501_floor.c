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

#include "unistd.h"
#include "stdio.h"

int	main()
{
	int		count;
	int		posit;
	int		i;
	char	c;

	i = 0;
	count = 0;
	posit = 0;
	while (read(STDIN_FILENO, &c, 1))
	{
		if (count == -1 && !posit)
		{
			posit = i;
		}
		if (c == '(')
		{
			++count;
		}
		if (c == ')')
		{
			--count;
		}
		++i;
	}
	printf("Star 1 : %i \n", count);
	printf("Star 2 : %i \n", posit);
	return (0);
}
