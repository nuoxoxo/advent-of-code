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
#include "utility"  // std::pair, std::make_pair
#include "vector"

int     findID(std::vector<std::vector<int> > grid,
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > v);
int     sumgt2(int size, 
        std::vector< std::vector<int> > arr);

std::vector<std::vector<int> >  build_nil_grid(int size);
extern const int                LEN = 1000;

//  DRIVE

int     main()
{
        int                         i, x, y;
        std::string                 word;
        std::pair<int, int>         root;
        std::pair<int, int>         span;
        std::vector< 
            std::vector<int> >      grid;
        std::vector<std::pair<
            std::pair<int, int>,
            std::pair<int, int> > > claims;

        grid = build_nil_grid(LEN);
        
        i = 0;
        while (std::cin >> word)
        {
            if (i == 2)
            {
                std::stringstream   ss(word);
                ss >> x;
                if (ss.peek() == ',')   ss.ignore();
                ss >> y;
                root = std::make_pair(x, y);
            }
            if (i == 3)
            {
                std::stringstream   ss(word);
                ss >> x;
                if (ss.peek() == 'x')   ss.ignore();
                ss >> y;
                span = std::make_pair(x, y);
                std::pair< std::pair<int, int>, std::pair<int, int> >
                    claim = std::make_pair(root, span);
                claims.push_back(claim);
            }
            i++;
            if (i == 4) i = 0;
        }
        
        i = -1;
        while (++i < (int) claims.size())
        {
            x = claims[i].first.first - 1;
            while (++x < claims[i].first.first + claims[i].second.first)
            {
                y = claims[i].first.second - 1;
                while (++y < claims[i].first.second 
                    + claims[i].second.second)  grid[x][y] += 1;
            }
        }
        i = findID(grid, claims);
        std::cout << "Star 1 : " << sumgt2(LEN, grid) << std::endl;
        std::cout << "Star 2 : " << i << std::endl;

        return (0);
}

//

int     findID(std::vector<std::vector<int> > grid,
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > v)
{
        int     flag, i, x, y;

        i = -1;
        while (++i < (int) v.size())
        {
            x = v[i].first.first - 1;
            flag = 0;
            while (++x < v[i].first.first + v[i].second.first)
            {
                y = v[i].first.second - 1;
                while (++y < v[i].first.second + v[i].second.second)
                {
                    if ((grid[x][y]) != 1)
                    {
                        flag++;
                        break;
                    }
                }
                if (flag)   break;
            }
            if (!flag)  break;
        }
        return (i + 1);
}

int     sumgt2(int n,
        std::vector< std::vector<int> > a)
{
        int     count, x, y;

        count = x = 0;
        while (x < n)
        {
            y = 0;
            while (y < n)
            {
                if (a[x][y] > 1)    count++;
                y++;
            }
            x++;
        }
        return (count);
}

std::vector< std::vector<int> >     build_nil_grid(int n)
{
    std::vector< std::vector<int> > grid;
    int                             a, b;
    
    a = 0;
    while (a < n)
    {
        b = 0;
        std::vector<int>    temp;
        while (b < n)
        {
            temp.push_back(0);
            b++;
        }
        grid.push_back(temp);
        a++;
    }
    return (grid);
}
