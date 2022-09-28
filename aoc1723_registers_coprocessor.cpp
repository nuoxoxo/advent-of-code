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

long    get_value(map<char, long> game, string temp);
int     count_mul(vector"string" instructions);
long    cal_reg_h(vector"string" instructions); // obsolete
long    finding_h(void);

//  DRIVE

int     main()
{
        vector"string"  instructions;
        string          s;
        long            H;
        int             C;

        while (getline(cin, s)) instructions.push_back(s);
        C = count_mul(instructions);
        H = finding_h();    //h = cal_reg_h(instructions);

        cout << "Star 1 : " << C << endl;
        cout << "Star 2 : " << H << endl;

        return (0);
}

//

long    finding_h(void)
{
        int     h, b, d, c;

        h = 0;
        b = 99;
        b *= 100;
        b += 100000;
        c = b + 17000;

        while (b <= c)
        {
            d = 1;
            while (++d != b)
            {
                if (b % d == 0)
                {
                    h++;
                    break;
                }
            }
            b += 17;
        }

        return (h);
}

long    cal_reg_h(vector"string" inst)  // takes too long
{
        map<char, long> game;
        string          code, s;
        char            name;
        int             i;

        i = -1;
        game['a'] = 1;
        while (1)
        {
            stringstream    ss(inst[++i]);

            /*
            cout << i << " - ";
            cout << game['a'] << " - ";
            cout << game['b'] << " - ";
            cout << game['c'] << " - ";
            cout << game['d'] << " - ";
            cout << game['e'] << " - ";
            cout << game['f'] << " - ";
            cout << game['g'] << " - ";
            cout << game['h'] << endl;
            */
            if (i < 0 || i > inst.size() - 1)   break;
            ss >> code;
            if (code == "set")  ss >> name >> s, game[name] = get_value(game, s);
            if (code == "sub")  ss >> name >> s, game[name] -= get_value(game, s);
            if (code == "mul")  ss >> name >> s, game[name] *= get_value(game, s);
            if (code == "jnz")
            {
                ss >> code >> s;
                if (get_value(game, code))  i += get_value(game, s) - 1;
            }
        }

        return (game['h']);
}

int     count_mul(vector"string" inst)
{
        map<char, long> game;
        string          code, s;
        int             count, i;
        char            name;
        long            n;

        i = -1;
        count = 0;
        while (1)
        {
            stringstream    ss(inst[++i]);

            if (i < 0 || i > inst.size() - 1)   break;
            ss >> code;
            if (code == "set")  ss >> name >> s, game[name] = get_value(game, s);
            if (code == "sub")  ss >> name >> s, game[name] -= get_value(game, s);
            if (code == "mul")  ss >> name >> s, game[name] *= get_value(game, s), count++;//, cout<<"i : "<<i<<endl;
            if (code == "jnz")
            {
                ss >> code >> s;
                if (get_value(game, code))  i += get_value(game, s) - 1;
            }
        }

        return (count);
}

long    get_value(map<char, long> game, string s)
{
        int     x;

        if (stringstream(s) >> x)   return (x);
        return game[s[0]];
}
