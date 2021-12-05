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
#include <map>

std::pair<std::string, int> dst_to_win(std::map<std::string, std::vector<int> > reindeer, int time);
std::pair<std::string, int> pts_to_win(std::map<std::string, std::vector<int> > reindeer, int time);
void                        print_reindeer(std::map<std::string, std::vector<int> > reindeer);
int                         distance_covered(std::vector<int> vect, int time);

//  DRIVE

int     main(void)
{
        const int   time = 2503;
        int         n;
        std::string s;
        std::string temp;
        std::string name;
        std::pair<std::string, int> dst_winner, pts_winner;
        std::map< std::string, std::vector< int > > reindeer;

        while (std::getline(std::cin, s))
        {
            std::stringstream ss(s);
            ss >> name;
            std::vector < int > v;
            while (!ss.eof())
            {
                ss >> temp;
                if ( std::stringstream(temp) >> n ) v.push_back(n);
            }
            v.push_back(0); // 1 more lot for points
            reindeer.insert(std::make_pair(name, v));
        }
        //print_reindeer(reindeer); //  test
        dst_winner = dst_to_win(reindeer, time);
        pts_winner = pts_to_win(reindeer, time);
        std::cout << "Star 1 : " << dst_winner.second << " (" << dst_winner.first << ")" << std::endl;
        std::cout << "Star 2 : " << pts_winner.second << " (" << pts_winner.first << ")" << std::endl;

        return (0);
}

//

std::pair<std::string, int> pts_to_win(std::map<std::string, std::vector<int> > reindeer, int time)
{
        std::map<std::string, std::vector<int> >::iterator it;
        int         max, dst, i;
        std::string winner;

        while (time > 0)
        {
            std::vector< std::pair< std::string, int> >  tied;
            it = reindeer.begin();
            max = 0;
            while (it != reindeer.end())
            {
                dst = distance_covered(it->second, time);
                tied.push_back(std::make_pair(it->first, dst));
                if (max < dst)  max = dst;
                it++;
            }
            i = -1;
            while (++i < (int) tied.size())
                if (tied[i].second == max) reindeer[tied[i].first][3]++;
            time--;
        }
        max = 0;
        it = reindeer.begin();
        while (it != reindeer.end())
        {
            if (max < it->second[3])
            {
                winner = it->first;
                max = it->second[3];
            }
            it++;
        }
        return (std::make_pair(winner, max));
}

std::pair<std::string, int> dst_to_win(std::map<std::string, std::vector<int> > reindeer, int time)
{
        std::map<std::string, std::vector<int> >::iterator i;
        int         max, dst;
        std::string winner;

        max = 0;
        i = reindeer.begin();
        while (i != reindeer.end())
        {
            dst = distance_covered(i->second, time);
            if (max < dst)
            {
                max = dst;
                winner = i->first;
            }
            i++;
        }
        return (std::make_pair(winner, max));
}

int     distance_covered(std::vector<int> vect, int time)
{
        int     v, t, r, block, save;
        bool    run;

        run = false;
        save = time;
        v = vect[0];
        t = vect[1];
        r = vect[2];
        block = 0;
        while (1)
        {
            if (time - t <= 0)
            {
                run = true;
                break;
            }
            block += 1;
            time -= t;
            if (time - r <= 0)  break;
            time -= r;
        }
        if (!block) return (save * v);
        if (run)    return (t * v * block + time * v);
        else        return (t * v * block);
}

void    print_reindeer(std::map<std::string, std::vector<int> > reindeer)
{
        std::vector<int>::iterator v;
        std::map<std::string, std::vector<int> >::iterator m;

        m = reindeer.begin();
        while (m != reindeer.end())
        {
            std::cout << m->first << " : ";
            v = m->second.begin();
            while (v != m->second.end())
            {
                std::cout << *v << " ";
                v++;
            }
            std::cout << std::endl;
            m++;
        }
}
