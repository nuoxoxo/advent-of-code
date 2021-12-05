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
        int     mass, gro, net, n;

        net = 0;
        gro = 0;
        while (std::cin >> n)
        {
            mass = n / 3 - 2;
            net += mass;
            while (mass > 0)
            {
                if (mass > 0) gro += mass;
                mass = mass / 3 - 2;
            }
        }
        std::cout << "Star 1 : " << net << std::endl;
        std::cout << "Star 2 : " << gro << std::endl;
}
