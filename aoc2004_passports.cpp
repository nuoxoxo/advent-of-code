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
#include "sstream"
#include "utility"
#include "string"

std::vector< std::pair< std::string, std::string> >
        make_person(std::string line);
void    show_pax(std::vector< std::vector< std::pair< std::string, std::string > > > pax);
bool    star_alpha(std::vector< std::pair< std::string, std::string > > p);
bool    star_omega(std::vector< std::pair< std::string, std::string > > p);
bool    is_passportid(std::string s);
bool    is_haircolor(std::string s);

//  DRIVE

int     main()
{
        std::vector< std::vector< std::pair< std::string, std::string > > > pax;
        std::vector< std::pair< std::string, std::string > > person;
        std::string line, s;
        int         count_valid_key;
        int         count_valid_val;
        int         i;

        while (std::getline(std::cin, s))
        {
            if (!s.length())
            {
                person = make_person(line);
                pax.push_back(person);
                if (!std::cin.eof()) line = "\0";
            }
            else line += ' ' + s;
        }
        person = make_person(line); 
        pax.push_back(person);
        //show_pax(pax); // test
        count_valid_key = count_valid_val = i = 0;
        while (i < (int) pax.size())
        {
            if (star_alpha(pax[i])) count_valid_key++;
            if (star_omega(pax[i])) count_valid_val++;
            i++;
        }
        std::cout << "Star 1 : " << count_valid_key << std::endl;
        std::cout << "Star 2 : " << count_valid_val << std::endl;

        return (0);
}

//

bool    star_alpha(std::vector< std::pair< std::string, std::string > > p)
{
        int     count, i, j;
        std::string r[7] = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};

        i = -1;
        count = 0;
        while (++i < (int) p.size())
        {
            j = -1;
            while (++j < 7)
            {
                if (p[i].first == r[j])
                {
                    count++;
                    break;
                }
            }
        }
        if (count == 7) return (true);
        return (false);
}

bool    star_omega(std::vector< std::pair< std::string, std::string > > p)
{
        int             count, n, i;
        std::string     f, s, sub;

        i = -1;
        count = 0;
        while (++i < (int) p.size())
        {
            f = p[i].first;
            s = p[i].second;
            if (f == "byr" || f == "iyr" || f == "eyr" || f == "hgt")       n = stoi(s);
            if (f == "byr" && s.length() == 4 && n <= 2002 && n >= 1920)    count++;
            if (f == "iyr" && s.length() == 4 && n <= 2020 && n >= 2010)    count++;
            if (f == "eyr" && s.length() == 4 && n <= 2030 && n >= 2020)    count++;
            if (f == "pid" && is_passportid(s)) count++;
            if (f == "hcl" && is_haircolor(s))  count++;
            if (f == "ecl" && (
                s == "amb" || s == "blu" || s == "brn" || s == "gry" ||
                s == "grn" || s == "hzl" || s == "oth")) count++;
            if (f == "hgt")
            {
                sub = s.substr(s.length() - 2);
                if ((sub == "cm" && n <= 193 && n >= 150) ||
                    (sub == "in" && n <= 76 && n >= 59)) count++;
            }
        }
        if (count == 7) return (true);
        
        return (false);
}

bool    is_passportid(std::string s)
{
        int     i;

        if (s.length() != 9)    return (false);
        i = -1;
        while (++i < (int) s.length())
        {
            if (!isdigit(s[i])) return (false);
        }

        return (true);
}

bool    is_haircolor(std::string s)
{
        int     i;

        if (s.length() != 7 || s[0] != '#') return (false);
        i = 0;
        while (++i < (int) s.length())
        {
            if (!((s[i] <= '9' && s[i] >= '0') || (s[i] <= 'f' && s[i] >= 'a')))
                return (false);
        }

        return (true);
}

std::vector< 
std::pair< std::string, std::string > > make_person(std::string line)
{
        std::vector< std::pair<std::string, std::string> > person;
        std::string         field, value;
        if (line[0] == 32)  line = line.substr(1);
        std::stringstream   ss(line);
        while (!ss.eof())
        {
            std::getline(ss, field, ':');
            std::getline(ss, value, ' ');
            person.push_back(std::make_pair(field, value));
        }

        return (person);
}

void    show_pax(std::vector< std::vector
< std::pair< std::string, std::string > > > p)
{
        std::string field, value;
        
        std::cout << "\n" << p.size() << " passaengers\n" << std::endl;
        for (int i = 0; i < (int) p.size(); i++) 
        {
            std::cout << "No. " << i << std::endl;
            for (int j = 0; j < (int) p[i].size(); j++)
            {
                std::cout << p[i][j].first << " : ";
                std::cout << p[i][j].second << std::endl;
            }
            std::cout << std::endl;
        }
}
