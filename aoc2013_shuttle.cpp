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

using   namespace std;

long    part2(long, string);
int     part1(long, string);

int     main(void)
{
        string      B;
        long        T;

        cin >> T >> B;

        cout << "Star 1: " << part1(T, B) << endl;
        cout << "Star 2: " << part2(T, B) << endl;

        return (0);
}

long    part2(long T, string B)
{
        stringstream    ss(B);
        string          busid;
        long            space, n, i;

        space = stol(B);
        while (1)
        {
            if (T % space)  T ++ ;
            else            break;
        }
        i = 1;
        getline(ss, busid, ',');
        while (getline(ss, busid, ','))
        {
            if (busid != "x")
            {
                n = stol(busid);
                while ((T + i) % n) T += space;
                space *= n;
            }
            i ++ ;
        }

        return (T);
}

int     part1(long T, string B)
{
        stringstream    ss(B);
        string          busid;
        int             diff, min, bus, wait, early;

        wait = 0;
        while (getline(ss, busid, ','))
        {
            if (busid != "x")
            {
                min = stoi(busid);
                bus = min;
                while (min < T) min += bus;
                diff = min - T;
                if (!wait)  wait = diff; 
                else if (wait > diff)
                {
                    wait = diff;
                    early = bus;
                }
            }
        }

        return (wait * early);
}
