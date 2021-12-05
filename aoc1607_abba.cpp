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

//  DRIVE

int     subset_abba_checker(std::string s, int L, int R);
int     subset_xxxx_checker(std::string s, int L, int R);
int     slen(std::string s);

int     main(void)
{
        int             count_TLS;
        int             count_SSL;
        std::string     s;
        
        count_SSL = count_TLS = 0;
        while (std::cin >> s)
        {
            std::vector<std::string> arr_outer;
            std::vector<std::string> arr_inner;
            int should_have_none;
            int should_have_some;
            int has_SSL;
            int i, j, x;

            i = j = 0;
            should_have_none = 0;
            should_have_some = 0;
            while (s[i])
            {
                j = i + 1;
                while (s[j])
                {
                    if (!s[j + 1])
                    {
                        if (subset_xxxx_checker(s, i, j))   should_have_none++;
                        if (subset_abba_checker(s, i, j))   should_have_some++;
                        x = i;
                        while (x + 1 < j)
                        {
                            if (s[x] == s[x + 2])
                            {
                                std::string temp;
                                temp += s[x];
                                temp += s[x + 1];
                                temp += s[x];
                                arr_outer.push_back(temp);
                            }
                            x++;
                        }
                        i = j;
                        break;
                    }
                    if (s[j + 1] == '[')
                    {
                        if (subset_xxxx_checker(s, i, j))   should_have_none++;
                        if (subset_abba_checker(s, i, j))   should_have_some++; 
                        x = i;
                        while (x + 1 < j)
                        {
                            if (s[x] == s[x + 2])
                            {
                                std::string temp;
                                temp += s[x];
                                temp += s[x + 1];
                                temp += s[x];
                                arr_outer.push_back(temp);
                            }
                            x++;
                        }
                        i = j + 2;
                    }
                    if (s[j + 1] == ']')
                    {
                        if (subset_abba_checker(s, i, j))   should_have_none++;
                        x = i;
                        while (x + 1 < j)
                        {
                            if (s[x] == s[x + 2])
                            {
                                std::string temp;
                                temp += s[x + 1];
                                temp += s[x];
                                temp += s[x + 1];
                                arr_inner.push_back(temp);
                            }
                            x++;
                        }
                        i = j + 2;
                    }
                    j++;
                }
                i++;
            }
            has_SSL = i = 0;
            while (i < (int) arr_outer.size() && !has_SSL)
            {
                j = 0;
                while (j < (int) arr_inner.size() && !has_SSL)
                {
                    if (arr_outer[i] == arr_inner[j])
                    {
                        has_SSL++;
                        break;
                    }
                    j++;
                }
                i++;
            }
            if (!should_have_none && should_have_some)  count_TLS++;
            if (has_SSL)    count_SSL++;
        }
        std::cout << "Star 1 : " << count_TLS << std::endl;
        std::cout << "Star 2 : " << count_SSL << std::endl;
        return (0);
}

//

int     subset_xxxx_checker(std::string s, int L, int R)
{
        if (R - L < 3)  return (0);
        while (L < R - 2)
        {
            if (s[L] == s[L + 1] && s[L] == s[L + 2] && s[L] == s[L + 3])
                return (1);
            L++;
        }
        return (0);
}

int     subset_abba_checker(std::string s, int L, int R)
{
        if (R - L < 3)  return (0);
        while (L < R - 2)
        {
            if (s[L] == s[L + 3] && s[L + 1] == s[L + 2])
                return (1);
            L++;
        }
        return (0);
}

int     slen(std::string s)
{
        int i = 0;

        while (s[i]) i++;
        return (i);
}
