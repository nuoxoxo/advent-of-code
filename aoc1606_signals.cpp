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
#include "utility" // pair + make_pair
#include "vector"
#include "limits" // std::numeric_limits<int>::max()

//  DRIVE

char    mfoc(std::vector< char > a); // most frequently occurring char
char    lfoc(std::vector< char > a); // least frequently occurring char
int     slen(std::string s);

int     main()
{
        std::vector< std::vector< char > >  arr;
        std::string                         err_corr_message;
        std::string                         original_message;
        std::string                         s;
        int                                 i;

        std::cin >> s;
        i = 0;
        while (i < slen(s))
        {
            std::vector< char > p;
            p.push_back(s[i++]);
            arr.push_back(p);
        }
        while (std::cin >> s)
        {
            i = 0;
            while (i < slen(s))
            {
                arr[i].push_back(s[i]);
                i++;
            }
        }
        i = 0;
        while (i < (int) arr.size())
        {
            err_corr_message += mfoc(arr[i]);
            original_message += lfoc(arr[i++]);
        }
        std::cout << "Star 1 : " << err_corr_message << std::endl;
        std::cout << "Star 2 : " << original_message << std::endl;
        return (0);
}

//

char    lfoc(std::vector<char> a)
{
        std::vector< std::pair<char, int> > v;
        int     found, min, len, i, j;
        char    res;

        len = (int) a.size();
        i = 0;
        while (i < len)
        {
            found = j = 0;
            while (j < (int) v.size())
            {
                if (v[j].first == a[i])
                {
                    v[j].second++;
                    found++;
                    break;
                }
                j++;
            }
            if (!found)
            {
                std::pair<char, int> p = std::make_pair(a[i], 0);
                v.push_back(p);
            }
            i++;
        }
        min = std::numeric_limits<int>::max();
        i = 0;
        while (i < (int) v.size())
        {
            if (min > v[i].second)
            {
                min = v[i].second;
                res = v[i].first;
            }
            i++;
        }
        return (res);
}

char    mfoc(std::vector<char> a)
{
        std::vector< std::pair<char, int> > v;
        int     found, max, len, i, j;
        char    res;

        len = (int) a.size();
        i = 0;
        while (i < len)
        {
            found = j = 0;
            while (j < (int) v.size())
            {
                if (v[j].first == a[i])
                {
                    v[j].second++;
                    found++;
                    break;
                }
                j++;
            }
            if (!found)
            {
                std::pair<char, int> p = std::make_pair(a[i], 0);
                v.push_back(p);
            }
            i++;
        }
        max = i = 0;
        while (i < (int) v.size())
        {
            if (max < v[i].second)
            {
                max = v[i].second;
                res = v[i].first;
            }
            i++;
        }
        return (res);
}

int     slen(std::string s)
{
        int i = 0;

        while(s[i]) i++;
        return (i);
}
