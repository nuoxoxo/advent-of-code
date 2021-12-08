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

//  DRIVE

int     position_check(int cell, int i, int j);
int     algoL(int steps);
int     algoR(int steps);
int     algoU(int steps);
int     algoD(int steps);
int     termial(int n);

int     main(void)
{
        int     end = 289326;
        int     found, steps, d;
        
        found = 0;
        while (1)
        {
            d = 0;
            while (1)
            {
                steps = 1;
                while (algoL(steps) < end * 2 && algoR(steps) < end * 2 
                    && algoU(steps) < end * 2 && algoD(steps) < end * 2)
                {
                    if ((found = position_check(steps, end, d))) break;
                    steps++;
                }
                if (found)  break;
                d++;
            }
            if (found)  break;
        }
        std::cout << "Star 1 : " << steps + d << std::endl;
        
        return (0);
}

//

int     position_check(int steps, int i, int j)
{
        if (algoL(steps) == i + j || algoL(steps) == i - j || 
            algoR(steps) == i - j || algoR(steps) == i + j ||
            algoU(steps) == i + j || algoU(steps) == i - j ||
            algoD(steps) == i + j || algoD(steps) == i - j)
            return (1);
        return (0);
}
    
int     algoU(int steps)
{
        return (1 + 3 * steps + 8 * termial(steps - 1));
}

int     algoD(int steps)
{
        return (1 + 7 * steps + 8 * termial(steps - 1));
}

int     algoL(int steps)
{
        return (1 + 5 * steps + 8 * termial(steps - 1));
}

int     algoR(int steps)
{
        return (1 + steps + 8 * termial(steps - 1));
}

int     termial(int n)
{
        int     res = 0;
        int     i = n;

        while (i > 0)   res += i--;
        return (res);
}
