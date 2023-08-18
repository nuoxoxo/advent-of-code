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
#include "unistd.h"

using   namespace std;

vector"string"  paper_init(int, int, vector<vector<int>>);
void            paper_print_clear(int, int, vector"string");
void            paper_print_pound(int, int, vector"string");
int             count_pound(int, int, vector"string");

int     main()
{
        vector<vector<int>> post, inst;
        vector"string"      paper;
        string              s;
        char                c;
        int                 first, fold, row, col, i, j, k;

        //  parse

        row = col = 0;
        while (getline(cin, s) && s.length())
        {
            stringstream    ss(s);

            ss >> i >> c >> j;
            col = col > i ? col : i;
            row = row > j ? row : j;
            post.push_back({j, i}); 
        }
        while (getline(cin, s))
        {
            sscanf(s.c_str(), "fold along %c=%i\n", &c, &i);
            if (c == 'x')   inst.push_back({0, i});
            if (c == 'y')   inst.push_back({i, 0});
        }
        row++;
        col++;

        //  solve

        paper = paper_init(row, col, post);
        i = -1;
        while (++i < inst.size())
        {
            if (!inst[i][1])
            {
                fold = inst[i][0];
                j = fold - 1;
                while (++j < row)
                {
                    k = -1;
                    while (++k < col)
                    {
                        if (paper[j][k] == '#') paper[2 * fold - j][k] = '#';
                    }
                }
                row = fold;
            }
            else if (!inst[i][0])
            {
                fold = inst[i][1];
                j = -1;
                while (++j < row)
                {
                    k = fold - 1;
                    while (++k < col)
                    {
                        if (paper[j][k] == '#') paper[j][2 * fold - k] = '#';
                    }
                }
                col = fold;
            }
            if (!i) first = count_pound(row, col, paper);
            paper_print_clear(row, col, paper);
            usleep(1000 * 128);
        }
        
        cout << "Star 1: " << first << endl;
        cout << "Star 2: \n";
        paper_print_pound(row, col, paper);
        paper_print_clear(row, col, paper);

        return (0);
}

vector"string"  paper_init(int r, int c, vector<vector<int>> ps)
{
        vector"string"  res;
        string          s;
        int             i, j;

        i = -1;
        while (++i < r)
        {
            s = "";
            j = -1;
            while (++j < c) s += '.';
            res.push_back(s);
        }
        i = -1;
        while (++i < ps.size()) res[ ps[i][0] ][ ps[i][1] ] = '#';

        return (res);
}

int     count_pound(int r, int c, vector"string" paper)
{
        int     tt = 0, i = -1, j;

        while (++i < r)
        {
            j = -1;
            while (++j < c) if (paper[i][j] == '#') tt++;
        }

        return (tt);
}

void    paper_print_clear(int r, int c, vector"string" g)
{
        char    chr;
        int     i = -1, j;

        while (++i < r)
        {
            j = -1;
            while (++j < c)
            {
                chr = g[i][j];
                if (chr == '.') cout << "  ";
                else            cout << " @";
            }
            cout << endl;
        }
        cout << "--" << endl;
}

void    paper_print_pound(int r, int c, vector"string" g)
{
        int     i = -1, j;

        while (++i < r)
        {
            j = -1;
            while (++j < c) cout << g[i][j];
            cout << endl;
        }
        cout << "--" << endl;
}
