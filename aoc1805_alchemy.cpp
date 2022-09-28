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
#include "limits"   // int  n = std::numeric_limits<double>::infinity();
// double n = std::numeric_limits<int>::max(); <----- use max() for <int>

//  DRIVE

int     count_remaining_units(std::vector<char> arr);
int     count_polymer(int c, std::vector<char> arr);
void    show_array(std::vector<char> arr);

int     main()
{
        std::vector<char>   arr;
        char                c;
        int                 shortest_polymer;
        int                 remaining_units;
        int                 count;

        while (std::cin >> c)   arr.push_back(c);
        remaining_units = count_remaining_units(arr);
        shortest_polymer = std::numeric_limits<int>::max();
        c = 'A';
        while (c < 'Z' + 1)
        {
            count = count_polymer(c++, arr);
            std::cout << "Polymer length removing ";
            std::cout << c << '/' << (char) (c + 32);
            std::cout << " : " << count << std::endl;
            if (shortest_polymer > count)   shortest_polymer = count;
            //c++;
        }
        std::cout << "Star 1 : " << remaining_units << std::endl;
        std::cout << "Star 2 : " << shortest_polymer << std::endl;
        return (0);
}

//

void    show_array(std::vector<char> arr)
{
        int i = 0;

        while (i < (int) arr.size())    std::cout << arr[i++];
        std::cout << std::endl;
}

int     count_polymer(int c, std::vector<char> arr)
{
        while (1)
        {
            int i = 0;
            while (i < (int) arr.size())
            {
                if (c == arr[i] || c + 32 == arr[i])
                {
                    arr.erase(arr.begin() + i);
                    break;
                }
                i++;
            }
            if (i == (int) arr.size())  break;
        }
        /*
        show_array(arr);
        */
        return (count_remaining_units(arr));
}

int     count_remaining_units(std::vector<char> arr)
{
        while (1)
        {
            int i = 0;
            while (i < (int) arr.size())
            {
                if (arr[i] - arr[i + 1] == 32 || arr[i + 1] - arr[i] == 32)
                {
                    arr.erase(arr.begin() + i + 1);
                    arr.erase(arr.begin() + i);
                    break;
                }
                i++;
            }
            if (i == (int) arr.size())  break;
        }
        return ((int) arr.size());
}
