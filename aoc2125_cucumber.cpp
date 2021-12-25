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
#include "sstream"
#include "unistd.h"

using   namespace std;

void    printG(vector<vector<char>>);
int     part1(vector<vector<char>>);

int     main(void)
{
        vector<vector<char>>    G;
        string                  s;
        char                    c;
        int                     N;

        while (cin >> s)
        {
            stringstream    ss(s);
            vector<char>    temp;

            while (ss >> c) temp.push_back(c);
            G.push_back(temp);
        }
        
        N = part1(G);
        cout << "Star 1: " << N << endl;

        return (0);
}

int     part1(vector<vector<char>> G)
{
        vector<vector<char>>    E;
        int                     count = 0, i, j, R, C;
        bool                    moved = true;

        C = G[0].size();
        R = G.size();
        while (moved)
        {
            E = G;
            //printG(G);
            i = -1;
            moved = false;
            while (++i < R)
            {
                j = -1;
                while (++j < C)
                {
                    if (G[i][j] == '>')
                    {
                        if (j < C - 1 && G[i][j + 1] == '.')
                        {
                            E[i][j] = '.';
                            E[i][j + 1] = '>';
                            moved = true;
                        }
                        if (j == C - 1 && G[i][0] == '.')
                        {
                            E[i][j] = '.';
                            E[i][0] = '>';
                            moved = true;
                        }
                    }
                }
            }
            G = E;
            i = -1;
            while (++i < R)
            {
                j = -1;
                while (++j < C)
                {
                    if (G[i][j] == 'v')
                    {
                        if (i + 1 < R && G[i + 1][j] == '.')
                        {
                            E[i][j] = '.';
                            E[i + 1][j] = 'v';
                            moved = true;
                        }
                        if (i + 1 == R && G[0][j] == '.')
                        {
                            E[i][j] = '.';
                            E[0][j] = 'v';
                            moved = true;
                        }
                    }
                }
            }
            count ++ ;
            G = E;
        }

        return (count);
}

void    printG(vector<vector<char>> G)
{
        int i, j; i = -1;
        while (++i < G.size())
        {
            j = -1;
            while (++j < G[0].size())
            {
                cout << G[i][j] << ' ';
            }
            cout << endl;
        }
        cout << "--" << endl;
        usleep(1000 * 32);
}
