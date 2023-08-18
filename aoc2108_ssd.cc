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

using   namespace std;

int             find_display(string, string);
vector"string"  sort_segment(string);

int     main()
{
        string      L, R, s, output, unique;
        int         n, i, j, total, times;

        times = total = 0;
        while (getline(cin, s))
        {
            stringstream    ss(s);

            i = 0;
            while (getline(ss, output, '|'))
            {
                if (++i % 2)    L = output;
                else
                {
                    //  Part 1
                    
                    stringstream    oo(output);
                    while (oo >> unique)
                    {
                        n = unique.length();
                        if (n == 2 || n == 3 || n == 4 ||
                            n == 7) times++;
                    }

                    //  Part 2
                    
                    R = output;
                    total += find_display(L, R);
                }
            }
        }

        cout << "Star 1: " << times << endl;
        cout << "Star 2: " << total << endl;

        return (0);
}

int     find_display(string L, string R)
{
        vector"string"      len6, len5;
        vector"string"      right;
        vector"string"      left;
        map<string, int>    wire;
        string              seven, five, six, one, s;
        char                TR, RU, RD, LD;
        int                 len, i, res;

        left = sort_segment(L);
        right = sort_segment(R);
        i = -1;
        while (++i < left.size())
        {
            len = left[i].length();
            if (len == 2)
            {
                wire[left[i]] = 1;  // 1
                one = left[i];
            }
            if (len == 3)
            {
                wire[left[i]] = 7;  // 7
                seven = left[i];
            }
            if (len == 4)   wire[left[i]] = 4;  // 4
            if (len == 7)   wire[left[i]] = 8;  // 8
            if (len == 5)   len5.push_back(left[i]);
            if (len == 6)   len6.push_back(left[i]);
        }

        i = 0;  // get top row from 1 7
        while (seven[i] == one[i])  i++;
        TR = seven[i];

        i = -1; // search len6 group (0 6 9) for right up, right down and 6
        while (++i < len6.size())   // 6
        {
            s = len6[i];
            if (s.find(one[0]) != string::npos
            &&  s.find(one[1]) == string::npos)
            {
                wire[s] = 6;
                RU = one[1];
                RD = one[0];
                six = s;
                len6.erase(len6.begin() + i);
                break;
            }
            if (s.find(one[0]) == string::npos
            &&  s.find(one[1]) != string::npos)
            {
                wire[s] = 6;
                RU = one[0];
                RD = one[1];
                six = s;
                len6.erase(len6.begin() + i);
                break;
            }
        }

        i = -1;
        while (++i < len5.size())   // 2 3 5
        {
            s = len5[i];
            if (s.find(RU) != string::npos
            &&  s.find(RD) != string::npos)
            {
                wire[s] = 3;
                len5.erase(len5.begin() + i);
                i--;
            }
            else if (s.find(RU) != string::npos
            &&  s.find(RD) == string::npos)
            {
                wire[s] = 2;
                len5.erase(len5.begin() + i);
                i--;
            }
            else if (s.find(RU) == string::npos
            &&  s.find(RD) != string::npos)
            {
                wire[s] = 5;
                five = s;
                len5.erase(len5.begin() + i);
                i--;
            }
        }
        
        i = 0;  // left down
        while (five[i] == six[i])   i++;
        LD = six[i];

        i = -1; // 6 9
        while (++i < len6.size())
        {
            s = len6[i];
            if (s.find(LD) != string::npos)
            {
                wire[s] = 0;
                len6.erase(len6.begin() + i);
                break;
            }
        }
        wire[len6[0]] = 9;

        res = 0;
        i = -1;
        while (++i < right.size())  res = res * 10 + wire[right[i]];

        return (res);
}

vector"string"  sort_segment(string s)
{
        vector"string"  vect;
        string          str;
        stringstream    ss(s);

        while (ss >> str)
        {
            sort(str.begin(), str.end());
            vect.push_back(str);
        }

        return (vect);
}

//      tester: check if each line contains a len3 string

/*

int     len3test(string L, string R)
{
        (void)          R;
        stringstream    ss(L);
        string          s;
        int             i;

        while (ss >> s) if ( s.length() == 3 )  return (1);
        return (0);
}

*/
