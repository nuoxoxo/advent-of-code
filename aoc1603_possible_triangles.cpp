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

int     is_possible(int a, int b, int c);

//  DRIVE

int     main()
{
        std::vector< std::vector<int> > sq;
        int     count, a, b, c, i, j;

        count = 0;
        while (std::cin >> a >> b >> c)
        {
            std::vector<int>    line;
            if (is_possible(a, b, c))   count++;
            line.push_back(a);
            line.push_back(b);
            line.push_back(c);
            sq.push_back(line);
        }

        count = i = 0;
        while (i < (int) sq.size() - 2)
        {
            j = 0;
            while (j < 3)
            {
                if (is_possible(sq[i][j], sq[i + 1][j], sq[i + 2][j]))
                    count++;
                j++;
            }
            i += 3;
        }
        std::cout << "Star 1 : " << count << '\n';
        std::cout << "Star 2 : " << count << '\n';
}

//

int     is_possible(int a, int b, int c)
{
        if (a + b > c && a + c > b && c + b > a)
            return (1);
        return (0);
}
