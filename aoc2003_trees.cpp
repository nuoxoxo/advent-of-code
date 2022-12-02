#include "iostream"
#include "vector"
#include "string"

int     tree(std::vector< std::string > x, int r, int d);

// Drive

int     main()
{
	std::vector< std::string >	x;
	std::string			s;
	
	int		r, rr;

	while (std::cin >> s)
		x.push_back(s);
	r = tree(x, 3, 1);
	rr = r * tree(x, 1, 1) * tree(x, 5, 1) * tree(x, 7, 1) * tree(x, 1, 2);
	std::cout << "Star 1 : " << r << std::endl;
	std::cout << "Star 2 : " << rr << std::endl;
}

//

int     tree(std::vector< std::string > x, int r, int d)
{
	int     trees, i, j;

	trees = i = j = 0;
	while (i < (int) x.size())
	{
		if (x[i][j] == '#')
			trees++;
		if (j + r < (int) x[i].length())
			j += r;
		else
			j = (j + r) % (int) x[i].length();
		i += d;
	}
	return (trees);
}
