/* ******************************************** */
/*                                              */
/*              ~  ~  ~  ~  ~    ~              */
/*               ~    _ ~ _   o>                */
/*              ~  \ / \ / \ /  ~               */
/*               ~  ~      ~    ~               */
/*                                              */
/* ******************************************** */

#include <iostream>
#include <vector>

int     atoi_here_and_now(std::string s);

//  DRIVE

int     main(void)
{
        int                 op, fq, t, f, i;
        int                 toggle, count;
        std::vector< int >  arr_op, arr_fq;
        std::string         s;

        // Part 1

        fq = 0;
        while (std::cin >> s)
        {
            op = atoi_here_and_now(s);
            arr_op.push_back(op);
            fq += op;
        }
        f = fq;

        // Part 2

        toggle = count = fq = i = 0;
        while (i < (int) arr_op.size() && !toggle)
        {
            fq += arr_op[i];
            if (std::find(arr_fq.begin(), arr_fq.end(), fq) != arr_fq.end())
            {
                t = fq;
                toggle = 1;
            }
            arr_fq.push_back(fq);
            count++;
            i++;
            if (i == (int) arr_op.size())
                i = 0;
        }
        std::cout << "Star 1 : " << f << std::endl;
        std::cout << "Star 2 : " << t << " found at step ";
        std::cout << count << std::endl;
}

//

int     atoi_here_and_now(std::string s)
{
        int     sign, tt, i;

        tt = i = 0;
        sign = 1;
        while (s[i])
        {
            if (s[i] == '+')    i++;
            else if (s[i] == '-')
            {
                sign = -1;
                i++;
            }
            tt = tt * 10 + s[i] - '0';
            i++;
        }
        return (sign * tt);
}
