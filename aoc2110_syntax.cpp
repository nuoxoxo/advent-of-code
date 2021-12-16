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
#include "map"
#include "stack"

using   namespace std;

vector<long>    solve_2(vector<string>, map<char, char>, map<char, int>);
int             solve_1(vector<string>, map<char, char>, map<char, int>);
void            parse_1(string, map<char, int>&, map<char, char>&);
void            parse_2(string, map<char, int>&);
long            string_to_long(string, map<char, int>);
string          stack_to_string(stack<char>);

int     main(void)
{
        map<char, char> opener;
        map<char, int>  scores1, scores2;
        vector<string>  subsys;
        vector<long>    score_vect;
        string          s, scoring1, scoring2;
        char            c;
        long            mid_score;
        int             sum_score, i;

        //  Parse

        scoring2 = "): 1 point.\n]: 2 points.\n}: 3 points.\n>: 4 points.";
        scoring1 = 
        "): 3 points.\n]: 57 points.\n}: 1197 points.\n>: 25137 points.";

        while (cin >> s)    subsys.push_back(s);
        parse_1(scoring1, scores1, opener);
        parse_2(scoring2, scores2);

        //  Solve

        sum_score = solve_1(subsys, opener, scores1);
        score_vect = solve_2(subsys, opener, scores2);
        sort(score_vect.begin(), score_vect.end());
        mid_score = score_vect[score_vect.size() / 2];

        cout << "Star 1: " << sum_score << endl;
        cout << "Star 2: " << mid_score << endl;

        return (0);
}

vector<long> solve_2(vector<string> ns, map<char, char> op, map<char, int> sc)
{
        map<char, char>::iterator   it;
        vector<long>                score_vect;
        stack<char>                 stack;
        string                      s;
        bool                        isCorrupt, isOpener;
        char                        c;
        long                        tt;
        int                         i, j;

        i = -1;
        while (++i < ns.size())
        {
            while (!stack.empty())    stack.pop();
            
            tt = 0;
            j = -1;
            isCorrupt = false;
            while (++j < ns[i].size())
            {
                c = ns[i][j];
                isOpener = false;
                it = op.begin();
                while (it != op.end())
                {
                    if (c == it->second)
                    {
                        isOpener = true;
                        stack.push(c);
                        break;
                    }
                    it++;
                }
                if (!isOpener)
                {
                    if (stack.top() == op[c])   stack.pop();
                    else                        isCorrupt = true;
                }
                if (isCorrupt)  break;
            }
            //cout<<"staack size : "<<stack.size()<<endl;
            //cout<<"is it empty : "<<stack.empty()<<endl;
            if (!isCorrupt && !stack.empty())
            {
                s = stack_to_string(stack);
                tt = string_to_long(s, sc);
                score_vect.push_back(tt);
            }
            //cout<<ns[i]<<' '<<tt<<endl;
        }
        return (score_vect);
}

string  stack_to_string(stack<char> stack)
{
        string      s;
        int         n;

        while (!stack.empty())
        {
            if (stack.top() == '(') n = 1;
            else                    n = 2;
            s += (char) (stack.top() + n);
            stack.pop();
        }
        //cout<<s<<endl;
        return (s);
}

long     string_to_long(string str, map<char, int> sc)
{
        long    tt = 0;
        int     i = -1;
    
        while (++i < str.length())  tt = sc[str[i]] + tt * 5;
        //cout<<tt<<endl;
        return (tt);
}

int     solve_1(vector<string> ns, map<char, char> op, map<char, int> sc)
{
        map<char, char>::iterator   it;
        stack<char>                 stack;
        char                        c;
        bool                        isOpener;
        bool                        firstErr;
        int                         tt, i, j;

        tt = 0;
        i = -1;
        while (++i < ns.size())
        {
            while (!stack.empty())  stack.pop();
            j = -1;
            firstErr = false;
            while (++j < ns[i].size())
            {
                c = ns[i][j];
                isOpener = false;
                it = op.begin();
                while (it != op.end())
                {
                    if (c == it->second)
                    {
                        isOpener = true;
                        stack.push(c);
                        break;
                    }
                    it++;
                }
                if (!isOpener)
                {
                    if (stack.empty())
                    {
                        firstErr = true;
                        tt += sc[c];
                    }
                    else
                    {
                        if (stack.top() == op[c]) stack.pop();
                        else
                        {
                            firstErr = true;
                            tt += sc[c];
                        }
                    }
                }
                if (firstErr)   break;
            }
        }

        return (tt);
}

void    parse_2(string s, map<char, int>& sc)
{
        char    c;
        int     i;

        stringstream    ss(s);
        while (getline(ss, s))
        {
            stringstream    ss(s);
            i = -1;
            while (getline(ss, s, ':'))
            {
                if (i % 2)  c = s[0];
                else        sc[c] = stoi(s);
                ++i;
            }
        }
}

void    parse_1(string s, map<char, int>& sc, map<char, char>& op)
{
        char    c;
        int     i;

        stringstream    ss(s);
        while (getline(ss, s))
        {
            stringstream    ss(s);
            i = -1;
            while (getline(ss, s, ':'))
            {
                if (i % 2)  c = s[0];
                else
                {
                    sc[c] = stoi(s);
                    if (c == ')')   op[c] = c - 1;
                    else            op[c] = c - 2;
                }
                ++i;
            }
        }
}
