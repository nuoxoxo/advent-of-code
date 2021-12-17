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

#include <iostream>

using   namespace std;

int     main(void)
{
        string      s;
        bool        landed;
        int         i, j, x, y, xa, xo, ya, yo, dx, dy, temp, steps, Y, IV;
        int         max = 1024;

        getline(cin, s);

        sscanf(s.c_str(),
        "target area: x=%i..%i, y=%i..%i\n", &xa, &xo, &ya, &yo);
        cout << xa << ' ' << xo << ' ' << ya << ' ' << yo << endl; // test
        Y = IV = 0;
        dx = -1 * max - 1;
        while (++dx < max + 1)
        {
            dy = -1 * max - 1;
            while (++dy < max + 1)
            {
                landed = false;
                temp = 0;
                x = 0;
                y = 0;
                i = dx;
                j = dy;
                steps = -1;
                while (++steps < max + 1)
                {
                    x += i;
                    y += j;
                    temp = temp > y ? temp : y;
                    if (i > 0)      i--;
                    else if (i < 0) i++;
                    j--;
                    if (x <= xo && x >= xa && y <= yo && y >= ya)
                        landed = true;
                }
                if (landed) IV++;
                if (landed) Y = temp > Y ? temp : Y;
                if (landed) cout << x << ' ' << y << endl; // test
            }
        }

        cout << "Star 1: " << Y << endl;
        cout << "Star 2: " << IV << endl;

        return (0);
}
