#include "iostream"
#include "sstream"
#include "vector"
#include "unistd.h"

using   namespace std;

void    flash_DFS(vector<vector<int>> &, int, int, int &);
void    flash_all(vector<vector<int>> &, int &);
void    reset_all(vector<vector<int>> &);
bool    check_sim(vector<vector<int>>);
void    increment(vector<vector<int>> &);
void    visualize(vector<vector<int>>, int, int);

int     main()
{

        vector<vector<int>> grid;
        string              s;
        char                c;
        bool                steps_100th, steps_first;
        int                 flash_100th, flash_first, i, steps;
        const int           rest = 64;

        while (cin >> s)
        {
            stringstream    ss(s);
            vector<int>     temp;

            while (ss >> c)
                temp.push_back(c - '0');
            grid.push_back(temp);
        }

        steps_first = steps_100th = false;
        steps = i = 0;
        while (1)
        {
            //  visual

            visualize(grid, rest, i);

            //  solve

            if (steps_100th && steps_first)
                break;

            increment(grid);
            flash_all(grid, steps);
            reset_all(grid);

            i++;

            if (i == 100)
            {
                flash_100th = steps;
                steps_100th = true;
            }
            if (check_sim(grid) && !steps_first)
            {
                steps_first = true;
                flash_first = i;
            }
        }

        cout << "Star 1: " << flash_100th << endl;
        cout << "Star 2: " << flash_first << endl;

        return (0);
}

bool    check_sim(vector<vector<int>> grid)
{

        int     r, c, i, j;

        c = grid[0].size();
        r = grid.size();
        i = -1;
        while (++i < r)
        {
            j = -1;
            while (++j < c)
                if (grid[i][j])
                    return (false);
        }
        return (true);
}

void    flash_all(vector<vector<int>>& g, int& steps)
{

        int     i, j;

        i = -1;
        while (++i < g.size())
        {
            j = -1;
            while (++j < g[0].size())
                if (g[i][j] > 9)
                    flash_DFS(g, i, j, steps);
        }
}

void    flash_DFS(vector<vector<int>>& g, int x, int y, int& c)
{

        vector<int> dx = {-1, -1, -1,  0, 0,  1, 1, 1};
        vector<int> dy = {-1,  0,  1, -1, 1, -1, 0, 1};
        int         n, px, py;

        ++c;
        n = -1;
        g[x][y] = -1;
        while (++n < dx.size())
        {
            px = x + dx[n];
            py = y + dy[n];
            if (px < g.size() && py < g[0].size() && px > -1 && py > -1 &&
                g[px][py] > -1)
            {
                g[px][py]++;
                if (g[px][py] > 9)
                    flash_DFS(g, px, py, c);
            }
        }
}

void    reset_all(vector<vector<int>>& grid)
{

        int     i, j;

        i = -1;
        while (++i < grid.size())
        {
            j = -1;
            while (++j < grid[i].size())
                if (grid[i][j] == -1)
                    grid[i][j] = 0;
        }
}

void    increment(vector<vector<int>>& grid)
{

        int     i, j;

        i = -1;
        while (++i < grid.size())
        {
            j = -1;
            while (++j < grid[0].size())
                ++grid[i][j];
        }
}

void    visualize(vector<vector<int>> oo, int sleeep, int n)
{

        int     i, j;

        i = -1;
        while (++i < oo.size())
        {
            j = -1;
            while (++j < oo[0].size())
            {
                if (oo[i][j] == 9)
                    cout << '#';
                else if (oo[i][j] == 8)
                    cout << '+';
                else if (oo[i][j] == 7)
                    cout << ':';
                else if (oo[i][j] == 6)
                    cout << '.';
                else
                    cout << ' ';
            }
            cout << endl;
        }

        cout << "\n--\n" << n << "\n--\n";

        usleep(sleeep * 1000);
}
