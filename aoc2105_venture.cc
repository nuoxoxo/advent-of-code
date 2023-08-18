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

using   namespace std;

vector<vector<int>> make_grid(int side);
void                mark_HV(vector<vector<int>>&, vector<vector<int>>);
void                mark_DG(vector<vector<int>>&, vector<vector<int>>);
int                 count_gt1(vector<vector<int>>);
void                show_grid(vector<vector<int>>);

int     main()
{
        vector<vector<int>>     vent, grid;
	int                     side, i, j, x, y, HV, DG;
        string                  s;
        
        side = 1000;            // 10 if test
        grid = make_grid(side);        
        while (getline(cin, s))
        {
            vector<int>     f;

            sscanf(s.c_str(), "%i,%i -> %i,%i", &i, &j, &x, &y);
            f.push_back(j);
            f.push_back(i);
            f.push_back(y);
            f.push_back(x);
            vent.push_back(f);
        }
        
        mark_HV(grid, vent);
        HV = count_gt1(grid);

        //  test
        //  show_grid(grid);

        mark_DG(grid, vent);
        DG = count_gt1(grid);

        //  test
        //  show_grid(grid);

        cout << "Star 1: " << HV << endl;
        cout << "Star 2: " << DG << endl;

        return (0);
}

int     count_gt1(vector<vector<int>> grid)
{
        int     t, i, j;

        i = -1;
        t = 0;
        while (++i < grid.size())
        {
            j = -1;
            while (++j < grid[i].size())
                if (grid[i][j] > 1) t++;
        }

        return (t);
}

void    mark_DG(vector<vector<int>>& grid, vector<vector<int>> v)
{
        int     begin_x, until_x, begin_y, until_y;
        int     i, dx, dy;

        i = -1;
        while (++i < (int) v.size())
        {
            if (v[i][0] != v[i][2] && v[i][1] != v[i][3])
            {
                dx = dy = 1;
                begin_x = v[i][0];
                begin_y = v[i][1];
                until_x = v[i][2];
                until_y = v[i][3];
                if (begin_x > until_x)
			dx = -dx;
                if (begin_y > until_y)
			dy = -dy;
                while (begin_x != until_x + dx)
                {
                    grid[begin_x][begin_y]++;
                    begin_x += dx;
                    begin_y += dy;
                }
            }
        }
}

void    mark_HV(vector<vector<int>>& grid, vector<vector<int>> v)
{
        int     start, finish, i, j;

        i = -1;
        while (++i < (int) v.size())
        {
            if (v[i][0] == v[i][2])
            {
                start = v[i][1];
                finish = v[i][3];
                if (start > finish)
			swap(start, finish);
                j = start - 1;
                while (++j <= finish)
			grid[ v[i][0] ][j]++;
            }
            else if (v[i][1] == v[i][3])
            {
                start = v[i][0];
                finish = v[i][2];
                if (start > finish)
			swap(start, finish);
                j = start - 1;
                while (++j <= finish)
			grid[j][ v[i][1] ]++;
            }
        }
}

vector<vector<int>> make_grid(int side)
{
        vector<vector<int>>	grid;
        int                	i, j;

        i = -1;
        while (++i < side)
        {
            vector<int>    temp;

            j = -1;
            while(++j < side)
		    temp.push_back(0);
            grid.push_back(temp);
        }

        return (grid);
}

//  test

/*

--
.......1..
..1....1..
..1....1..
.......1..
.112111211
..........
..........
..........
..........
222111....
--
--
1.1....11.
.111...2..
..2.1.111.
...1.2.2..
.112313211
...1.2....
..1...1...
.1.....1..
1.......1.
222111....
--
Star 1: 5
Star 2: 12

*/

void    show_grid(vector<vector<int>> grid)
{
        int i, j;

        cout << "--" << endl;
        i = -1;
        while (++i < grid.size())
        {
            j = -1;
            while (++j < grid[i].size())
            {
                if (!grid[i][j])
			cout << '.';
                else
			cout << grid[i][j];
            }
            cout << endl;
        }
        cout << "--" << endl;
}
