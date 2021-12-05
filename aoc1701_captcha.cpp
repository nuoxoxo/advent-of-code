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
        int         len;
        int         div;
        int         tt1;
        int         tt2;
        int         i;
        std::string s;

        std::cin >> s;
        len = (int) s.size();
        div = len / 2;
        tt1 = i = 0;
        while (1)
        {
            if (i != len - 1 && s[i] == s[i + 1])
                tt1 += s[i] - '0';
            if (i == len - 1 && s[i] == s[0])
            {
                tt1 += s[i] - '0';
                break;
            }
            i++;
        }
        tt2 = i = 0;
        while (i < len)
        {
            if (i + div < len && s[i] == s[i + div])
                tt2 += 2 * (s[i] - 48);
            i++;
        }
        std::cout << "Star 1 : " << tt1 << std::endl;
        std::cout << "Star 2 : " << tt2 << std::endl;
}
