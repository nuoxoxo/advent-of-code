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

//  first time using tuple / set of tuples

#include "iostream"
#include "sstream"
#include "tuple"
#include "set"

using   namespace std;

void    get_range(int& L, int& R);

int     main(void)
{
        set<tuple<int, int, int>>   S;
        string                      O, T; // on/off, tuple str
        int                         x, y, z, xa, xo, ya, yo, za, zo;

        while (cin >> O >> T)
        {
            sscanf(T.c_str(), 
            "x=%i..%i,y=%i..%i,z=%i..%i", &xa, &xo, &ya, &yo, &za, &zo);
            get_range(xa, xo);
            get_range(ya, yo);
            get_range(za, zo);
            x = xa - 1;
            while (++x < xo + 1)
            {
                y = ya - 1;
                while (++y < yo + 1)
                {
                    z = za - 1;
                    while (++z < zo + 1)
                    {
                        if (O == "on")  S.insert(make_tuple(x, y, z));
                        if (O == "off") S.erase(make_tuple(x, y, z));
                    }
                }
            }
        }
        cout << S.size() << endl;
}

void    get_range(int& L, int& R)
{
        L = L > -50 ? L : -50;
        R = R < 50 ? R : 50;
}
