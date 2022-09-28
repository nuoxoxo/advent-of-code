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
#include "fstream"
#include "sstream"
#include "vector"

int     main()
{
        int tt_dif, tt_div, flag, max, min, i, j, k, a, b;
        std::vector< std::vector<int> > arr;
        
        std::ifstream file("spreadsheet", std::ios::in);
        if (file.good())
        {
            std::string s;
            while (getline(file, s))
            {
                std::stringstream   ss(s);
                std::vector<int>    tmp;
                int                 n;
                while (ss >> n) tmp.push_back(n);
                arr.push_back(tmp);
            }
        }
        tt_dif = i = 0;
        while (i < (int) arr.size())
        {
            j = 1;
            max = min = arr[i][0];
            while (j < (int) arr[i].size())
            {
                if (max < arr[i][j])   max = arr[i][j];
                if (min > arr[i][j])   min = arr[i][j];
                j++;
            }
            i++;
            tt_dif += max - min;
        }
        tt_div = i = 0;
        while (i < (int) arr.size())
        {
            j = 0;
            while (j < (int) arr[i].size() - 1)
            {
                k = j + 1;
                flag = 0;
                while (k < (int) arr[j].size())
                {
                    a = arr[i][j];
                    b = arr[i][k++];
                    if (a > b && !(a % b))
                    {
                            tt_div += a / b;
                            flag++;
                            break;
                    }
                    if (a <= b && !(b % a))
                    {
                            tt_div += b / a;
                            flag++;
                            break;
                    }
                    if (flag)   break;
                }
                j++;
            }
            i++;
        }
        std::cout << "Star 1 : " << tt_dif << std::endl;
        std::cout << "Star 2 : " << tt_div << std::endl;
}
