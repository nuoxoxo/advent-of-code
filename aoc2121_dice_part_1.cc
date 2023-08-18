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

using   namespace std;

long    dice(int& D);

int     main()
{
        string  s;
        long    A, B, p1, p2;
        int     D;

        //  parse

        while (getline(cin, s))
        {
            sscanf(s.c_str(), "Player 1 starting position: %li\n", &A);
            sscanf(s.c_str(), "Player 2 starting position: %li\n", &B);
        }

        //  solve

        A--;
        B--;
        D = p1 = p2 = 0;
        while (1)
        {
            A = (A + dice(D) + dice(D) + dice(D)) % 10;
            p1 += A + 1;
            if (p1 > 999 || p2 > 999)   break;
            B = (B + dice(D) + dice(D) + dice(D)) % 10;
            p2 += B + 1;
            if (p1 > 999 || p2 > 999)   break;
        }
        cout << "Star 1: " << min(p1 * D, p2 * D);
        cout << " (" << p1 * D << ", " << p2 * D  << ")\n";

        return (0);
}

long    dice(int& D)
{
        return (++D);
}
