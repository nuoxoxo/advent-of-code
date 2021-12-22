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

#include "map" // adj list, two way
#include "set"
#include "vector"
#include "sstream"
#include "iostream"

using   namespace std;
using   adj = map<string, vector<string>>;
using   msi = map<string, int>;

void    DFS1(string, adj, msi, long&, vector<string>);
void    DFS2(string, adj, msi, long&, vector<string>);
void    print_path(vector<string>, long);

int     main(void)
{
        string  s;
        long    part1, part2;
        msi     visited;
        vector<string>  path;
        adj     E;

        //  parsing

        while (getline(cin, s))
        {
            stringstream    ss(s);
            string          L, R;

            getline(ss, L, '-');
            ss >> R;
            E[L].push_back(R);
            E[R].push_back(L);
        }

        //  solve

        part1 = part2 = 0;
        DFS1("start", E, visited, part1, path);
        DFS2("start", E, visited, part2, path);

        cout << "Star 1: " << part1 << endl;
        cout << "Star 2: " << part2 << endl;

        return (0);
}

void    DFS2(string node, adj E, msi V, long& n, vector<string> path)
{
        int     gt1 = 0, i = -1;

        if (node == "end")
        {
            print_path(path, n);
            n += 1;
            return;
        }
        if (islower(node[0]))
        {
            msi::iterator   it = V.begin();
            int             gt1 = 0;

            path.push_back(node);
            V[node] += 1;
            while (it != V.end())
            {
                if (it->second > 1)
                {
                    // if one of the nodes ahead > 2, we fail, backtrack
                    if (it->second > 2)
                    {
                        path.pop_back();
                        V[node] --;
                        return ;
                    }
                    gt1++;
                }
                it++;
            }
            if (gt1 > 1)
            {
                path.pop_back();
                V[node] --;
                return ; // if more than one nodes > 1, backtrack
            }
        }
        while (++i < E[node].size())
        {
            if (E[node][i] == "start")  continue;
            DFS2(E[node][i], E, V, n, path);
        }
        path.pop_back();
        V[node]--; // attempt finished, backtrack
}

void    DFS1(string node, adj E, msi V, long& n, vector<string> path)
{
        int     i = -1;

        if (node == "end")
        {
            print_path(path, n);
            n += 1;
            return;
        }
        if (islower(node[0]) && V[node])    return ;
        path.push_back(node);
        V[node]++;
        while (++i < E[node].size())
            if (E[node][i] != "start")  DFS1(E[node][i], E, V, n, path);
        path.pop_back();
        V[node]--;
}

void    print_path(vector<string> pa, long n)
{
        int     i = -1;

        cout << n << ": ";
        while (++i < pa.size())
        {
            cout << pa[i] << ',';
            if (i == pa.size() - 1) cout << "end";
        }
        cout << endl;
}
