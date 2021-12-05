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

//  DRIVE

void    print_int_array(std::vector< int > a);
int     jump_stranger(std::vector< int > a);
int     jump_strange(std::vector< int > a);

int     main(void)
{
        std::vector<int>    arr;
        int                 n;

        while (std::cin >> n)   arr.push_back(n);
        std::cout << "Star 1 : " << jump_strange(arr) << std::endl;
        std::cout << "Star 2 : " << jump_stranger(arr) << std::endl;

        return (0);
}

//

int     jump_stranger(std::vector<int> a)
{
        int     count, n, i;

        count = i = 0;
        while (1)
        {
            if (i > (int) a.size() - 1) break;
            if (a[i] == 0)  a[i] += 1;
            else
            {
                if (a[i] > 2)
                {
                    n = a[i];
                    a[i] += -1;
                    i += n;
                }
                else
                {
                    n = a[i];
                    a[i] += 1;
                    i += n;
                }
            }
            count++;
        }

        return (count);
}

int     jump_strange(std::vector<int> a)
{
        int     count, n, i;

        count = i = 0;
        while (1)
        {
            if (i > (int) a.size() - 1) break;
            if (a[i] == 0)  a[i] += 1;
            else
            {
                n = a[i];
                a[i] += 1;
                i += n;
            }
            count++;
        }

        return (count);
}

void    print_int_array(std::vector<int> a)
{
        int     i;

        i = 0;
        while (i < (int) a.size())  std::cout << a[i++] << " ";
        std::cout << std::endl;
}
