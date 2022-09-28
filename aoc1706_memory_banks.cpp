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
#include "limits"
#include "map"

//  DRIVE

std::vector< int >  redistribute(std::vector<int> vec);
void                put_int_vect(std::vector<int> vec);

int     main()
{
        int seen_first, seen_again, i, found, count;
        std::map<std::vector<int>, int> cycles;
        std::vector<int>                banks;

        while (std::cin >> i)
            banks.push_back(i);
        cycles.insert(std::make_pair(banks, 0));
        put_int_vect(banks);
        found = count = 0;
        while (1)
        {
            banks = redistribute(banks);
            count++;
            put_int_vect(banks);
            if (cycles.find(banks) == cycles.end())
                cycles.insert(std::make_pair(banks, 0));
            else
            {
                if (!cycles[banks] && !found)
                {
                    seen_first = count;
                    cycles[banks]++;
                    found++;
                }
                else if (cycles[banks])
                {
                    seen_again = count;
                    break;
                }
            }
        }
        std::cout << "Star 1 : " << seen_first << std::endl;
        std::cout << "Star 2 : " << seen_again - seen_first << std::endl;

        return (0);
}

//

std::vector< int >  redistribute(std::vector<int> vec)
{
        int         chosen, len, max, i;
        int         value_to_give;

        len = (int) vec.size();
        max = std::numeric_limits<int>::min();
        i = -1;
        while (++i < len)
        {
            if (max < vec[i])
            {
                max = vec[i];
                chosen = i;
            }
        }
        if (max >= len - 1)
        {
            value_to_give = vec[chosen] / (len - 1);
            vec[chosen] %= (len - 1);
            i = -1;
            while (++i < len)
            {
                if ( i != chosen )  vec[i] += value_to_give;
            }
        }
        else
        {
            i = chosen;
            while (vec[chosen] > 0)
            {
                if ( i + 1 == len ) i = 0;
                else                i++;
                vec[chosen]--;
                vec[i]++;
            }
        }

        return (vec);
}

void    put_int_vect(std::vector<int> vec)
{
        int     i = -1;

        while (++i < (int) vec.size())
        {
            if (vec[i] < 10) std::cout << " ";
            std::cout << vec[i] << "  ";
        }
        std::cout << std::endl;
}
