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
#include "algorithm" //  find
#include "utility"  //  pair, make_pair
#include "vector"
#include "sstream"
#include "string"   //  getline

using namespace std;

pair<string, string> find_prev \
        (vector< pair<string, string> > a, string s);
int     count_orbits \
        (vector< pair<string, string> > a, string s, string t, int n);
int     seen(vector"string" unique, string s);

//  DRIVE

int     main()
{
        vector< pair<string, string> >  orbits;
        vector"string"                  unique;
        vector"string"                  path_of_you;
        vector"string"                  path_of_san;
        string                          s;
        int                             count_all_orbits = 0;

        //  Part 1

        while (cin >> s)
        {
            string          x;
            string          y;
            
            stringstream    ss(s);
            getline(ss, x, ')');
            getline(ss, y);
            orbits.push_back(make_pair(x, y));
        }
 
        for (int i = 0; i < (int) orbits.size(); i++)
        {
            if (!seen(unique, orbits[i].second))
            {
                count_all_orbits += count_orbits(orbits, orbits[i].second, "COM", 1);
                unique.push_back(orbits[i].second);
            }
        }

        //  Part 2

        string  step_of_you = "YOU";
        string  step_of_san = "SAN";
        int     count_you_to_san, i, j;      

        while (1)
        {
            pair<string, string>    temp = find_prev(orbits, step_of_you);
            step_of_you = temp.first;
            if (step_of_you == "COM")   break;
            path_of_you.push_back(step_of_you);
        }
        while (1)
        {
            pair<string, string>    temp = find_prev(orbits, step_of_san);
            step_of_san = temp.first;
            if (step_of_san == "COM")   break;
            path_of_san.push_back(step_of_san);
        }
        count_you_to_san = i = 0;
        while (i < (int) path_of_you.size() && !count_you_to_san)
        {
            j = 0;
            while (j < (int) path_of_san.size() && !count_you_to_san)
            {
                if (path_of_you[i] == path_of_san[j])   count_you_to_san = i + j;
                j++;
            }
            i++;
        }
        cout << "Star 1 : " << count_all_orbits << endl;
        cout << "Star 2 : " << count_you_to_san << endl;
}

//

pair<string, string> \
        find_prev(vector< pair<string, string> > arr, string s)
{
        int     i = 0;

        while (i < (int) arr.size())
        {
            if (arr[i].second == s)    break;
            i++;
        }
        return (arr[i]);
}

int     count_orbits(vector< pair<string, string> > arr, string second, string target, int n)
{
        pair<string, string>    temp = find_prev(arr, second);
        if (temp.first == target)   return (n);
        n += 1;
        return (count_orbits(arr, temp.first, target, n));
}

int     seen(vector"string" arr, string s)
{
        if (find(arr.begin(), arr.end(), s) != arr.end())
            return (1);
        return (0);
}
