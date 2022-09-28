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
#include "utility"

int                 count_after_end(int p, std::vector<std::pair<std::string, std::pair<int, bool> > > i);
int                 count_before_rep(std::vector<std::pair<std::string, std::pair<int, bool> > > i);
std::vector<int>    find_nop_and_jmp(std::vector<std::pair<std::string, std::pair<int, bool> > > i);
bool                check_pos(int p, std::vector<std::pair<std::string, std::pair<int, bool> > > i);
void                put_ops(std::vector<std::pair<std::string, std::pair<int, bool> > > i);

int     main()
{
        std::vector< std::pair< 
        std::string, std::pair< int, bool > > > ins;
        std::vector< int >  pos;
        std::string         s;
        int                 acc_before_rep, acc_after_end, i;

        while (std::cin >> s >> i)
        {
            std::pair< int, bool >  command = std::make_pair(i, false);
            std::pair< std::string, std::pair<int, bool> >
                op = std::make_pair( s, command );
            ins.push_back(op);
        }
        //put_ops(ins); // test
        acc_before_rep = count_before_rep(ins);
        pos = find_nop_and_jmp(ins);
        i = -1;
        while (++i < (int) pos.size())
        {
            if (check_pos(pos[i], ins)) break;
        }
        acc_after_end = count_after_end(pos[i], ins);
        std::cout << "Star 1 : " << acc_before_rep << std::endl;
        std::cout << "Star 2 : " << acc_after_end << std::endl;

        return (0);
}

//

int     count_after_end(int p, std::vector< std::pair< std::string, std::pair< int, bool > > > ins)
{
        int     accumulator, i;

        if (ins[p].first == "nop")  ins[p].first = "jmp";
        else                        ins[p].first = "nop";

        i = accumulator = 0;
        while (i < (int) ins.size())
        {
            if (ins[i].first == "nop")      i += 1;
            else if (ins[i].first == "jmp") i += ins[i].second.first;
            else if (ins[i].first == "acc")
            {
                accumulator += ins[i].second.first;
                i += 1;
            }
        }

        return (accumulator);
}

bool    check_pos(int p, std::vector<std::pair< std::string, std::pair<int, bool> > > ins)
{
        int     i;

        if (ins[p].first == "nop")  ins[p].first = "jmp";
        else                        ins[p].first = "nop";
        i = 0;
        while (i < (int) ins.size())
        {
            if ( ins[i].second.second == true ) return (false);
            else if (ins[i].first == "nop" || ins[i].first == "acc")
            {
                ins[i].second.second = true;
                i += 1;
            }
            else if (ins[i].first == "jmp")
            {
                ins[i].second.second = true;
                i += ins[i].second.first;
            }
        }
        return (true);
}

std::vector< int >  find_nop_and_jmp(std::vector<std::pair< std::string, std::pair< int, bool > > > n)
{
        std::vector< int >  res;
        int                 i;

        i = -1;
        while (++i < (int) n.size())
        {
            if (n[i].first == "nop" || n[i].first == "jmp") res.push_back(i);
        }

        return (res);
}

int     count_before_rep(std::vector< std::pair< std::string, std::pair< int, bool > > > ins)
{
        int     accumulator, i;
        
        i = accumulator = 0;
        while (1)
        {
            if ( ins[i].second.second == true ) break;
            else if ( ins[i].first == "nop" )
            {
                ins[i].second.second = true;
                i += 1;
            }
            else if ( ins[i].first == "jmp" )
            {
                ins[i].second.second = true;
                i += ins[i].second.first;
            }
            else if ( ins[i].first == "acc" )
            {
                accumulator += ins[i].second.first;
                ins[i].second.second = true;
                i += 1;
            }
        }

        return (accumulator);
}

void    put_ops(std::vector< std::pair< 
        std::string, std::pair< int, bool > > > ins)
{
        int     i = -1;
        
        while (++i < (int) ins.size())
        {
            std::cout << ins[i].first << " " << ins[i].second.first << " " << ins[i].second.second << std::endl;
        }
}
