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
#include <utility>
#include <vector>

std::pair<long, long>   score(std::vector< std::vector<int> > recipe);
void                    print(std::vector< std::vector<int> > recipe);

//  DRIVE

int     main(void)
{
        std::vector< std::vector<int> > recipe;
        std::pair<long, long>           result;
        std::string                     t, s;
        int                             n;

        while (getline(std::cin, s))
        {
            std::stringstream   ss(s);
            std::vector< int >  v;

            std::cout << s << std::endl;
            while (!ss.eof())
            {
                ss >> t;
                if (std::stringstream(t) >> n)  v.push_back(n);
            }
            recipe.push_back(v);
        }
        print(recipe);
        result = score(recipe);
        std::cout << "Star 1 : " << result.first << std::endl;
        std::cout << "Star 2 : " << result.second << std::endl;

        return (0);
}

//

std::pair< long, long > score(std::vector< std::vector<int> > r)
{
        std::pair< long, long > res;
        long    temp, capa, dura, flav, text, calo, max, mac;

        max = 0;
        for (int a = -1; a < 101; ++a)
            for (int b = -1; b < 101 - a; ++b)
                for (int c = -1; c < 101 - a - b; ++c)
                    for (int d = -1; d < 101 - a - b - c; ++d)
                        if (a + b + c + d == 100)
                        {
                            capa = a * r[0][0] + b * r[1][0] + c * r[2][0] + d * r[3][0];
                            dura = a * r[0][1] + b * r[1][1] + c * r[2][1] + d * r[3][1];
                            flav = a * r[0][2] + b * r[1][2] + c * r[2][2] + d * r[3][2];
                            text = a * r[0][3] + b * r[1][3] + c * r[2][3] + d * r[3][3];
                            calo = a * r[0][4] + b * r[1][4] + c * r[2][4] + d * r[3][4];
                            if ( capa < 0 || dura < 0 || flav < 0 || text < 0 ) break;
                            temp = capa * dura * flav * text;
                            if (calo == 500 && mac < temp)  mac = temp;
                            if (max < temp) max = temp;
                        }
        res = std::make_pair(max, mac);
        return (res);
}

void    print(std::vector< std::vector<int> > recipe)
{
        for (int i = 0; i < (int) recipe.size(); i++)
        {
            for (int j = 0; j < (int) recipe[i].size(); j++)
                std::cout << recipe[i][j] << " ";
            std::cout << std::endl;
        }
}
