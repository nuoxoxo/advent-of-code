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
#include "algorithm"
#include "sstream"
#include "vector"

int     strcmp_soft(std::string s1, std::string s2);
int     strcmp_hard(std::string s1, std::string s2);
int     phrcmp_soft(std::vector<std::string> pp);
int     phrcmp_hard(std::vector<std::string> pp);

//  DRIVE

int     main()
{
        std::string s;
        int         count_soft;
        int         count_hard;                

        count_soft = count_hard = 0;
        
        while (std::getline(std::cin, s))   // line intact incl. spaces
        //while (std::cin >> s)             // words splitted by spaces
        {
            std::vector<std::string>    pp;
            std::stringstream           ss(s);
            std::string                 temp;
            while (ss >> temp)
            {
                pp.push_back(temp);
            }
            if (phrcmp_soft(pp)) count_soft++;
            if (phrcmp_hard(pp))  count_hard++;
        }
        std::cout << "Star 1 : " << count_soft << std::endl;
        std::cout << "Star 2 : " << count_hard << std::endl;
}

//

int     phrcmp_hard(std::vector<std::string> pp)
{
        int d;

        for (int i = 0; i < (int) pp.size() - 1; i++)
        {
            for (int j = i + 1; j < (int) pp.size(); j++)
            {
                d = strcmp_hard(pp[i], pp[j]);
                if (!d) return (0);
            }
        }
        return (1);
}

int     phrcmp_soft(std::vector<std::string> pp)
{
        int d;

        for (int i = 0; i < (int) pp.size() - 1; i++)
        {
            for (int j = i + 1; j < (int) pp.size(); j++)
            {
                d = strcmp_soft(pp[i], pp[j]);
                if (!d) return (0);
            }
        }
        return (1);
}

int     strcmp_hard(std::string s1, std::string s2)
{
        int len1, len2, i;

        if (!strcmp_soft(s1, s2))   return (0);
        len1 = i = 0;
        while (s1[i])
        {
            len1++;
            i++;
        }
        len2 = i = 0;
        while (s2[i])
        {
            len2++;
            i++;
        }
        if (len1 != len2)   return (1);
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (!strcmp_soft(s1, s2))   return (0);
        return (1);
}

int     strcmp_soft(std::string s1, std::string s2)
{
        int i = 0;

        while (s1[i] && s2[i] && s1[i] == s2[i])
            i++;
        return (s1[i] - s2[i]);
}
