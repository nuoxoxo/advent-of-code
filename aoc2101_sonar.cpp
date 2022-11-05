#include "iostream"
#include "vector"

using	namespace std;

int	main(void)
{
        vector<int>	D;
        int		p1, p2, t1, t2, i;

        while (cin >> i)
		D.push_back(i);
        i = -1;
	p1 = 0;
	p2 = 0;
        while (++i < (int) D.size())
        {
            if (i > 0 && D[i] > D[i - 1])
		    ++p1;
	    t1 = D[i - 2] + D[i - 1] + D[i];
	    t2 = D[i - 2] + D[i - 1] + D[i - 3];
            if (i > 2 && t1 > t2)
		    ++p2;
        }
        cout << "Star 1: " << p1 << endl;
        cout << "Star 2: " << p2 << endl;
        return (0);
}
