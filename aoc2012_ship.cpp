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

int     main(void)
{
        std::vector< char > facing;
        std::string         s;
        int                 shx, shy, wpx, wpy;
        int                 val, x, y, f;
        char                dir;
        bool                shift; /// Part 2 only

        facing.push_back('E');
        facing.push_back('S');
        facing.push_back('W');
        facing.push_back('N');
        shx = shy = f = x = y = 0;
        wpx = 10;
        wpy = 1;
        while (std::cin >> s)
        {
            std::stringstream ss(s);
            ss >> dir >> val;
            shift = false;
            if (dir == 'F')
            {
                dir = facing[f];
                shx += wpx * val;
                shy += wpy * val;
                shift = true;
            }
            if (dir == 'L' || dir == 'R') /// Part 2 only
            {
                if (val == 180)
                {
                    wpx = -wpx;
                    wpy = -wpy;
                }
                if ((dir == 'L' && val == 90) ||
                    (dir == 'R' && val == 270))
                {
                    std::swap(wpx, wpy);
                    wpx = -wpx;
                }
                if ((dir == 'L' && val == 270) ||
                    (dir == 'R' && val == 90))
                {
                    std::swap(wpx, wpy);
                    wpy = -wpy;
                }
            }
            switch (dir)
            {
                case 'E':
                    x += val;
                    if (!shift) wpx += val;
                    break;
                case 'W':
                    x -= val;
                    if (!shift) wpx -= val;
                    break;
                case 'N':
                    y += val;
                    if (!shift) wpy += val;
                    break;
                case 'S':
                    y -= val;
                    if (!shift) wpy -= val;
                    break;
                case 'R':
                    val /= 90;
                    if ( f + val > 3 )  f = f + val - 4;
                    else                f += val;
                    break;
                case 'L':
                    val /= 90;
                    if ( f < val )  f = f - val + 4;
                    else            f -= val;
                    break;
            }
        }
        std::cout << "Star 1 : " << abs(x) + abs(y) << std::endl;
        std::cout << "Star 2 : " << abs(shx) + abs(shy) << std::endl;

        return (0);
}
