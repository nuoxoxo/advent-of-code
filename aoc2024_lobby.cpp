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
#include "set"
#include "vector"

using   namespace std;

int     main()
{
        set<pair<int, int>> L;
        pair<int, int>      p;
        string              s;
        int                 i, x, y, part1, part2;

        // part 1 solved while parsing

        while (cin >> s)
        {
            i = x = y = 0;
            while (i < s.length())
            {
                if (s[i] == 'n')
                {
                    if (s[i + 1] == 'e')
                    {
                        x += 1;
                        y -= 1;
                    }
                    if (s[i + 1] == 'w')
                    {
                        x -= 1;
                        y -= 1;
                    }
                }
                else if (s[i] == 's')
                {
                    if (s[i + 1] == 'e')
                    {
                        x += 1;
                        y += 1;
                    }
                    if (s[i + 1] == 'w')
                    {
                        x -= 1;
                        y += 1;
                    }
                }
                else if ( s[i] == 'e' ) x += 2;
                else if ( s[i] == 'w' ) x -= 2;
                if (s[i] == 'e' || s[i] == 'w') ++i;
                else if ( s[i] == 'n' || s[i] == 's' )  i += 2;
            }
            p = make_pair(x, y);
            if ( L.find(p) != L.end() ) L.erase(p);
            else                        L.insert(p);
        }
        part1 = L.size();

        // part 2

        set<pair<int, int>>::iterator   it;
        vector<int> dx = {-2, -1, -1,  1, 1, 2};
        vector<int> dy = { 0, -1,  1, -1, 1, 0};
        int         D = 100 + 1, n;

        while (--D)
        {
            set<pair<int, int>> ALL;
            set<pair<int, int>> temp;

            it = L.begin();
            while (it != L.end())
            {
                ALL.insert(make_pair(it->first, it->second));
                i = -1;
                while (++i < 6)
                {
                    p = make_pair( it->first + dx[i], it->second + dy[i] );
                    ALL.insert(p);
                }
                it ++ ;
            }
            it = ALL.begin();
            while (it != ALL.end())
            {
                n = 0;
                i = -1;
                while (++i < 6)
                {
                    p = make_pair( it->first + dx[i], it->second + dy[i] );
                    if ( L.find(p) != L.end() ) n ++ ;
                }
                p = make_pair( it->first, it->second );
                if ((L.find(p) != L.end() && (n < 3 && n > 0)) ||
                    (L.find(p) == L.end() && n == 2))
                    temp.insert(p);
                it ++ ;
            }
            L = temp;
            if (D - 1 > 89 || (D - 1) % 10 == 0)
                cout << "Day " << 100 - D + 1 << ": " << L.size() << endl;
            if (D == 1 || D == 89) cout << "--\n";
        }
        part2 = L.size();

        cout << "Star 1: " << part1 << endl;
        cout << "Star 2: " << part2 << endl;

        return (0);
}
