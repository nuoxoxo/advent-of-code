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
#include "vector"

int     main()
{
        std::vector<std::string>    line;
        std::string                 word;
        int                         lights_lit, brightness;
        int                         i, j, x, y;

        //  use a grid of vectors
         
        std::vector< std::vector<int> > grid_1;
        std::vector< std::vector<int> > grid_2;
        
        i = 0;
        while (i < 1000)
        {
            j = 0;
            std::vector<int>    vect;
            while (j < 1000)
            {
                vect.push_back(0);
                j++;
            }
            grid_1.push_back(vect);
            grid_2.push_back(vect);
            i++;
        }
        
        /*
        
        //  we can also use a 2D int grid_1 instead

        const int   ROWS = 1000;
        const int   COLS = 1000;
        int         grid_1[ROWS][COLS];
        int         grid_2[ROWS][COLS];
 
        i = 0;
        while (i < ROWS)
        {
            j = 0;
            while (j < COLS)
            {
                grid_1[i][j] = 0;
                grid_2[i][j] = 0;
                j++;
            }
            i++;
        }
        
        */

        while (std::cin >> word)    line.push_back(word);
        i = 0;
        while (i < (int) line.size()) // ??
        {
            int n;

            if (line[i] == "toggle")
            {
                std::stringstream   start(line[i + 1]);
                std::stringstream   close(line[i + 3]);
                std::vector<int>    pos;

                while (start >> n)
                {
                    pos.push_back(n);
                    if (start.peek() == ',')
                        start.ignore();
                }
                while (close >> n)
                {
                    pos.push_back(n);
                    if (close.peek() == ',')
                        close.ignore();
                }
                x = pos[0];
                while (x < pos[2] + 1)
                {
                    y = pos[1];
                    while (y < pos[3] + 1)
                    {
                        if (grid_1[x][y] == 1)
                            grid_1[x][y] = 0;
                        else
                            grid_1[x][y] = 1;
                        grid_2[x][y] += 2;
                        y++;
                    }
                    x++;
                }
            }
            if (line[i] == "turn")
            {
                std::stringstream   start(line[i + 2]);
                std::stringstream   close(line[i + 4]);
                std::vector<int>    pos;

                while (start >> n)
                {
                    pos.push_back(n);
                    if (start.peek() == ',')
                        start.ignore();
                }
                while (close >> n)
                {
                    pos.push_back(n);
                    if (close.peek() == ',')
                        close.ignore();
                }
                x = pos[0];
                while (x < pos[2] + 1)
                {
                    y = pos[1];
                    while (y < pos[3] + 1)
                    {
                        if (line[i + 1] == "on")
                        {
                            grid_1[x][y] = 1;
                            grid_2[x][y] += 1;
                        }
                        else
                        {
                            grid_1[x][y] = 0;
                            if (grid_2[x][y] - 1 < 0)
                                grid_2[x][y] = 0;
                            else
                                grid_2[x][y] -= 1;
                        }
                        y++;
                    }
                    x++;
                }
            }
            if (line[i] == "toggle")
                i += 4;
            else
                i += 5;
        }
        lights_lit = brightness = i = 0;
        while (i < 1000)
        {
            j = 0;
            while (j < 1000)
            {
                if (grid_1[i][j] == 1)
                    lights_lit++;
                brightness += grid_2[i][j];
                j++;
            }
            i++;
        }
        std::cout << "Star 1 : " << lights_lit << '\n';
        std::cout << "Star 2 : " << brightness << std::endl;
}
