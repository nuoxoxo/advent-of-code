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

int     if_exists(std::pair<int, int> pair, \
        std::vector< std::pair<int, int> > path);

int     main()
{
        std::vector< std::pair <int, int> > path;
        std::pair<int, int>                 crossed;
        std::string                         src;
        int                                 heading, counter, been, x, y;

        heading = counter = x = y = 0;
        while (std::cin >> src)
        {
            std::stringstream   ss(src);
            char                c;
            int                 d;
            
            ss >> c >> d;
            if (c == 'L')       heading -= 1;
            else                heading += 1;
            if (heading > 4)    heading = 1;
            if (heading < 1)    heading = 4;
            if (heading == 1)
            {
                if (!counter)
                {
                    for (int i = x; i < x + d; i++)
                    {
                        std::pair<int, int> pos = std::make_pair(i, y);
                        been = if_exists(pos, path);
                        if (!been)  path.push_back(pos);
                        else
                        {
                            crossed = pos;
                            counter++;
                        }
                    }
                }
                x += d;
            }
            if (heading == 2)
            {
                if (!counter)
                {
                    for (int i = y; i > y - d; i--)
                    {
                        std::pair<int, int> pos = std::make_pair(x, i);
                        been = if_exists(pos, path);
                        if (!been)  path.push_back(pos);
                        else
                        {
                            crossed = pos;
                            counter++;
                        }
                    }   
                }
                y -= d;
            }
            if (heading == 3)
            {
                if (!counter)
                {
                    for (int i = x; i > x - d; i--)
                    {
                        std::pair<int, int> pos = std::make_pair(i, y);
                        been = if_exists(pos, path);
                        if (!been)  path.push_back(pos);
                        else
                        {
                            crossed = pos;
                            counter++;
                        }
                    }
                }
                x -= d;
            }
            if (heading == 4)
            {
                if (!counter)
                {
                    for (int i = y; i < y + d; i++)
                    {
                        std::pair<int, int> pos = std::make_pair(x, i);
                        been = if_exists(pos, path);
                        if (!been)  path.push_back(pos);
                        else
                        {
                            crossed = pos;
                            counter++;
                        }
                    }
                }
                y += d;
            }
        }
        if (x < 0)  x = -x;
        if (y < 0)  y = -y;
        if (crossed.first < 0)  crossed.first *= -1;
        if (crossed.second < 0) crossed.second *= -1;
        
        std::cout 
            << "Star 1 : " << x + y << '\n' 
            << "Star 2 : " << crossed.first + crossed.second << '\n';
}

int     if_exists(std::pair<int, int> pair, \
        std::vector< std::pair<int, int> > path)
{
        if (std::find(path.begin(), path.end(), pair) != path.end())
            return 1;
        return 0;
}
