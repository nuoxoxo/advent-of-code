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
#include "utility"
#include "vector"
#include "bitset"
#include "map"
#include "set"

std::vector< std::string >  find_all_perm_binstr(int n);
std::set< long >            apply_mask_on_binstr(std::string m, std::string s);
std::string                 apply_mask(std::string m, std::string s);
long                        sum_map(std::map<long, long> m);
long                        bin_to_long(std::string s);

//  DRIVE

int     main()
{
        std::map<long, long>::iterator  itmap;
        std::map<long, long>            mem_1;
        std::map<long, long>            mem_2; // final err fix: map<int, long>
        std::set<long>::iterator        itset;       
        std::set<long>                  adr_to_write;
        std::string                     val_binary;
        std::string                     adr_binary;
        std::string                     line;
        std::string                     mask;
        std::string                     s;
        long                            val_origin;
        long                            val_masked;
        long                            adr;

        while (std::getline(std::cin, line))
        {
            std::stringstream   ss(line);

            ss >> s;
            if (s == "mask")    ss >> s >> mask;
            else
            {
                adr = stol(s.substr(4));
                ss >> s >> val_origin;

                //  Part 1

                val_binary = apply_mask
                    ( mask, std::bitset<36>(val_origin).to_string() );
                val_masked = bin_to_long(val_binary);
                itmap = mem_1.find(adr);
                if (itmap == mem_1.end())
                    mem_1.insert(std::make_pair(adr, val_masked));
                else
                    mem_1[adr] = val_masked;

                //  Part 2

                adr_binary = std::bitset<36>(adr).to_string();
                adr_to_write = apply_mask_on_binstr(mask, adr_binary);
                itset = adr_to_write.begin();
                while (itset != adr_to_write.end())
                {
                    itmap = mem_2.find(*itset);
                    if (itmap == mem_2.end())
                        mem_2.insert(std::make_pair(*itset, val_origin));
                    else
                        mem_2[*itset] = val_origin;
                    itset++;
                }
            }
        }
        std::cout << "Star 1 : " << sum_map(mem_1) << std::endl;
        std::cout << "Star 2 : " << sum_map(mem_2) << std::endl;

        return (0);
}

//

std::set<long> apply_mask_on_binstr(std::string mask, std::string adr_binary)
{
        std::vector< std::string >  all;
        std::vector< int >          bitpos;
        std::set< long >            res;
        int                         total_bitset;
        int                         i, j;

        i = -1;
        total_bitset = 0;
        while (++i < (int) mask.length())
        {
            if (mask[i] == '1') adr_binary[i] = '1';
            if (mask[i] == 'X')
            {
                total_bitset++;
                bitpos.push_back(i);
            }
        }
        all = find_all_perm_binstr(total_bitset);
        i = -1;
        while (++i < (int) all.size())
        {
            j = -1;
            while (++j < (int) bitpos.size())
                adr_binary[bitpos[j]] = all[i][36 - j - 1];
            res.insert(bin_to_long(adr_binary));
        }

        return (res);
}

std::vector < std::string > find_all_perm_binstr(int n)
{
        std::vector< std::string >  all_bins;
        int                         i = -1;

        std::string s;
        while (++i < pow(2, n))
        {
            s = std::bitset<36>(i).to_string();
            all_bins.push_back(s);
        }

        return (all_bins);
}

long    bin_to_long(std::string s)
{
        long    res;

        if (s.find('1') == std::string::npos) res = 0;
        else    res = stol(s.substr(s.find('1')), 0, 2);

        return (res);
}

std::string apply_mask(std::string mask, std::string val_binary)
{
        int     i = -1;

        while (++i < (int) mask.length())
            if (mask[i] != 'X') val_binary[i] = mask[i];

        return (val_binary);
}

long    sum_map(std::map<long, long> m)
{
        std::map<long, long>::iterator  i;
        long    total;

        total = 0;
        for (i = m.begin(); i != m.end(); i++)
            total += i->second;

        return (total);
}
