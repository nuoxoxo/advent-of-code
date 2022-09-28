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
#include "utility"
#include "sstream"
#include "vector"

using   namespace std;

pair<int, int>	couple(vector<vector<vector<pair<int, int>>>>, vector<int>);
void            print_sample(vector<vector<vector<pair<int, int>>>>);
void	        check_num(vector<vector<pair<int, int>>>&, int);
bool	        check_col(vector<vector<pair<int, int>>>);
bool	        check_row(vector<vector<pair<int, int>>>);
bool	        check_win(vector<vector<pair<int, int>>>);
int	        count_score(vector<vector<pair<int, int>>>, int);
vector<vector<vector<pair<int, int>>>>	make_decks(vector<int>);

int     main()
{
	vector<vector<vector<pair<int, int>>>>  decks;
	pair<int, int>				first_and_last;
	vector<int>				call, nums;
	string					s;
	int					n;

	cin >> s;
	stringstream    ss(s);
	while ( getline(ss, s, ',') )   call.push_back(stoi(s));
	while (cin >> n)                nums.push_back(n);
	decks = make_decks(nums);
	//print_sample(decks); // test
	first_and_last = couple(decks, call);

	cout << "Star 1: " << first_and_last.first << endl;
	cout << "Star 2: " << first_and_last.second << endl;

	return (0);
}

//	

pair<int, int>	couple(vector<vector<vector<pair<int, int>>>> decks, vector<int> call)
{
	vector<pair<int, int>>  decks_won;
	int                     win, i, j, k, L, R;

	win = 0;
	i = -1;
	while (++i < call.size())
	{
            j = -1;
            while (++j < decks.size())
            {
                check_num(decks[j], call[i]);
                if (check_win(decks[j]))
                {
                    win++;
		    if (win == 1)
		    L = count_score(decks[j], call[i]);
                    k = -1;
                    while (++k < decks_won.size())
                        if (decks_won[k].first == j)    break;
                    if (k == decks_won.size())
                    {
                        decks_won.push_back(make_pair(j, call[i]));
                        R = count_score(
                            decks[ decks_won.back().first ],
                            decks_won.back().second);
                    }
                }
            }
        }
        return (make_pair(L, R));
}

int	count_score(vector<vector<pair<int, int>>> deck, int caller)
{
	int	um, i, j;

	um = 0;
	i = -1;
	while (++i < (int) deck.size())
	{
            j = -1;
            while (++j < (int) deck[i].size())
                if (!deck[i][j].second)	um += deck[i][j].first;
	}
	return (caller * um);
}

void	check_num(vector<vector<pair<int, int>>>& deck, int caller)
{
	int	i, j;

	i = -1;
	while (++i < (int) deck.size())
	{
            j = -1;
            while (++j < (int) deck[i].size())
                if (caller == deck[i][j].first) deck[i][j].second++;
	}
}

bool	check_win(vector<vector<pair<int, int>>> deck)
{
	if (check_row(deck) || check_col(deck))	return (true);
	return (false);
}

bool	check_col(vector<vector<pair<int, int>>> deck)
{
	int	ye, r, c;

	c = -1;
	while (++c < (int) deck[0].size())
	{
            ye = 0;
            r = -1;
            while (++r < (int) deck[0].size())
                if (deck[r][c].second)	++ye;
            if (ye == (int) deck[0].size()) return (true);
        }
	return (false);
}

bool	check_row(vector<vector<pair<int, int>>> deck)
{
	int     ye, r, c;

	r = -1;
	while (++r < (int) deck.size())
	{
            ye = 0;
            c = -1;
	    while (++c < (int) deck[r].size())
                if (deck[r][c].second)	++ye;
            if (ye == (int) deck[r].size()) return (true);
	}
	return (false);
}

vector<vector<vector<pair<int, int>>>>	make_decks(vector<int> nums)
{
	vector<vector<vector<pair<int, int>>>>	decks;
	int					n, i, j, k;

	n = i = -1;
	while (++i < (int) nums.size() / 25)
	{
            vector<vector<pair<int, int>>>  deck;

            j = -1;
            while (++j < 5)
	    {
                vector<pair<int, int>>	row;

                k = -1;
                while (++k < 5)
                    row.push_back(make_pair(nums[++n], 0));
                deck.push_back(row);
            }
            decks.push_back(deck);
        }
	return (decks);
}

void	print_sample(vector<vector<vector<pair<int, int>>>> decks)
{
	int z = (int) decks.size() - 1;

	cout << "--" << endl;
	cout << "(bug check)\n" << endl;
	cout << "how many decks: " << z + 1 << endl;
	cout << "check 1st element: " << decks[0][0][0].first;
	cout << '.' << decks[0][0][0].second << endl;
	cout << "check end element: " << decks[z][4][4].first;
	cout << '.' << decks[z][4][4].second << endl;
	cout << "--" << endl;
}
