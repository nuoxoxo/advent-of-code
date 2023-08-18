#include "iostream"
#include "sstream"
#include "limits"
#include "vector"

int main()
{
    int zero, one, two, max, pdt, i, j, index;
    char c;
    std::string s;
    std::vector<std::vector<char>> img;

    i = -1;
    while (++i < 6)
    {
        j = -1;
        std::vector<char> temp;
        while (++j < 25)
            temp.push_back('2');
        img.push_back(temp);
    }

    std::cin >> s;
    std::stringstream ss(s);
    max = std::numeric_limits<int>::max();
    index = 0;

    while (index < static_cast<int>(s.length()))
    {
        i = -1;
        while (++i < 6)
        {
            j = -1;
            while (++j < 25)
            {
                ss >> c;
                if (c == '0')
                    zero++;
                if (c == '1')
                    one++;
                if (c == '2')
                    two++;
                index++;
                if (img[i][j] == '2')
                    img[i][j] = c;
            }
        }

        if (max > zero)
        {
            max = zero;
            pdt = one * two;
        }

        zero = one = two = 0;
    }

    std::cout << "Star 1 : " << pdt << std::endl;
    std::cout << "Star 2 : " << std::endl << "--" << std::endl;

    i = -1;
    while (++i < 6)
    {
        j = -1;
        while (++j < 25)
        {
            if (img[i][j] == '0')
                std::cout << ' ';
            if (img[i][j] == '1')
                std::cout << '$';
        }
        std::cout << std::endl;
    }

    std::cout << "--" << std::endl;

    return 0;
}

