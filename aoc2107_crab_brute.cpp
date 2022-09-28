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
#include "limits"
#include "vector"

using   namespace std;

int     move(int diff);

int     main()
{
        vector<int> post;
        string      s;
        int         fuel, temp, min, max, i, j, rest;

        cin >> s;
        stringstream    ss(s);
        while (getline(ss, s, ',')) post.push_back(stoi(s));
        //i = -1; while(++i < post.size()) cout << post[i] << ", "; // test
        min = *min_element(post.begin(), post.end());
        max = *max_element(post.begin(), post.end());
        fuel = numeric_limits<int>::max();
        i = min - 1;
        while (++i < max + 1)
        {
            temp = 0;
            j = -1;
            while (++j < post.size())   temp += abs(i - post[j]);
            fuel = fuel < temp ? fuel : temp;
        }
        rest = fuel;
        fuel = numeric_limits<int>::max();
        i = min - 1;
        while (++i < max + 1)
        {
            temp = 0;
            j = -1;
            while (++j < post.size())   temp += move(abs(i - post[j]));
            fuel = fuel < temp ? fuel : temp;
        }

        cout << "Star 1: " << rest << endl;
        cout << "Star 2: " << fuel << endl;

        return (0);
}

int     move(int diff)
{
        if (diff <= 1)  return (diff);
        return (move(diff - 1) + diff);
}
