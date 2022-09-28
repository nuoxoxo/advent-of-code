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

using namespace std;

int     find_sue(string s, bool range);

//  DRIVE

int     main()
{
        vector<int> sue_exact;
        vector<int> sue_range;
        string      s;
        char        c;
        int         n;

        while (getline(cin, s))
        {
            n = find_sue(s, false);
            if (n)  sue_exact.push_back(n);
            n = find_sue(s, true);
            if (n)  sue_range.push_back(n);
        }
        cout << "Star 1 : ";
        for (int i = 0; i < sue_exact.size(); i++)  cout << sue_exact[i] << endl;
        cout << "Star 2 : ";
        for (int i = 0; i < sue_range.size(); i++)  cout << sue_range[i] << endl;
        return (0);
}

//

int     find_sue(string s, bool range)
{
        map<string, int>    real_sue;
        stringstream        ss(s);
        string              temp, item;
        int                 this_sue;
        int                 n;

        real_sue =
        {
            {"children", 3}, {"cats", 7}, 
            {"samoyeds", 2}, {"pomeranians", 3}, {"akitas", 0}, {"vizslas", 0},
            {"goldfish", 5}, {"trees", 3}, {"cars", 2}, {"perfumes", 1}
        };
        while (ss >> temp)
        {
            if (temp == "Sue")
            {
                ss >> temp;
                this_sue = stoi(temp);
            }
            else
            {
                item = temp;
                item.pop_back();
                ss >> temp;
                n = stoi(temp);
                if (range)
                {
                    if (item == "pomeranians" || item == "goldfish")
                    {
                        if (!(n < real_sue[item]))  this_sue = 0;
                    }
                    else if (item == "cats" || item == "trees")
                    {
                        if (!(n > real_sue[item]))  this_sue = 0;
                    }
                    else
                    {
                        if (real_sue[item] != n)    this_sue = 0;
                    }
                }
                if (!range && real_sue[item] != n)  this_sue = 0;
            }
        }
        return (this_sue);
}
