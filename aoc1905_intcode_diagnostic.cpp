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

//  DRIVE

int     icc(std::vector<int> vect, int input);

int     main()
{
        std::vector<int>    lines;
        std::string         s;
        int                 output1, output2, n;
        const int           input1 = 1;
        const int           input2 = 5;

        std::cin >> s;
        std::stringstream ss(s);
        while (ss >> n)
        {
            if (ss.peek() == ',')   ss.ignore();
            lines.push_back(n);
        }
        output1 = icc(lines, input1);
        output2 = icc(lines, input2);
        std::cout << "Star 1 : " << output1 << std::endl;
        std::cout << "Star 2 : " << output2 << std::endl;

        return (0);
}

int     icc(std::vector<int> a, int input)
{
        int res, tmp, x, y, i;
        const int halt = 99;

        std::cout << "==> Intcode icc with input : ";
        std::cout << input << " <==" << std::endl;
        i = 0;
        while (1)
        {
            /*
            std::cout << "i : " << i << " - ";
            std::cout << a[i] << std::endl; // Debugging
            */
            if (a[i] < 100)
            {
                switch (a[i])
                {
                    case halt:
                        std::cout << std::endl; //  nl for tst
                        return (res);
                    case 1:
                        a[a[i + 3]] = a[a[i + 1]] + a[a[i + 2]];
                        i += 4;
                        break;
                    case 2:
                        a[a[i + 3]] = a[a[i + 1]] * a[a[i + 2]];
                        i += 4;
                        break;
                    case 3:
                        a[a[i + 1]] = input;
                        i += 2;
                        break;
                    case 4:
                        std::cout << "Output at i of: " << i;
                        std::cout << " : " << a[a[i + 1]] << std::endl;
                        res = a[a[i + 1]];
                        i += 2;
                        break;
                    case 5:
                        if (a[a[i + 1]])    i = a[a[i + 2]];
                        else                i += 3;
                        break;
                    case 6:
                        if (!a[a[i + 1]])   i = a[a[i + 2]];
                        else                i += 3;
                        break;
                    case 7:
                        if (a[a[i + 1]] < a[a[i + 2]])  a[a[i + 3]] = 1;
                        else                            a[a[i + 3]] = 0;
                        i += 4;
                        break;
                    case 8:
                        if (a[a[i + 1]] == a[a[i + 2]]) a[a[i + 3]] = 1;
                        else                            a[a[i + 3]] = 0;
                        i += 4;
                        break;
                    default:
                        std::cout << "Wrong single-digit turn at i of ";
                        std::cout << i << " : " << a[i] << std::endl;
                        i += 4;
                        break;
                }
            }
            else
            {
                tmp = a[i];
                switch (tmp % 10)
                {
                    case 1:
                        tmp /= 100;
                        if (tmp % 10 == 1)  x = a[i + 1];
                        else                x = a[a[i + 1]];
                        tmp /= 10;
                        if (tmp == 1)       y = a[i + 2];
                        else                y = a[a[i + 2]];
                        a[a[i + 3]] = x + y;
                        i += 4;
                        break;
                    case 2:
                        tmp /= 100;
                        if (tmp % 10 == 1)  x = a[i + 1];
                        else                x = a[a[i + 1]];
                        tmp /= 10;
                        if (tmp == 1)       y = a[i + 2];
                        else                y = a[a[i + 2]];
                        a[a[i + 3]] = x * y;
                        i += 4;
                        break;
                     case 3:
                        tmp /= 100;
                        if (!tmp)           a[a[i + 1]] = input;
                        else                a[i + 1] = input;
                        i += 2;
                        break;
                     case 4:
                        tmp /= 100;
                        if (!tmp)
                        {
                            res = a[a[i + 1]];
                            std::cout << "Output at i of " << i;
                            std::cout << " : " << a[a[i + 1]] << std::endl;
                        }
                        else
                        {
                            res = a[i + 1];
                            std::cout << "Output at i of " << i;
                            std::cout << " : " << a[i + 1] << std::endl;
                        }
                        i += 2;
                        break;
                     case 5:
                        tmp /= 100;
                        if (!(tmp % 10))        x = a[a[i + 1]];
                        else                    x = a[i + 1];
                        if (!(tmp / 10 % 10))   y = a[a[i + 2]];
                        else                    y = a[i + 2];
                        if (x != 0)             i = y;
                        else                    i += 3;
                        break;
                     case 6:
                        tmp /= 100;
                        if (!(tmp % 10))        x = a[a[i + 1]];
                        else                    x = a[i + 1];
                        if (!(tmp / 10 % 10))   y = a[a[i + 2]];
                        else                    y = a[i + 2];
                        if (x == 0)             i = y;
                        else                    i += 3;
                        break;
                     case 7:
                        tmp /= 100;
                        if (!(tmp % 10))        x = a[a[i + 1]];
                        else                    x = a[i + 1];
                        if (!(tmp / 10 % 10))   y = a[a[i + 2]];
                        else                    y = a[i + 2];
                        if (x < y)
                        {
                            if (!(tmp / 100 % 10))  a[a[i + 3]] = 1;
                            else                    a[i + 3] = 1;
                        }
                        else
                        {
                            if (!(tmp / 100 % 10))  a[a[i + 3]] = 0;
                            else                    a[i + 3] = 0;
                        }
                        i += 4;
                        break;
                     case 8:
                        tmp /= 100;
                        if (!(tmp % 10))        x = a[a[i + 1]];
                        else                    x = a[i + 1];
                        if (!(tmp / 10 % 10))   y = a[a[i + 2]];
                        else                    y = a[i + 2];
                        if (x == y)
                        {
                            if (!(tmp / 100 % 10))  a[a[i + 3]] = 1;
                            else                    a[i + 3] = 1;
                        }
                        else
                        {
                            if (!(tmp / 100 % 10))  a[a[i + 3]] = 0;
                            else                    a[i + 3] = 0;
                        }
                        i += 4;
                        break;
                     default:
                        std::cout << "Wrong multi-digit turn at i of ";
                        std::cout << i << " : " << a[i] << std::endl;
                        i += 4;
                        break;
                }
            }
        }
        //return (res); //  obsolete
}
