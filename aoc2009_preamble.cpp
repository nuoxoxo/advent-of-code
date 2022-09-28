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


#include "algorithm"
#include "iostream"
#include "vector"

//  DRIVE

long    checkII(std::vector<long> v, long n);
bool    check(std::vector<long> v);

int     main()
{
        std::vector<long>::iterator i;
        std::vector<long>           v;
        long                        n;

        while ( std::cin >> n ) v.push_back(n);
        i = v.begin() + 25;
        while (++i != v.end() - 1)
        {
            std::vector< long > sub(i - 26, i);
            if (!check(sub)) break;
        }
        std::cout << "Star 1 : " << *(i - 1) << std::endl;
        std::cout << "Star 2 : " << checkII(v, *(i - 1)) << std::endl;
}

//

long    checkII(std::vector<long> v, long n)
{
        std::vector<long>::iterator i, j;
        long                        t;

        i = v.begin() - 1;
        while (*(++i) < n)
        {
            t = *i;
            j = i;
            while (*(++j) < n)
            {
                t += *j;
                if (t == n)
                    return (*std::min_element(i, j) + *std::max_element(i, j));
                if (t > n)  break;
            }
        }
        return (-1);
}

bool    check(std::vector<long> v)
{
        std::vector<long>::iterator i, j;
        bool    found = false;

        i = v.begin() - 1;
        while (++i != v.end() - 2)
        {
            j = i;
            while (++j != v.end() - 1)
                if ( *(v.end() - 1) == *i + *j) found = true;
        }
        if (!found) return (false);
        return (true);
}
