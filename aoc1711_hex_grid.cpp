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

using namespace std;

int     man(int x, int y);

int     main(void)
{
        string      step, s;
        char        c;
        int         max, end, x, y;

        max = x = y = 0;
        cin >> s;
        stringstream ss(s);
        while (getline(ss, step, ','))
        {
            if (step == "n")
                y += 2;
            if (step == "s")
                y -= 2;
            if (step == "ne")
            {
                x += 1;
                y += 1;
            }
            if (step == "se")
            {
                x += 1;
                y -= 1;
            }
            if (step == "sw")
            {
                x -= 1;
                y -= 1;
            }
            if (step == "nw")
            {
                x -= 1;
                y += 1;
            }
            end = man(x, y);
            max = max < end ? end : max;
        }
        cout << "Star 1 : " << end << endl;
        cout << "Star 2 : " << max << endl;
}

int     man(int x, int y)
{
        return ((abs(x) + abs(y)) / 2);
}
