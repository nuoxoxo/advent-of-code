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

int     main(void)
{
        int     flo, pos, i;
        char    c;

        flo = pos = i = 0;
        while (std::cin >> c)
        {
            if (flo == -1 && pos == 0)  pos = i;
            if (c == '(')               flo++;
            if (c == ')')               flo--;
            i++;
        }

        std::cout << "Star 1 : " << flo << std::endl;
        std::cout << "Star 2 : " << pos << std::endl;

        return (0);
}
