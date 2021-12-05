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
#include <string>

long    decompress_omega(std::string s);
int     decompress_alpha(std::string s);

int     main(void)
{
        std::string s;
        long        len1;
        long        len2;        

        std::cin >> s;
        len1 = decompress_alpha(s);
        len2 = decompress_omega(s);
        
        std::cout << "Star 1 : " << len1 << std::endl;
        std::cout << "Star 2 : " << len2 << std::endl;
        return (0);
}

long    decompress_omega(std::string s)
{
        std::size_t L;
        std::size_t R;
        std::string sub;
        long        len;
        char        c;
        int         a;
        int         b;

        len = 0;
        L = 0;
        R = 0;
        if (s.find('(') == std::string::npos)
            return ((long) s.length());
        while (s.find('(') != std::string::npos)
        {
            L = s.find('(');
            R = s.find(')');
            if (R != std::string::npos)
            {
                std::stringstream ss(s.substr(L + 1, R - 1));
                ss >> a >> c >> b;
                //  debug
                //std::cout << a << ' ' << c << ' ' << b << std::endl;
                len += L;
                s = s.substr(R + 1);
                len += b * decompress_omega(s.substr(0, a));
                s = s.substr(a);
            }
        }
        return (len + (long) s.length());
}


int     decompress_alpha(std::string s)
{
        std::size_t L;
        std::size_t R;
        char        c;
        int         len;
        int         a;
        int         b;
        int         i;

        len = i = 0;
        while (s[i])
        {
            s = s.substr(i);
            L = s.find('(');
            if (L != std::string::npos)
            {
                R = s.find(')');
                if (R != std::string::npos)
                {
                    std::stringstream ss(s.substr(L + 1, R - 1));
                    ss >> a >> c >> b;
                    len += L + a * b;
                    i = R + a + 1;
                }
            }
            else
            {
                len += (int) s.length();
                break;
            }
        }
        return (len);
}
