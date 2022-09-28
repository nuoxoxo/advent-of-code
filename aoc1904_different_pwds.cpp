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
#include "sstream"

//  DRIVE

int     is_increased(std::string s);
int     has_repeat(std::string s);
int     has_pair(std::string s);

int     main(int argc, char **argv)
{
        int     count_strict, count_lazy, a, b;
        
        if (argc != 2)  return (1);
        std::stringstream   ss(argv[1]);
        ss >> a >> b;
        b = 1 - b;
        count_strict = 0;
        count_lazy = 0;
        while (a < b)
        {
            std::stringstream   ss;
            std::string         s;
            ss << a;
            ss >> s;
            if (has_repeat(s) && is_increased(s))
            {
                count_lazy++;
                if (has_pair(s))    count_strict++;
            }
            a++;
        }
        std::cout << "Star 1 : " << count_lazy << std::endl;
        std::cout << "Star 2 : " << count_strict << std::endl;

        return (0);
}

//

int     has_pair(std::string s)
{
        int     count, i, j;

        i = 0;
        while (s[i])
        {
            count = j = 0;
            while (s[j])
            {
                if (s[i] == s[j++]) count++;
            }
            if (count == 2) return (1);
            i++;
        }
        return (0);
}

int     has_repeat(std::string s)
{
        int     i = 0;

        while (s[i + 1])
        {
            if (s[i + 1] == s[i])   return (1);
            i++;
        }
        return (0);
}

int     is_increased(std::string s)
{
        int     i = 0;

        while (s[i + 1])
        {
            if (s[i] > s[i + 1])    return (0);
            i++;
        }
        return (1);
}
