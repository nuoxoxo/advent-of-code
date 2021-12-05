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

long    get_value(std::vector<std::string> inst, long a, long b);

int     main(void)
{
        std::vector<std::string>    instructions;
        std::string                 s;
        long                        release_1, release_2;

        while ( getline(std::cin, s) )  instructions.push_back(s);
        release_1 = get_value(instructions, 0, 0);
        release_2 = get_value(instructions, 1, 0);
        std::cout << "Star 1 : " << release_1 << std::endl;
        std::cout << "Star 2 : " << release_2 << std::endl;

        return (0);
}

//

long    get_value(std::vector<std::string> inst, long a, long b)
{
        std::string opcode, d;
        int         n, v, i;
        char        c;

        i = 0;
        while (1)
        {
            if ( i > inst.size() - 1 || i < 0 ) break;
            std::stringstream   ss(inst[i]);
            ss >> opcode;
            if (opcode == "jmp")   
            {
                ss >> n;
                i += n;
            }
            if (opcode == "hlf")
            {
                ss >> c;
                if (c == 'a')   a /= 2;
                if (c == 'b')   b /= 2;
                i++;
            }
            if (opcode == "tpl")
            {
                ss >> c;
                if (c == 'a')   a *= 3;
                if (c == 'b')   b *= 3;
                i++;
            }
            if (opcode == "inc")
            {
                ss >> c;
                if (c == 'a')   a++;
                if (c == 'b')   b++;
                i++;
            }
            if (opcode == "jie")
            {
                ss >> c >> d >> n;
                if (c == 'a')   v = a;
                if (c == 'b')   v = b;
                if (v % 2 == 0) i += n;
                else            i++;
            }
            if (opcode == "jio")
            {
                ss >> c >> d >> n;
                if (c == 'a')   v = a;
                if (c == 'b')   v = b;
                if (v == 1)     i += n;
                else            i++;
            }
            a = a > -1 ? a : 0;
            b = b > -1 ? b : 0;
        }
        return (b);
}
