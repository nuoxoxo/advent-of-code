/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

std::vector <std::pair<char, int> 
            >sort_vect_of_pairs(std::vector<std::pair<char, int> > v);
std::string decrypt(std::vector<std::string> v, int id);
std::string find_5_chars(std::vector<std::string> v);
int         find_north_pole_object_store(std::string s);

//  DRIVE

int     main(void)
{
        std::vector<std::vector<std::string> >
                                    encrypted_name;
        std::vector<std::string>    decrypted_name;
        std::vector<std::string>    checksum;
        std::vector<std::string>    temp_in;
        std::vector<int>            sector_id;
        std::vector<int>            passed;
        std::string                 s;
        int                         count, n, i;

        //  Parsing

        while (std::cin >> s)
            temp_in.push_back(s);
        i = -1;
        while (++i < (int) temp_in.size())
        {
            std::stringstream           ss(temp_in[i]);
            std::vector<std::string>    temp_ss;
            while (std::getline(ss, s, '-'))
                temp_ss.push_back(s);
            encrypted_name.push_back(temp_ss); 
            s = temp_ss[(int) temp_ss.size() - 1];
            sector_id.push_back(atoi(s.c_str()));
            checksum.push_back(s.substr(4, 5));
        }

        /*  Star 1  */

        count = i = 0;
        while (i < (int) encrypted_name.size())
        {
            if (find_5_chars(encrypted_name[i]) == checksum[i])
                count += sector_id[i];
            i++;
        }

        /*  Star 2  */

        i = -1;
        while (++i < (int) encrypted_name.size())
        {
            std::string temp = decrypt(encrypted_name[i], sector_id[i]);
            decrypted_name.push_back(temp);
        }
        n = i = -1;
        while (++i < (int) decrypted_name.size())
        {
            if (find_north_pole_object_store(decrypted_name[i]) > 3)
                passed.push_back(sector_id[i]);
        }
        if (passed.size() == 1) n = passed[0];
        
        std::cout << "Star 1 : " << count << std::endl;
        std::cout << "Star 2 : " << n << std::endl;

        return (0);
}

//

int     find_north_pole_object_store(std::string s)
{
        char    *cs = (char *) s.c_str();
        int     count = 0;
            
        if (strstr(cs, "north"))    count++;
        if (strstr(cs, "pole"))     count++;
        if (strstr(cs, "object"))   count++;
        if (strstr(cs, "store"))    count++;
        if (strstr(cs, "stored"))   count++;
        if (strstr(cs, "storage"))  count++;

        return (count);
}

std::string decrypt(std::vector<std::string> v, int id)
{
        std::string s;
        int         c;
        int         i, j;

        i = -1;
        while (++i < (int) v.size() - 1)
        {
            j = -1;
            while (++j < (int) v[i].length())
            {
                c = v[i][j] + id % 26;
                if (c > 'z')    s += c - 26;
                else            s += c;
            }
            s += ' ';
        }

        return (s);
}

std::string find_5_chars(std::vector<std::string> v)
{
        std::vector<std::pair<char, int> >  cc;
        int                                 flag, i, j, k;
        std::string                         s;
        
        i = -1;
        while (++i < (int) v.size() - 1)
        {
            j = -1;
            while (++j < (int) v[i].length())
            {
                flag = 0;
                k = -1;
                while (++k < (int) cc.size())
                {
                    if (cc[k].first == v[i][j])
                    {
                        cc[k].second++;
                        flag++;
                        break;
                    }
                }
                if (!flag)
                    cc.push_back(std::make_pair(v[i][j], 0));
            }
        }
        cc = sort_vect_of_pairs(cc);
        i = -1;
        while (++i < 5) s += cc[i].first;

        return (s);
}

std::vector<std::pair<char, int> >
        sort_vect_of_pairs(std::vector<std::pair<char, int> > v)
{
        std::pair<char, int>    temp;
        int                     i = 0;

        while (i < (int) v.size() - 1)
        {
            if (v[i].second < v[i + 1].second)
            {
                temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                i = 0;
            }
            else if (v[i].second == v[i + 1].second && v[i].first > v[i + 1].first)
            {
                temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                i = 0;
            }
            else    i++;
        }
        
        return (v);
}
