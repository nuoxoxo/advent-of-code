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

//  BFS (queue) tells you the fewest steps we can take
//  Dijkstra uses a priority queue and chooses the cheapest path each time

//  priority queue ~ heapq

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <sstream>
#include <map>

using   namespace std;
using   pii = pair<int, int>;
using   pipii = pair<int, pii>;

int     min_risk(vector<vector<int>> G, int N);

int     main(void)
{
        vector<vector<int>> G;
        string              s;
        char                c;

        while (cin >> s)
        {
            stringstream    ss(s);
            vector<int>     temp;

            while (ss >> c) temp.push_back(c - '0');
            G.push_back(temp);
        }

        cout << "Star 1: " << min_risk(G, 1) << endl;
        cout << "Star 2: " << min_risk(G, 5) << endl;

        return (0);
}

int     min_risk(vector<vector<int>> G, int N)
{
        priority_queue<pipii, vector<pipii>, greater<pipii>> Q;
        // using std::greater<T> causes the smallest element to 
        // appear as the top()

        vector<pii>::iterator   it;
        map<pii, int>           D;
        pii                     p;
        int                     R, C, r, c, val, rsk, d;

        C = G[0].size();
        R = G.size();
        r = -1;
        while (++r < R * N)
        {
            c = -1;
            while (++c < C * N) D[make_pair(r, c)] = -1;
        }
        Q.push(make_pair(0, make_pair(0, 0)));
        while (!Q.empty())
        {
            d = Q.top().first;
            r = Q.top().second.first;
            c = Q.top().second.second;
            Q.pop();
            if (r < 0 || r >= N * R || c < 0 || c >= N * C) continue;
            val = G[r % R][c % C] + (r / R) + (c / C);
            //if (N == 5) val = G[r % R][c % C] + (r / R) + (c / C);
            //if (N == 1) val = G[r][c];
            while (val > 9) val -= 9;
            rsk = d + val;
            p = make_pair(r, c);
            if (rsk < D[p] || D[p] < 0) D[p] = rsk;
            else                        continue;
            if ( r == R * N - 1 && c == N * C - 1 ) break;
            Q.push(make_pair(D[p], make_pair(r + 1, c)));
            Q.push(make_pair(D[p], make_pair(r - 1, c)));
            Q.push(make_pair(D[p], make_pair(r, c + 1)));
            Q.push(make_pair(D[p], make_pair(r, c - 1)));
        }

        return (D[make_pair(N * R - 1, N * C - 1)] - G[0][0]);
}
