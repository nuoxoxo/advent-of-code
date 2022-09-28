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
#include "set"

using   namespace std;

void    DFS(vector"string", set<pair<int, int>>&, int, int, char);
bool    isLP(vector"string", int, int);
void    view_grid(vector"string" bsn);

int     main()
{
        vector<pair<int, int>>  lopt;
        vector"string"          grid;
        vector<int>             size;
        set<pair<int, int>>     been;
        pair<int, int>          p;
        string                  s;
        int                     risk, i, j, big3;

        while (cin >> s)    grid.push_back(s);
        risk = 0;
        i = -1;
        while (++i < grid.size())
        {
            j = -1;
            while (++j < grid[0].length())
            {
                if (isLP(grid, i, j))
                {
                    risk += grid[i][j] + 1 - '0';       // Part 1
                    lopt.push_back(make_pair(i, j));    // Part 2
                }
            }
        }
        i = -1;
        while (++i < lopt.size())
        {
            p = lopt[i];
            if (been.size())  been.clear();
            DFS(grid, been, p.first, p.second, grid[p.first][p.second]);
            size.push_back(been.size());
        }
        sort(size.rbegin(), size.rend());
        big3 = size[0] * size[1] * size[2];

        view_grid(grid);
        cout << "Star 1: " << risk << endl;
        cout << "Star 2: " << big3 << endl;

        return (0);
}

void    DFS(vector"string" g, set<pair<int, int>>& b, int x, int y, char prev)
{
        pair<char, char>    p;
        int                 i, rend, bend; // right end, bottom end

        rend = g[0].length() - 1;
        bend = g.size() - 1;
        p = make_pair(x, y);
        if (b.find(p) != b.end() || x < 0 || y < 0 || x > rend || y > bend )
            return ;
        if (g[x][y] == '9' || g[x][y] < prev)
            return ;
        b.insert(p);
        prev = g[x][y];
        DFS(g, b, x + 1, y, prev);
        DFS(g, b, x - 1, y, prev);
        DFS(g, b, x, y + 1, prev);
        DFS(g, b, x, y - 1, prev);
}

bool    isLP(vector"string" p, int i, int j)
{
        char        L, R, U, D, C;

        C = p[i][j];
        U = i < 1 ? '9' : p[i - 1][j];
        L = j < 1 ? '9' : p[i][j - 1];
        D = i > p.size() - 2 ? '9' : p[i + 1][j];
        R = j > p[0].length() - 2 ? '9' : p[i][j + 1]; 
        if (C < L && C < R && C < U && C < D)   return (true);
        return (false);
}

void    view_grid(vector"string" bsn)
{
        string      s = " .:-=+*#%@"; // grey scale
        int         i, j;

        s = ".:-=+*#%@$";
        i = -1;
        while (++i < bsn.size())
        {
            j = -1;
            while (++j < bsn[i].size()) cout << s[ bsn[i][j] - '0' ];
            cout << endl;
        }
}
