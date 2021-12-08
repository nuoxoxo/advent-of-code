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

int     main(void)
{
        const int   xmas = 20201227;
        const int   subj = 7;
        long        key;
        int         loop_size_card, loop_size_door;
        int         pubk_card, pubk_door, i;

        std::cin >> pubk_card >> pubk_door;
        loop_size_card = loop_size_door = 0;
        key = 1;
        i = 0;
        while (1)
        {
            if (key == pubk_card) loop_size_card = i;
            if (key == pubk_door) loop_size_door = i;
            if (loop_size_card && loop_size_door) break;
            key *= subj;
            key %= xmas;
            i++;
            //std::cout << "i : " << i << " - key : " << key << "\n";
        }
        key = 1;
        i = 0;
        while (i < loop_size_card)
        {
            key *= pubk_door;
            key %= xmas;
            i++;
            //std::cout << "i : " << i << " - key : " << key << "\n";
        }
        std::cout << "Star 1 : " << std::endl;
        std::cout << "Loop size of card  : " << loop_size_card << std::endl;
        std::cout << "Loop size of door  : " << loop_size_door << std::endl;
        std::cout << "Encr key card/door : " << key << std::endl;
}
