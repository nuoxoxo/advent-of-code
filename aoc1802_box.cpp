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
#include <vector>

int     seen(char c, std::vector< char > arr);
int     post(std::string s1, std::string s2);

// DRIVE

int     main (void)
{
        std::vector< std::string >  id;
        std::string                 s;
        int                         count, i, j;
        int                         doubler = 0;
        int                         tripler = 0;
        int                         checksum;
        int                         p;

        // Part 1

        while (std::cin >> s)
        {
            std::vector< char > temp;
            int doubler_checked = 0;
            int tripler_checked = 0;
            
            id.push_back(s);

            i = 0;
            while (s[i])
            {
                count = 1;
                if (!seen(s[i], temp))
                {       
                    temp.push_back(s[i]);
                    j = i + 1;
                    while (s[j])
                    {
                        if (s[j++] == s[i]) count++;
                    }
                }
                if (count == 2 && !doubler_checked)
                {
                    doubler_checked++;
                    doubler++;
                }
                if (count == 3 && !tripler_checked)
                {
                    tripler_checked++;
                    tripler++;
                }
                i++;
            }
        }
        checksum = doubler * tripler;

        // Part 2

        p = -1;
        i = 0;
        while (i < (int) id.size())
        {
            j = i + 1;
            while (j < (int) id.size() && p < 0)
            {
                p = post(id[i], id[j]);
                j++;
            }
            if (p != -1)    break;
            i++;
        }

        std::cout << "Star 1 : " << checksum << std::endl;
        std::cout << "star 2 : ";

        j = 0;
        while (id[i][j])
        {
            if (j != p)
            std::cout << id[i][j];
            j++;
        }
        std::cout << std::endl;
}

//

int     post(std::string s1, std::string s2)
{
        int count, post, i;

        count = i = 0;
        while (s1[i] && s2[i])
        {
            if (s1[i] - s2[i])
            {
                post = i;
                count++;
            }
            i++;
        }
        if (count == 1) return (post);
        return (-1);
}

int     seen(char c, std::vector< char > arr)
{
        if (std::find(arr.begin(), arr.end(), c) == arr.end())
            return (0);
        return (1);
}
