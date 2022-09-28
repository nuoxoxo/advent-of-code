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

int     newly_encoded_string(std::string s);
int     characters_in_memory(std::string s);

//  DRIVE

int     main()
{
        int             length_minus_memory;
        int             encode_minus_length;
        int             len, mem, enc;
        std::string     s;

        len = mem = enc = 0;
        while (std::cin >> s)
        {
            len += (int) s.length();
            mem += characters_in_memory(s);
            enc += newly_encoded_string(s);
        }
        length_minus_memory = len - mem;
        encode_minus_length = enc - len;
        std::cout << "Star 1 : " << length_minus_memory << std::endl;
        std::cout << "Star 2 : " << encode_minus_length << std::endl;

        return (0);
}

//

int     newly_encoded_string(std::string s)
{
        int     i, encoded;

        encoded = i = 0;
        while (i < (int) s.length())
        {
            if (s[i] == '\"')
            {
                if (!i || i == (int) s.length() - 1)
                    encoded += 3;
                else
                    encoded += 2;
                i++;
            }
            else if (s[i] == '\\')
            {
                i++;
                encoded += 2;
            }
            else
            {
                i++;
                encoded += 1;
            }
        }
        return (encoded);
}

int     characters_in_memory(std::string s)
{
        int     i, memory;

        memory = i = 0;
        while (i < (int) s.length())
        {
            if (s[i] == '\"')
                i++;
            else if (s[i] == '\\')
            {
                i++;
                if (s[i] == 'x')
                    i += 3;
                else
                    i++;
                memory++;
            }
            else
            {
                i++;
                memory++;
            }
        }
        return (memory);
}
