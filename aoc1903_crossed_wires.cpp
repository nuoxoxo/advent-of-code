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
#include <limits>

void    put_pos(std::pair<int, int> pair);
int     manhattan(std::pair<int, int> pair);
int     if_exists(std::pair<int, int> pair, \
        std::vector<std::pair<int, int> >path);

// DRIVE

int main()
{
    int                                 fewest_steps;
    int                                 shortest_md;
    int                                 left, right;
    int                                 distance;
    int                                 n, x, y;
    char                                c;
    std::string                         wet, dry;
    std::string                         opcode;
    std::vector< std::pair<int, int> >  patha;
    std::vector< std::pair<int, int> >  patho;
    std::vector< std::pair<int, int> >  meet;

    // Part 1

    std::cin >> wet >> dry;
    std::stringstream   sw(wet);
    std::stringstream   sd(dry);
    x = y = 0;
    while (std::getline(sw, opcode, ','))
    {
        std::stringstream  op(opcode);
        op >> c >> n;
        if (c == 'U')
        {
            for (int i = y; i < y + n; i++)
            {
                std::pair<int, int> pos = std::make_pair(x, i);
                patha.push_back(pos);
            }
            y += n;
        }
        if (c == 'D')
        {
            for (int i = y; i > y - n; i--)
            {
                std::pair<int, int> pos = std::make_pair(x, i);
                patha.push_back(pos);
            }
            y -= n;
        }
        if (c == 'L')
        {
            for (int i = x; i > x - n; i--)
            {
                std::pair<int, int> pos = std::make_pair(i, y);
                patha.push_back(pos);
            }
            x -= n;
        }
        if (c == 'R')
        {
            for (int i = x; i < x + n; i++)
            {
                std::pair<int, int> pos = std::make_pair(i, y);
                patha.push_back(pos);
            }
            x += n;
        }
    }
    
    x = y = 0;
    while (std::getline(sd, opcode, ','))
    {
        std::stringstream   op(opcode);
        op >> c >> n;
        if (c == 'U')
        {
            for (int i = y; i < y + n; i++)
            {
                std::pair<int, int> pos = std::make_pair(x, i);
                patho.push_back(pos);
                if (if_exists(pos, patha))
                    meet.push_back(pos);
            }
            y += n;
        }
        if (c == 'D')
        {
            for (int i = y; i > y - n; i--)
            {
                std::pair<int, int> pos = std::make_pair(x, i);
                patho.push_back(pos);
                if (if_exists(pos, patha))
                    meet.push_back(pos);
            }
            y -= n;
        }
        if (c == 'L')
        {
            for (int i = x; i > x - n; i--)
            {
                std::pair<int, int> pos = std::make_pair(i, y);
                patho.push_back(pos);
                if (if_exists(pos, patha))
                    meet.push_back(pos);
            }
            x -= n;
        }
        if (c == 'R')
        {
            for (int i = x; i < x + n; i++)
            {
                std::pair<int, int> pos = std::make_pair(i, y);
                patho.push_back(pos);
                if (if_exists(pos, patha))
                    meet.push_back(pos);
            }
            x += n;
        }
    }

    shortest_md = std::numeric_limits<int>::max();
    
    for (int i = 1; i < (int) meet.size(); i++)
    {
        distance = manhattan(meet[i]);
        if (shortest_md > distance)    shortest_md = distance;
    }

    // Part 2

    fewest_steps = std::numeric_limits<int>::max();
    left = right = 0; 
    for (int i = 1; i < (int) meet.size(); i++)
    {
        for (int j = 0; j < (int) patha.size(); j++)
        {
            if (meet[i] == patha[j])    left = j;
            //put_pos(patha[j]);
        }
        for (int k = 0; k < (int) patho.size(); k++)
        {
            if (meet[i] == patho[k])    right = k;
            //put_pos(patho[k]);
        }
        if (fewest_steps > right + left)
            fewest_steps = right + left;
    }
    
    std::cout 
        << "Star 1 : " << shortest_md << '\n'
        << "Star 2 : " << fewest_steps << '\n';
}

//

int     manhattan(std::pair<int, int> p)
{
        int f, s;
    
        f = p.first;
        if (f < 0)  f = -f;
        s = p.second;
        if (s < 0)  s = -s;

        return (s + f);
}

int     if_exists(std::pair<int, int> pair, \
        std::vector< std::pair<int, int> > path)
{
        if (std::find(path.begin(), path.end(), pair) != path.end())
            return 1;
        return 0;
}

void    put_pos(std::pair<int, int> pair)
{
        std::cout << "X : " << pair.first << " Y : " << pair.second << std::endl;
}
