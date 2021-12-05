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
#include <vector>
#include <string>

//  DRIVE

int     tree(std::vector< std::string > x, int r, int d);

int     main(void)
{
        std::vector< std::string >  x;
        std::string s;
        int         slope, slopes;

        while (std::cin >> s)   x.push_back(s);
        slope = tree(x, 3, 1);
        slopes = slope;
        slopes *= tree(x, 1, 1) * tree(x, 5, 1) * tree(x, 7, 1) * tree(x, 1, 2);
        std::cout << "Star 1 : " << slope << std::endl;
        std::cout << "Star 2 : " << slopes << std::endl;
        
        return (0);
}

//

int     tree(std::vector< std::string > x, int r, int d)
{
        int     trees, i, j;

        trees = i = j = 0;
        while (i < (int) x.size())
        {
            if (x[i][j] == '#') trees++;
            if (j + r < (int)   x[i].length()) j += r;
            else    j = (j + r) % (int) x[i].length();
            i += d;
        }
        
        return (trees);
}
