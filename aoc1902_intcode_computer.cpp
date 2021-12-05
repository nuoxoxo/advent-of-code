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

int     program(std::vector< int >  a);

//  DRIVE

int     main(void)
{
        std::vector< int >  intcode;
        std::string         s;
        int                 o;
        int                 noun, verb, flag, n;
        
        // Part 1

        std::cin >> s;
        std::stringstream   ss(s);
        while (ss >> n)
        {
            if (ss.peek() == ',')   ss.ignore();
            intcode.push_back(n);
        }
        intcode[1] = 12;
        intcode[2] = 2;
        o = program(intcode);

        // Part 2

        flag = noun = 0;
        while (noun < 100)
        {
            verb = noun;
            while (verb < 100)
            {
                intcode[1] = noun;
                intcode[2] = verb;
                if (program(intcode) == 19690720)
                {
                    flag++;
                    break;
                }
                verb++;
            }
            if (flag)   break;
            noun++;
        }

        std::cout << "Star 1 : " << o << std::endl;
        std::cout << "Star 2 : " << noun * 100 + verb << std::endl;
}

//

int     program(std::vector< int > a)
{
        int     i = 0;

        while (i < (int) a.size() - 4)
        {
            if (a[i] == 99) break;
            if (a[i] == 1)
                a[a[i + 3]] = a[a[i + 1]] + a[a[i + 2]];
            if (a[i] == 2)
                a[a[i + 3]] = a[a[i + 1]] * a[a[i + 2]];
            i += 4;
        }
        return (a[0]);
}
