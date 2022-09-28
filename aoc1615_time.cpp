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
#include "vector"

using	namespace std;

int     find_pos(vector<pair<int, int>>);

int	main()
{
        vector<pair<int, int>>  E;
        string                  s;
        int                     t, x, y;

	while (getline(cin, s))
	{
            sscanf(s.c_str(), 
            "Disc #%d has %d positions; at time=0, it is at position %d.\n",
            &x, &x, &y);
            E.push_back(make_pair(x, y));
	}
        x = find_pos(E);
        E.push_back(make_pair(11, 0));
        y = find_pos(E);

        cout << "Star 1: " << x << endl;
        cout << "Star 2: " << y << endl;

	return 0 ;
}

int     find_pos(vector<pair<int, int>> E)
{
        bool    good;
        int     i, x;

        i = 0;
        while (++i)
        {
            x = -1;
            good = true;
            while (++x < E.size())
            {
                if ((E[x].second + i + x+1) % (E[x].first)) good = false;
            }
            if (good)   break;
        }
        return (i);
}
