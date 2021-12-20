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

#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <algorithm>

using   namespace std;

set<pair<int, int>> enhance(string A, set<pair<int, int>>, int, bool&);
vector<int>         find_bound(set<pair<int, int>>);
void                show(set<pair<int, int>>);

int     main(int argc, char *argv[])
{
        /*  after exhaustive testing M the magic number is 4  */

        set<pair<int, int>> G, temp;
        vector<string>      grid;
        string              A, s;
        int                 N, R, C, r, c, i, twice;
        bool                first = false;
        int                 M = 4;

        //  parsing

        cin >> A;
        while (cin >> s)    grid.push_back(s);
        C = grid[0].size();
        R = grid.size();
        r = -1;
        while (++r < R)
        {
            c = -1;
            while (++c < C) if (grid[r][c] == '#')  G.insert(make_pair(r, c));
        }

        //  solve

        i = -1;
        N = (argc == 2) ? stoi(argv[1]) : 2;
        while (++i < N)
        {
            //show(G);
            cout << "Current size: " << G.size() << endl;
            if (i + 1 == N) cout << "--\n";
            G = enhance(A, G, M, first);
            if (i == 1) twice = (int) G.size();
        }

        cout << "Star 1: " << twice << endl;
        cout << "Star 2: " << G.size() << endl;

        return (0);
}

set<pair<int, int>> enhance(string A, set<pair<int, int>> G, int M, bool& f)
{
        set<pair<int, int>> temp;
        pair<int, int>      P;
        vector<int>         B;
        string              bins;
        int                 i, r, c, dr, dc;

        if (A[0] == '#')
        {
            if (f)  M = 0;
        }
        else
        {
            M = 2;
        }
        B = find_bound(G);
        r = B[0] - M;
        while (++r < B[1] + M)
        {
            c = B[2] - M;
            while (++c < B[3] + M)
            {
                bins = "";
                dr = -2;
                while (++dr < 2)
                {
                    dc = -2;
                    while (++dc < 2)
                    {
                        P = make_pair(r + dr, c + dc);
                        if (G.find(P) != G.end())   bins += '1';
                        else                        bins += '0';
                    }
                }
                i = stoi(bins, 0, 2);
                if (A[i] == '#')
                {
                    temp.insert(make_pair(r, c));
                }
            }
        }
        f = !f;

        return (temp);
}

vector<int> find_bound(set<pair<int, int>> G)
{
        set<pair<int, int>>::iterator   P;
        vector<int>                     B;
        int                             RL, RH, CL, CH;

        RH = CH = numeric_limits<int>::min();
        RL = CL = numeric_limits<int>::max();
        P = G.begin();
        while (P != G.end())
        {
            RL = RL < P->first  ? RL : P->first;
            RH = RH > P->first  ? RH : P->first;
            CL = CL < P->second ? CL : P->second;
            CH = CH > P->second ? CH : P->second;
            P++;
        }
        B = {RL, RH, CL, CH};

        return (B);
}

void    show(set<pair<int, int>> G)
{
        set<pair<int, int>>::iterator   P;
        vector<int>                     B;
        string                          s;
        int                             i, j;

        B = find_bound(G);
        i = B[0] - 1;
        while (++i < B[1] + 1)
        {
            s = "";
            j = B[2] - 1;
            while (++j < B[3] + 1)
            {
                if (G.find(make_pair(i, j)) != G.end()) s += '#';
                else                                    s += '.';
            }
            cout << s << endl;
        }
        cout << "--\n";
}
