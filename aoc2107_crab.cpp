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

int     move(int);

int     main(void)
{
        vector<int> post;
        string      s;
        float       avg;
        int         fuel, i;
        int         midi, f, c, temp;  // Part 2

        cin >> s;
        stringstream    ss(s);
        while (getline(ss, s, ',')) post.push_back(stoi(s));
        
        //  Part 1

        sort(post.begin(), post.end());
        midi = post.size() / 2;
        fuel = 0;
        i = -1;
        while ( ++i < post.size() ) fuel += abs(post[i] - post[midi]);
        cout << "Star 1: " << fuel << endl;

        //  Part 2

        fuel = 0;
        i = -1;
        while ( ++i < post.size() ) fuel += post[i];
        avg = (float) fuel / (float) post.size();
        f = floor(avg);
        c = ceil(avg);
        fuel = temp = 0;
        i = -1;
        while ( ++i < post.size() )
        {
            fuel += move(abs(post[i] - f));
            temp += move(abs(post[i] - c));
        }
        fuel = fuel < temp ? fuel : temp;
        cout << "Star 2: " << fuel << endl;

        return (0);
}

int     move(int diff)
{
        if (diff <= 1)  return (diff);
        return (move(diff - 1) + diff);
}
