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

std::vector<int> parseSides(std::string s);

int     main()
{
    int ribbon = 0;
    int paper = 0;
    int minPerim;
    int minSlack;
    std::string s;

    while (std::cin >> s)
    {
        std::vector<int> arr = parseSides(s);
        int total = 0;
        int i = 0;
        int j;

        minPerim = arr[0] * 2 + arr[1] * 2;
        minSlack = arr[0] * arr[1];
        while (i < (int) arr.size() - 1)
        {
            j = i + 1;
            while (j < (int) arr.size())
            {
                int perim = arr[i] * 2 + arr[j] * 2;
                int slack = arr[i] * arr[j];

                if (minSlack > slack)
                    minSlack = slack;
                if (minPerim > perim)
                    minPerim = perim;
                total += 2 * arr[i] * arr[j];
                j++;
            }
            i++;
        }
        ribbon += arr[0] * arr[1] * arr[2] + minPerim;
        total += minSlack;
        paper += total; 
    }    

    std::cout
        << "Star 1 : " << paper << '\n' 
        << "Star 2 : " << ribbon << '\n';
}

//

std::vector<int> parseSides(std::string s)
{
    std::stringstream   ss(s);
    std::vector<int>    arr;
    int val;

    while (ss >> val)
    {
        arr.push_back(val);
        if (ss.peek() == 'x')   ss.ignore();
    }

    return (arr);
}
