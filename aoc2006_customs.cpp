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
#include "vector"
#include "map"
#include "set"

int     size_everyone(std::vector<std::string> v);
int     size_anyone(std::vector<std::string> v);

//  DRIVE

int     main()
{
        std::vector<std::string> arr;
        std::string s;
        int everyone, anyone;

        anyone = everyone = 0;
        while (std::getline(std::cin, s))
        {
            if (s == "")
            {
                everyone += size_everyone(arr);
                anyone += size_anyone(arr);
                arr.clear();
            }
            else    arr.push_back(s);
        }
        everyone += size_everyone(arr);
        anyone += size_anyone(arr);
        std::cout << "Star 1 : " << anyone << std::endl;
        std::cout << "Star 2 : " << everyone << std::endl;

        return (0);
}

//

int     size_everyone(std::vector<std::string> v)
{
        std::map<char,int>::iterator    it;
        std::map<char, int>             q;
        int                             len;
        int                             i, j;

        i = -1;
        while (++i < (int) v.size())
        {
            j = -1;
            while (++j < (int) v[i].length())
            {
                it = q.find(v[i][j]);
                if (it == q.end())  q.insert(std::make_pair(v[i][j], 1));
                else                q[v[i][j]] += 1;
            }
        }
        len = 0;
        it = q.begin();
        while (it != q.end())
        {
            if (it->second == (int) v.size())   len++;
            it++;
        }

        return (len);
}

int     size_anyone(std::vector<std::string> v)
{
        std::set<char>  q;
        int             i;
        int             j;

        i = -1;
        while (++i < (int) v.size())
        {
            j = -1;
            while (++j < (int) v[i].length())   q.insert(v[i][j]);
        }

        return ((int) q.size());
}
