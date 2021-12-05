/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

void    end_game(vector<string> inst, map<char, int>& game);

int     main(void)
{
        map<char, int>  game;
        vector<string>  inst;
        string          s;
        int             a;

        while (getline(cin, s)) inst.push_back(s);
        end_game(inst, game);
        a = game['a'];
        game.clear();
        game['c'] = 1;
        end_game(inst, game);
        cout << "Star 1 : " << a << endl;
        cout << "Star 2 : " << game['a'] << endl;

        return (0);
}

void    end_game(vector<string> inst, map<char, int>& game)
{
    string  temp, code;
    char    from, to;
    int     num, i;

    i = 0;
    while (1)
    {
        stringstream    ss(inst[i]);

        if ( i < 0 || i > (int) inst.size() - 1 ) break;
        ss >> code;
        if (code == "jnz")
        {
            ss >> temp;
            if (stringstream(temp) >> num)
            {
                if (num)
                {
                    ss >> num;
                    i += num;
                }
                else
                    i += 1;
            }
            else
            {
                ss >> num;
                if (game[temp[0]])
                    i += num;
                else
                    i += 1;
            }
        }
        if (code == "cpy")
        {
            ss >> temp >> to;
            if (stringstream(temp) >> num)
                game[to] = num;
            else
                game[to] = game[temp[0]];
            i += 1;
        }
        if (code == "inc")
        {
            ss >> to;
            game[to] += 1;
            i += 1;
        }
        if (code == "dec")
        {
            ss >> to;
            game[to] -= 1;
            i += 1;
        }
    }
}
