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

int     main()
{
        int         count_1, count_2, i, n, a, b;
        char        c;
        std::string temp;
        std::string s;

        count_1 = count_2 = 0;
        while (std::getline(std::cin, temp))
        {
            std::stringstream ss(temp);
            ss >> a;
            if (ss.peek() == '-')   ss.ignore();
            ss >> b;
            ss >> c;
            if (ss.peek() == ':')   ss.ignore();
            ss >> s;
            n = i = 0;
            while (s[i])
            {
                if (c == s[i])  n++;
                i++;
            }
            if (n <= b && n >= a)   count_1++;
            a--;
            b--;
            if (s[a] && s[b])
            {
                if (c == s[a] && c == s[b])         continue;
                else if (c == s[a] || c == s[b])    count_2++;
            }
        }
        std::cout << "Star 1 : " << count_1 << std::endl;
        std::cout << "Star 2 : " << count_2 << std::endl;
        
        return (0);
}
