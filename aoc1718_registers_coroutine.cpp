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
#include <queue>
#include <map>

using namespace std;

long    get_value(map<char, long>& game, string s);
int     coroutine(vector<string> instructions);
int     recover(vector<string> instructions);
bool    receive(int& count, int& index, queue<long>& native, queue<long>& remote,
        map<char, long>& game, vector<string> instructions);

//  DRIVE

int     main(void)
{
        vector<string>  instructions;
        string          s;
        int             first_rcv, program_1;

        while (getline(cin, s)) instructions.push_back(s);
        first_rcv = recover(instructions);
        program_1 = coroutine(instructions);
        cout << "Star 1 : " << first_rcv << endl;
        cout << "Star 2 : " << program_1 << endl;

        return (0);
}

///

int     coroutine(vector<string> instructions)
{
        map<char, long> ga, go;
        queue<long>     qa, qo;
        int             ca, co, ia, io;
        bool            a, o;

        ca = co = ia = io = 0;
        go['p']++;
        while (1)
        {
            a = receive(ca, ia, qa, qo, ga, instructions);
            o = receive(co, io, qo, qa, go, instructions);
            if ( !a && !o ) break;  //  final line
        }

        return (co);
}

bool    receive(int& count, int& i, queue<long>& native, queue<long>& remote,
        map<char, long>& game, vector<string> inst)
{
        string      temp, code;
        long        send, n;
        char        name;

        stringstream    ss(inst[i]);
        if (i < 0 || i > (int) inst.size() - 1) return (false);
        ss >> code;
        if (code == "add")  ss >> name >> temp, game[name] += get_value(game, temp);
        if (code == "mul")  ss >> name >> temp, game[name] *= get_value(game, temp);
        if (code == "mod")  ss >> name >> temp, game[name] %= get_value(game, temp);
        if (code == "set")  ss >> name >> temp, game[name] = get_value(game, temp);
        if (code == "jgz")
        {
            ss >> temp;
            n = get_value(game, temp);
            ss >> temp;
            if (n > 0)  i += get_value(game, temp) - 1;
        }
        if (code == "snd")
        {
            ss >> name;
            send = game[name]; //cout << send << endl;
            remote.push(send);
            count++;
        }
        if (code == "rcv")
        {
            if (native.empty()) return (false);
            ss >> name;
            game[name] = native.front();
            native.pop();
        }
        i += 1;

        return (true);
}

int     recover(vector<string> instructions)
{
        map<char, long> game;
        string          temp, code;
        long            send, n, i;
        char            name;

        i = -1;
        while (1)
        {
            stringstream    ss(instructions[++i]);

            if (i < 0 || i > (int) instructions.size() - 1) break;
            ss >> code;
            if (code == "add")  ss >> name >> temp, game[name] += get_value(game, temp);
            if (code == "mul")  ss >> name >> temp, game[name] *= get_value(game, temp);
            if (code == "mod")  ss >> name >> temp, game[name] %= get_value(game, temp);
            if (code == "set")  ss >> name >> temp, game[name] = get_value(game, temp);
            if (code == "snd")  ss >> name, send = game[name];
            if (code == "jgz")
            {
                ss >> temp;
                n = get_value(game, temp);
                ss >> temp;
                if (n > 0)  i += get_value(game, temp) - 1;
            }
            if (code == "rcv")
            {
                ss >> name;
                if (game[name]) return ((int) send);
            }
        }

        return (-1);
}

long    get_value(map<char, long>& game, string s)
{
        int     x;

        if (stringstream(s) >> x)   return (x);
        return game[s[0]];
}
