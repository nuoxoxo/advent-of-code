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
#include <set>

using namespace std;

int     main(void)
{
        vector<vector<string>>  formula;
        set<string>             molecules;
        string          temp, src, des, s;
        size_t          it, i;
        int             elements, RnAr, Y;

        while (getline(cin, s) && s != "")
        {
            stringstream    ss(s);
            ss >> src >> temp >> des;
            formula.push_back({src, des});
        }
        cin >> s;
        i = -1;
        while (++i < formula.size())
        {
            it = s.find(formula[i][0]);
            while (it != string::npos)
            {
                string  mol = s;
                mol.replace(it, formula[i][0].length(), formula[i][1]);
                molecules.insert(mol);
                it = s.find(formula[i][0], it + 1);
            }
        }
        cout << "Star 1 : " << molecules.size() << endl;

        RnAr = Y = elements = i = 0;
        while (i < s.length())
        {
            if (s[i] < 91 && s[i] > 64) ++elements;
            if (s[i] == 'Y')            ++Y;
            if (s[i] == 'R')            ++RnAr;
            i++;
        }
        cout << "--\n";
        cout << "molecule length : " << s.length() << endl;
        cout << "total elements : " << elements << endl;
        cout << "RnAr : " << RnAr << end;
        cout << "Y : " << Y << endl;
        cout << "(credit :: u/askalski's chemistry insights)\n--\n";
        RnAr *= 2;
        Y *= 2;
        cout << "Star 2 : " << elements - RnAr - Y - 1 << endl;

        return (0);
}

