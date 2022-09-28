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
#include "map"

using   namespace std;

int     brute_polymer(string, map<string, char>);
long    polymer(string, map<string, char>, int);
long    biggest_gap_in_map(map<char, long>);

int     main()
{
        map<string, long>::iterator it;
        map<string, char>           dict;
        map<string, long>           poly, temp;
        string                      s, init, duo, xx;
        long                        n, min, max, res10, res40, i;
        char                        c;
        int                         brute;

        //  parsing

        cin >> init;
        while (cin >> s >> xx >> c) dict[s] = c;

        //  solve

        brute = brute_polymer(init, dict);
        res10 = polymer(init, dict, 10);
        res40 = polymer(init, dict, 40);

        cout << "Star 1: " << brute << " (brute forced)\n--" << endl;
        cout << "Star 1: " << res10 << endl;
        cout << "Star 2: " << res40 << endl;

        return (0);
}

long    polymer(string init, map<string, char> dict, int N)
{
        map<string, long>::iterator it;
        map<string, long>           poly, temp;
        map<char, long>             chrs;
        string                      duo;
        long                        min, max;
        char                        c;
        int                         i;

        i = 0;
        while (++i < init.length())
        {
            duo = "";
            duo += init[i - 1];
            duo += init[i];
            poly[duo]++;
        }
        i = -1;
        while (++i < init.length()) chrs[init[i]]++;
        i = N + 1;
        while (--i)
        {
            if (!temp.empty())  temp.clear();
            it = poly.begin();
            while (it != poly.end())
            {
                duo = "";
                duo += it->first[0];
                duo += dict[ it->first ];
                temp[duo] += it->second;
                chrs[ dict[ it->first ] ] += it->second;
                duo = "";
                duo += dict[ it->first ];
                duo += it->first[1];
                temp[duo] += it->second;
                ++it;
            }
            poly = temp;
        }

        return (biggest_gap_in_map(chrs));
}

long    biggest_gap_in_map(map<char, long> chrs)
{
        map<char, long>::iterator   it;
        char                        c;
        long                        min, max;

        it = chrs.begin();
        max = 0;
        while (it != chrs.end())
        {
            if (max < it->second)
            {
                max = it->second;
                c = it->first;
            }
            it++;
        }
        min = max;
        it = chrs.begin();
        while (it != chrs.end())
        {
            if (min > it->second)
            {
                min = it->second;
                c = it->first;
            }
            it++;
        }

        return (max - min);
}

int     brute_polymer(string init, map<string, char> dict)
{
        string      tobe, duo;
        int         chrs[256] = {0}, i, n, min, max;
        char        c;

        n = 10 + 1;
        while (--n)
        {
            tobe = init[0];
            i = 0;
            while (++i < init.length())
            {
                duo = "";
                duo += init[i - 1];
                duo += init[i];
                tobe += dict[duo];
                tobe += init[i];
            }
            init = tobe;
        }
        i = -1;
        while (++i < init.length()) chrs[init[i]]++;
        i = -1;
        while (++i < init.length())
        {
            if (chrs[init[i]] > max)
            {
                max = chrs[init[i]];
                c = init[i];
            }
        }
        i = -1;
        min = max;
        while (++i < init.length())
        {
            if (init[i] && chrs[init[i]] < min)
            {
                min = chrs[init[i]];
                c = init[i];
            }
        }

        return (max - min);
}
