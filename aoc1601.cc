#include "iostream"
#include "vector"
#include "utility"
#include "algorithm"

using	namespace std;

int	main()
{
	vector<string>		vs;
	vector<pair<int, int>>	vp;

	string		s;
	int		face = 0, x = 0, y = 0;
	int		n;

	bool		ok = false;
	int		crossx, crossy;
	int		startx, endx;
	int		starty, endy;

	while (cin >> s)
	{
		vs.push_back(s);
	}
	for (string cmd: vs)
	{
		n = stoi(cmd.substr(1, cmd.length() - 1));

		startx = x;
		starty = y;

		if (cmd[0] == 'L')
		{
			if (face == 0)
				x -= n;
			if (face == 2)
				x += n;
			if (face == 1)
				y += n;
			if (face == 3)
				y -= n;
			--face;
			face = face < 0 ? 3 : face;
		}
		if (cmd[0] == 'R')
		{
			if (face == 0)
				x += n;
			if (face == 2)
				x -= n;
			if (face == 1)
				y -= n;
			if (face == 3)
				y += n;
			++face;
			face %= 4;
		}

		//	part 2

		endx = max(startx , x);
		startx = min(startx, x);

		endy = max(starty, y);
		starty = min(starty , y);

		if (ok)
		{
			continue ;
		}
		while (++startx < endx && !ok)
		{
			if (find(vp.begin(), vp.end(), make_pair(startx, y)) == vp.end())
				vp.push_back(make_pair(startx, y));
			else
			{
				if (!ok)
				{
					crossx = startx;
					crossy = y;
					ok = true;
				}
			}
		}
		while (++starty < endy && !ok)
		{
			if (find(vp.begin(), vp.end(), make_pair(x, starty)) == vp.end())
				vp.push_back(make_pair(x, starty));
			else
			{
				if (!ok)
				{
					crossx = x;
					crossy = starty;
					ok = true;
				}
			}
		}
	}
	cout << "Star 1: " << abs(x) + abs(y) << endl;
	cout << "Star 2: " << abs(crossx) + abs(crossy) << endl;
}
