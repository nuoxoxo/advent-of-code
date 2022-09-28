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
#include "vector"
#include "map"

using   namespace std;

void    show_baseline(map<int, long> life);
void    show_lifesize(map<int, long> life);
long    mapsum(map<int, long>);

//      dp part 1 + 2

int     main()
{
        map<int, long>  life;
        string          s;
        long            pop80, pop256;
        int             diff, i, date, days;

        cin >> s;
        stringstream    ss(s);
        while (getline(ss, s, ',')) life[stoi(s)]++;
        show_lifesize(life);
        show_baseline(life);
        date = 0;
        days = 256;
        while (++date < days)
        {
            i = date % 9;

            //  i is a weekday of a 9-day week
            //  a new-born needs 9 days to become a breeder
            //  ie. every 8 days
            //  grown-ups need 7 days, ie. every 6 days

            diff = i < 2 ? i + 7 : i - 2;
            life[diff] += life[i];
            if (date + 1 == 80) pop80 = mapsum(life);
        }
        pop256 = mapsum(life);

        cout << "Star 1: " << pop80 << endl;
        cout << "Star 2: " << pop256 << endl;

        return (0);
}

long    mapsum(map<int, long> mp)
{
        long    size = 0;
        int     i = -1;

        while (++i < 9) size += mp[i];
        return (size);
}

void    show_baseline(map<int, long> life)
{
        int     i = -1;

        cout << "--\n";
        while (++i < 9) cout << i << ":" << life[i] << "  ";
        cout << "\n--" << endl;
}

void    show_lifesize(map<int, long> life)
{
        cout << "--" << endl;
        cout << "lifesize: ";
        cout << life.size() << endl;
}

//      deprecated part 1

/*

void    debug(vector<int> vc);

int     main()
{
        vector<int>     life;
        string          s;
        int             i, days = 80;

        cin >> s;
        stringstream    ss(s);
        while (getline(ss, s, ',')) life.push_back(stoi(s));
        days++;
        while (--days)
        {
            i = -1;
            while (++i < life.size())
            {
                if (life[i])
                    life[i]--;
                else
                {
                    life[i] = 6;
                    life.push_back(9);
                }
            }
        }
        cout << "Star 1: " << life.size() << endl;

        return (O);
}

void    debug(vector<int> vc)
{
        int     i = -1;

        while (++i < vc.size()) cout << vc[i] << " ";
}

*/
