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
        // Part 1

        std::vector<std::vector<int> >  num;
        std::vector<int>                code;
        std::string                     src;
        int                             count, x, y;
        
        count = 1;
        num.resize(3);
        for (int i = 0; i < 3; i++)
        {
            num[i].resize(3);
            for (int j = 0; j < 3; j++)
            {
                num[i][j] = count;
                count++;
            }
        }
        count = 0;
        x = y = 1;
        while (std::cin >> src)
        {
            for (int i = 0; i < (int) src.size(); i++)
            {
                switch(src[i])
                {
                    case 'U':
                        x -= 1;
                        if (x < 0)  x = 0;
                        break;
                    case 'D':
                        x += 1;
                        if (x > 2)  x = 2;
                        break;
                    case 'L':
                        y -= 1;
                        if (y < 0)  y = 0;
                        break;
                    case 'R':
                        y += 1;
                        if (y > 2)  y = 2;
                        break;
                }
            }
            count++;
            code.push_back(num[x][y]);
        }

        std::cout << "Star 1 : ";
        for (int i = 0; i < count; i++)
            std::cout << code[i];
        std::cout << std::endl;

        return (0);
}
