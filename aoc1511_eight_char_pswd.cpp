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

bool            check_8_chars(std::string s);
bool            check_asc(std::string s);
bool            check_oil(std::string s);
bool            check_dup(std::string s);
std::string     next_pswd(std::string s);

//  DRIVE

int     main(int argc, char **argv)
{
        int     counter;

        if (argc != 2)  return (1);
        std::string s = argv[1];
        counter = 0;
        while (counter < 2)
        {
            if (check_8_chars(s))
            {
                counter++;
                std::cout << "Star " << counter << " : "<< s << std::endl;
            }
            s = next_pswd(s);
        }

        return (0);
}

//

bool    check_8_chars(std::string s)
{
        if (check_dup(s) && check_oil(s) && check_asc(s))
            return (true);
        return (false);
}

std::string next_pswd(std::string s)
{
        int     last = (int) s.length() - 1;
        
        if (s[last] < 122)
        {
            if (s[last] == 104 || s[last] == 107 || s[last] == 110)
                s[last] += 2;
            else
                s[last] += 1;
            return (s);
        }
        else if (s[last] == 122)
        {
            int i = last;

            s[i] += 1;  ///  crucial line
            while (s[i] > 122)
            {
                s[i] = 97;
                if (s[i - 1] == 104 || s[i - 1] == 107 || s[i - 1] == 110)
                    s[i - 1] += 2;
                else    s[i - 1] += 1;
                i--;
            }
        }
        return (s);
}

bool    check_dup(std::string s)
{
        int     counter = 0;
        int     i = -1;
        char    c;

        while (++i < (int) s.length() - 1)
        {
            if (s[i] == s[i + 1])
            {
                counter++;
                c = s[i];
                break;
            }
        }
        i += 1;
        while (++i < (int) s.length() - 1)
        {
            if (c != s[i] && s[i] == s[i + 1])
            {
                counter++;
                break;
            }
        }
        if (counter == 2)   return (true);
        return (false);
}

bool    check_asc(std::string s)
{
        int     i = -1;

        while (++i < (int) s.length() - 2)
        {
            if (s[i] + 1 == s[i + 1] && s[i] + 2 == s[i + 2])
                return (true);
        }
        return (false);
}

bool    check_oil(std::string s)
{
        int     i = -1;

        while (s[++i])
        {
            if (s[i] == 105 || s[i] == 108 || s[i] == 111)
                return (false);
        }
        return (true);
}
