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
        bool        hit;
        int         xa, xo, ya, yo, dx, dy, i, j, x, y, Y, IV, P1, P2, temp;

        //  parsing

        getline(cin, s);
        sscanf(s.c_str(),
        "target area: x=%i..%i, y=%i..%i\n", &xa, &xo, &ya, &yo);

        //  solve

        /*  Hack from reddit
        there is a definite upper y_0 bound for this problem.
        As the shot comes back down, 
        since it started at y=0 with a velocity of +vy_0. 
        it will always pass through y = 0 with a velocity of -vy_0, 

        So, if -vy_0 is smaller than the lower bound of the target, 
        you'll always overshoot if you go any higher.
        */

        Y = abs(ya) > abs(yo) ? abs(ya) : abs(yo);
        P1 = Y * (Y - 1) / 2; // HACK ? quick formula for pt 1 : brute 
        dx = -1;
        P2 = 0;
        while (++dx < xo + 1)
        {
            dy = -P1 - 1;
            while (++dy < P1 + 1)
            {
                temp = x = y = 0;
                hit = false;
                i = dx;
                j = dy;
                IV = -Y - 1; 
                while (++IV < Y + 1)
                // HACK ? the possible vertical IV depends on ya : brute
                {
                    x += i;
                    y += j;
                    temp = temp > y ? temp : y;
                    if (i > 0)      i--;
                    else if (i < 0) i++;
                    j--;
                    if (x <= xo && x >= xa && y <= yo && y >= ya)   hit = true;
                }
                if (hit)    P2 += 1;
                /*
                if (hit)
                {
                    cout << P2 << ' ' << IV << endl;
                }
                */
            }
        }

        cout << "Star 1: " << P1 << endl;
        cout << "Star 2: " << P2 << endl;

        return (0);
}
