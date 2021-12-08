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
#include "sstream"
#include "vector"
#include "map"

using	namespace std;

int     last_spoken(int post, map<int, int> said);

int     main(int argc, char** argv)
{
        map<int, int>   said;
        vector<int>     nums;
        string          s;
        int             p1, p2, i;

        p1 = 2020;
        p2 = 30000000;
        cin >> s;
        stringstream    ss(s);
        while (getline(ss, s, ',')) nums.push_back(stoi(s));
        i = -1;
        while (++i < nums.size())   said[nums[i]] = i;
        cout << "Star 1: " << last_spoken(p1, said) << endl;
        cout << "Star 2: " << last_spoken(p2, said) << endl;

	return (0);
}

int     last_spoken(int post, map<int, int> said)
{
        int     last, c, i;

        c = 0;
        i = said.size() - 1;
        while (++i < post)
        {
            last = c;
            if (said.find(c) != said.end()) c = i - said[c];
            else                            c = 0;
            said[last] = i;
        }
        return (last);
}
