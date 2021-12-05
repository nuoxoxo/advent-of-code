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
#include <utility>
#include <vector>

// std::pair (const first_type& a, const second_type& b); -> coordinates
// #include <utility>   // std::pair, std::make_pair

int if_exists(std::pair<int, int> pair, \
    std::vector< std::pair<int, int> > path);

int     main()
{
    std::vector< std::pair <int, int> > path_santa;
    std::vector< std::pair <int, int> > path_claus;
    int     step, x, y, a, b, c, d;
    char    buff;

    step = x = y = 0;
    a = b = 0;
    c = d = 0;
    path_santa.push_back(std::make_pair(x, y));
    path_claus.push_back(std::make_pair(x, y));
    while (std::cin >> buff)
    {
        if (buff == '>')
        {
            x++;
            if (step % 2)   a++;
            else            c++;
        }
        if (buff == '<')
        {
            x--;
            if (step % 2)   a--;
            else            c--;
        }
        if (buff == '^')
        {
            y++;
            if (step % 2)   b++;
            else            d++;
        }
        if (buff == 'v')
        {
            y--;
            if (step % 2)   b--;
            else            d--;
        }

        std::pair<int, int> pos_santa = std::make_pair(x, y);
        if (!if_exists(pos_santa, path_santa))
            path_santa.push_back(pos_santa);

        std::pair<int, int> pos_nick = std::make_pair(a, b);
        if (!if_exists(pos_nick, path_claus))
            path_claus.push_back(pos_nick);

        std::pair<int, int> pos_robo = std::make_pair(c, d);
        if (!if_exists(pos_robo, path_claus))
            path_claus.push_back(pos_robo);

        step++;
    }
    std::cout << path_santa.size() << '\n';
    std::cout << path_claus.size() << '\n';
}

//

int     if_exists(std::pair<int, int> pair, \
        std::vector< std::pair<int, int> > path)
{
        int     mark = 0;
        int     i = 0;

        while (i < (int) path.size())
        {
            if (pair == path[i])
                mark++;
            i++;
        }
        return (mark);
}
