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

int     find_missing(std::vector<int> a);
int     find_highest(std::vector<int> a);
int     convert_seat_id(std::string s);
void    sort_id(std::vector<int> a);

//  DRIVE

int     main(void)
{
        std::vector<int>    all_seats;
        std::string         s;
        int                 max, pid;

        max = 0;
        while (std::cin >> s)
        {
            pid = convert_seat_id(s);
            all_seats.push_back(pid);
        }
        max = find_highest(all_seats);
        pid = find_missing(all_seats);
        std::cout << "Star 1 : " << max << std::endl;
        std::cout << "Star 2 : " << pid << std::endl;

        return (0);
}

//

int     convert_seat_id(std::string s)
{
        int                 lo, hi, le, ri;
        std::stringstream   ss(s);
        char                c;
        
        lo = le = 0;
        hi = 127;
        ri = 7;
        
        while (ss >> c)
        {
            if (c == 'F')   hi -= (hi - lo + 1) / 2;
            if (c == 'B')   lo += (hi - lo + 1) / 2;
            if (c == 'L')   ri -= (ri - le + 1) / 2;
            if (c == 'R')   le += (ri - le + 1) / 2;
        }

        return (8 * lo + ri);
}

int     find_missing(std::vector<int> a)
{
        int     i = -1;
        
        //sort_id(a); // no need
        while (++i < (int) a.size() - 2)
        {
            if ((std::find(a.begin(), a.end(), 1 + a[i]) == a.end()) &&
                std::find(a.begin(), a.end(), 2 + a[i]) != a.end())
                break;
        }
        
        return (1 + a[i]);
}

int     find_highest(std::vector<int> a)
{
        int     max = 0;
        int     i = -1;

        while (++i < (int) a.size())
        {
            if (max < a[i]) max = a[i];
        }

        return (max);
}

void    sort_id(std::vector<int> a)
{
        int     flag, temp, i;

        i = 0;
        while (i < (int) a.size() - 1)
        {
            flag = 0;
            if (a[i] < a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                flag++;
            }
            if (!flag)  break;
        }
}
