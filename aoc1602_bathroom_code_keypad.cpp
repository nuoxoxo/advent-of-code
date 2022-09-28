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
#include "vector"

int     main()
{
        // Part 2
        
        std::vector<std::string>    key;
        std::vector<char>           code;
        std::string                 src;
        std::string                 row0 = "00100";
        std::string                 row1 = "02340";
        std::string                 row2 = "56789";
        std::string                 row3 = "0ABC0";
        std::string                 row4 = "00D00";
        int                         count, x, y;

        key.push_back(row0);
        key.push_back(row1);
        key.push_back(row2);
        key.push_back(row3);
        key.push_back(row4);
        count = y = 0;
        x = 2;
        while (std::cin >> src)
        {
            for (int i = 0; i < (int) src.size(); i++)
            {
                std::cout << src[i] << '\n';
                switch(src[i])
                {
                    case 'U':
                        if (x - 1 < 0 || key[x - 1][y] == 48)
                            continue;
                        else
                            x -= 1;
                        break;
                    case 'D':
                        if (x + 1 > 4 || key[x + 1][y] == 48)
                            continue;
                        else
                            x += 1;
                        break;
                    case 'L':
                        if (y - 1 < 0 || key[x][y - 1] == 48)
                            continue;
                        else
                            y -= 1;
                        break;
                    case 'R':
                        if (y + 1 > 4 || key[x][y + 1] == 48)
                            continue;
                        else
                            y += 1;
                        break;
                }
            }
            code.push_back(key[x][y]);
            count++;
        }

        std::cout << "Star 2 : ";
        for (int i = 0; i < count; i++)
        {
            std::cout << code[i];
        }
        std::cout << std::endl;
        
        return (0);
}
