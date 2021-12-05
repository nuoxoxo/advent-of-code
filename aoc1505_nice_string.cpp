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

int count_double(std::string s);
int count_vowel(std::string s);
int count_pair(std::string s);
int count_efe(std::string s);
int count_ab(std::string s);

int main()
{
    std::string  s;
    int     prop;
    int     good_1 = 0;
    int     good_2 = 0;

    while (std::cin >> s)
    {
        prop = 3;   
        if (count_double(s) > 0) prop--;
        if (count_vowel(s) > 2) prop--;
        if (count_ab(s) == 0)   prop--;
        if (prop == 0)  good_1++;

        prop = 2;
        if (count_pair(s) > 0)  prop--;
        if (count_efe(s) > 0)   prop--;
        if (prop == 0)  good_2++;
    }
    std::cout 
        << "Star 1 : " << good_1 << '\n'
        << "star 2 : " << good_2 << '\n';
}

//

int count_pair(std::string s)
{
    int i = 0;
    int j;
    int count = 0;

    while (s[i])
    {
        j = i + 2;
        while (s[j + 1])
        {
            if (s[i] == s[j] && s[i + 1] == s[j + 1])
                count++;
            j++;
        }
        i++;
    }
    return count;
}

int count_efe(std::string s)
{
    int i = 2;
    int count = 0;

    while (s[i])
    {
        if (s[i - 2] == s[i])   count++;
        i++;
    }
    return (count);
}

int count_vowel(std::string s)
{
    char    vowels [] = {'a', 'e', 'i', 'o', 'u'};
    int i = 0;
    int j;
    int count = 0;

    while (s[i])
    {
        j = 0;
        while (vowels[j])
        {
            if (vowels[j] == s[i])  count++;
            j++;
        }
        i++;
    }
    return (count);
}

int count_double(std::string s)
{
    int i = 1;
    int count = 0;

    while (s[i])
    {
        if (s[i - 1] == s[i])   count++;
        i++;
    }
    return (count);
}

int count_ab(std::string s)
{
    int i = 1;
    int count = 0;

    while (s[i])
    {
        if ((s[i] == 'b' && s[i - 1] == 'a') || \
            (s[i] == 'd' && s[i - 1] == 'c') || \
            (s[i] == 'q' && s[i - 1] == 'p') || \
            (s[i] == 'y' && s[i - 1] == 'x'))
            count++;
        i++;
    }
    return (count);
}
