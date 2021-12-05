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
#include <vector>

using namespace std;

//  DRIVE

vector<string>  life_of_four(vector<string> grid, vector<vector<int>> neighbors, int steps);
vector<string>  game_of_life(vector<string> grid, vector<vector<int>> neighbors, int steps);
int             count_live_neighbors(vector<string> s, vector<vector<int>> n, int p, int q);
int             count_lights(vector<string> state);
void            print_state(vector<string> a, int b);

int     main(void)
{
        vector<vector<int>> neighbors;
        vector<string>      grid, game, life;
        string              s;
        int                 steps;

        neighbors = 
        {
            { 1,  1}, { 1, 0}, { 1, -1}, { 0, -1},
            {-1, -1}, {-1, 0}, {-1,  1}, { 0,  1}
        };
        while (getline(cin, s)) grid.push_back(s);
        steps = 100;
        game = game_of_life(grid, neighbors, steps);
        life = life_of_four(grid, neighbors, steps);
        cout << "Star 1 : " << count_lights(game) << endl;
        cout << "Star 2 : " << count_lights(life) << endl;
        return (0);
}

//

vector<string>  life_of_four(vector<string> grid, vector<vector<int>> n, int steps)
{
        vector<string>  state;
        int             alive, e;

        while (steps)
        {
            print_state(grid, steps);
            state = grid;
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[i].length(); j++)
                {
                    e = grid[i].length() - 1;
                    alive = count_live_neighbors(grid, n, i, j);
                    if (!((!i && j == e) || (i == e && j == e) || (!i && !j) || (i == e && !j))
                        && alive != 2 && alive != 3)
                        state[i][j] = '.';
                    if (alive == 3)
                        state[i][j] = '#';
                }
            }
            steps--;
            grid = state;
        }

        return (grid);
}

vector<string>  game_of_life(vector<string> grid, vector<vector<int>> n, int steps)
{
        vector<string>  state;
        int             alive;

        while (steps)
        {
            print_state(grid, steps);
            state = grid;
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[i].length(); j++)
                {
                    alive = count_live_neighbors(grid, n, i, j);
                    if (alive != 2 && alive != 3)
                        state[i][j] = '.';
                    if (alive == 3)
                        state[i][j] = '#';
                }
            }
            steps--;
            grid = state;
        }

        return (grid);
}

int     count_live_neighbors(vector<string> s, vector<vector<int>> n, int p, int q)
{
        int     x, y, total;

        total = 0;
        for (int i = 0; i < n.size(); i++)
        {
            x = p + n[i][0];
            y = q + n[i][1];
            if (x < s[0].length() && y < s[0].length() 
                && y > -1 && x > -1 && s[x][y] == '#')
                total++;
        }

        return (total);
}

int     count_lights(vector<string> s)
{
        int     total = 0;

        for (int i = 0; i < s.size(); i++)
            for (int j = 0; j < s[i].length(); j++)
                if (s[i][j] == '#') total++;

        return (total);
}

void    print_state(vector<string> state, int steps)
{
        for (int i = 0; i < state.size(); i++) cout << state[i] << endl;
        cout << endl << steps << endl;
}
