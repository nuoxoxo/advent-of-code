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
#include <sstream>
#include <vector>

int     solve(std::vector< std::vector<char> > grid);

//  DRiVE

int     main(void)
{
        std::vector<std::vector<char> > grid;
        std::string direction, display, input, s;
        const int   W = 50;
        const int   T = 6;
        int         post, step, a, b, i, j;
        char        c;
        
        a = -1;
        while (++a < T)
        {
            std::vector<char>   row;
            b = -1;
            while (++b < W) row.push_back(32);
            grid.push_back(row);
        }
        while (std::getline(std::cin, input))
        {
            std::stringstream   ss(input);
            
            ss >> display;
            if (display == "rotate")
            {
                ss >> direction >> c >> c >> post >> s >> step;
                if (direction == "column")
                {
                    while (step--)
                    {
                        c = grid[T - 1][post];
                        i = T;
                        while (--i > -1)
                        {
                            if (!i) grid[i][post] = c;
                            else    grid[i][post] = grid[i - 1][post];
                        }
                    }
                }
                if (direction == "row")
                {
                    while (step--)
                    {
                        c = grid[post][W - 1];
                        i = W;
                        while (--i > -1)
                        {
                            if (!i) grid[post][i] = c;
                            else    grid[post][i] = grid[post][i - 1];
                        }
                    }
                }
            }
            if (display == "rect")
            {
                ss >> a;
                if (ss.peek() == 'x')   ss.ignore();
                ss >> b;
                i = -1;
                while (++i < b)
                {
                    j = -1;
                    while (++j < a) grid[i][j] = '#';
                }
            }
        }
        solve(grid);

        return (0);
}

//

int     solve(std::vector< std::vector<char> > grid)
{
        std::string empty = " ";
        int         count, x, y;
        
        std::cout << "Star 1 : " << std::endl;
        std::cout << "--" << std::endl;
        count = 0;
        x = -1;
        while (++x < (int) grid.size())
        {
            y = -1;
            while (++y < (int) grid[x].size())
            {
                std::cout << grid[x][y] << " ";
                if (grid[x][y] == '#')  count++;
            }
            std::cout << std::endl;
        }
        std::cout << "--" << std::endl;
        std::cout << "Star 2 : " << count << std::endl;

        return (count);
}
