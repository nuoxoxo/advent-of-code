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
#include <string>
#include <map>

#include <vector>

using   namespace std;

string          GetMD5String_stretching(string s, int times);
static string   GetMD5String(string s);

//bool            check_next_1000_hashes_part_2(string s, int i, char c, int times);
bool            check_next_1000_hashes_part_2(map<int, char>& mp, string s, int i, char c, int times);
bool            check_next_1000_hashes_part_1(string s, int i, char c);
char            fetch_3time_char(string md5string);
bool            check_5time_char_part_2(map<int, char>& mp, int index, string s, char c);
bool            check_5time_char(string s, char c);
int             count_part_2(string s, int times);
int             count_part_1(string s);

//  DRIVE

int     main(int argc, char **argv)
{
        string      s, salt;
        int         count_1 = 0;
        int         count_2 = 0;

        if (argc != 2)  return (-1);
        salt = argv[1];

        //  Part 1

        //count_1 = count_part_1(salt);
        cout << "Star 1 : " << count_1 << endl;
        cout << "Part 2 takes forever ... \n" << endl;

        //  Part 2

        count_2 = count_part_2(salt, 2017);
        cout << "Star 2 : " << count_2 << endl;

        return (0);
}

string  GetMD5String_stretching(string s, int times)
{
        int     i;

        i = 0;
        while (++i < times + 1) s = GetMD5String(s);

        return (s);
}

int     count_part_2(string salt, int times)
{
        map<int, char>  mp;
        string          s;
        char            c;
        int             i, count;

        //  salt : ahsbgdzn
        //count = 0; i = 0;       //  Yet started

        //  salt : abc
        //count = 14;  i = 4384;  //  Updating...
        //count = 20;  i = 6505;  //  Updating...
        //count = 37;  i = 12003;  //  Updating...
        //count = 37;  i = 14448;  //  Updating...
        //count = 37;  i = 17250;  //  Updating...
        //count = 46;  i = 18225;  //  Updating...
        //count = 47;  i = 19100;  //  Updating...
        //count = 62;  i = 21008;  //  Updating...
        //count = 63;  i = 22121;  //  Updating...
        count = 64;  i = 22311;  //  Updating...
        //count = 32;  i = 8470;  //  Updating...

        //  (start from beginning)

        count = i = 0;
        

        vector<int>     index{10,25,1471,1596,1610,1715,1778,1951,1994,2023,2288,4249,4340,4352
,4533
,4829
,4878
,5014
,5226
,5803
,6878
,7087
,7120
,7137
,7182
,7229
,7280
,7317
,7460
,7841
,8058
,8277
,8472
,8473
,8487
,8550
,8574
,17372
,17438
,17506
,17737
,17768
,18105
,18175
,18210
,18302
,19212
,19236
,19270
,19334
,19346
,19366
,19369
,19471
,19498
,19799
,19880
,19915
,19947
,19950
,20212
,22097
,22122
,22551};


        
        //while (1)
        while (i < index.size())
        {
            //cout << i << endl;
            //s = GetMD5String_stretching(salt + to_string(i), times);
            s = GetMD5String_stretching(salt + to_string(index[i]), times);
            c = fetch_3time_char(s);
            //if (c != 95 && check_next_1000_hashes_part_2(salt, i, c, times))
            /*
            if (c != 95)
            {
                cout << "found triplet of " << c;
                //cout << " at i : " << i << '\n';
                cout << " at i : " << index[i] << '\n';
            }
            */
            //if (c != 95 && check_next_1000_hashes_part_2(mp, salt, i, c, times))
            if (c != 95 && check_next_1000_hashes_part_2(mp, salt, index[i], c, times))
                cout << "count : " << ++count << "\n\n";
            if (count == 64)    break;
            i++;
        }

        return (index[i]);
}

int     count_part_1(string salt)
{
        string  s;
        char    c;
        int     i, count;

        count = i = 0;
        while (1)
        {
            s = GetMD5String(salt + to_string(i));
            c = fetch_3time_char(s);
            
            if (c != 95 && check_next_1000_hashes_part_1(salt, i, c))
                cout << "count : " << ++count << "\n\n";
            if (count == 65)    break;
            i++;
        }

        return (i);
}

bool    check_next_1000_hashes_part_2(map<int, char>& mp, string salt, int n, char c, int times)
{
        string  s, m;
        int     i;

        i = 1;
        while (i < 1001)
        {
            //cout << "inside : " << i << endl;
            if (mp[n + i] == c)
            {
                
                cout << "found in map-index : " << n + i << endl;
                cout << "index : " << n <<endl;
                cout << "prev  : " << s << endl;
                cout << "md5   : " << m << endl;
                
                return (true);
            }
            i++;
        }
        i = 1;
        while (i < 1001)
        {
            s = salt + to_string(n + i);
            m = GetMD5String_stretching(s, times);
            if (check_5time_char_part_2(mp, n + i, m, c))
            {
                mp[n + i] = c;
                
                cout << "added to map-index : " << n + i << '\n';
                cout << "md5   : " << m << '\n';
                cout << "char  : " << c << "\n";
                cout << "i     : " << n << "\n";
                /*
                cout << "index : " << n <<endl;
                cout << "prev  : " << s << endl;
                cout << "md5   : " << m << endl;
                */
                return (true);
            }
            i++;
        }

        return (false);
}

bool    check_next_1000_hashes_part_1(string salt, int index, char c)
{
        string  s, m;
        int     i;

        i = 1;
        while (i < 1001)
        {
            s = salt + to_string(index + i);
            m = GetMD5String(s);
            if (check_5time_char(m, c))
            {
                cout << "index : " << index <<endl;
                cout << "prev  : " << s << endl;
                cout << "md5   : " << m << endl;
                return (true);
            }
            i++;
        }

        return (false);
}

bool    check_5time_char_part_2(map<int, char>& mp, int index, string s, char c)
{
        int     i, j;

        i = -1;
        while (++i < s.length() - 5 + 1)
        {
            j = 0;
            while (s[i + j] == s[i])    j++;
            if (j == 5)
            {
                if (i + j > s.length() - 1 || s[i + j] != s[i])
                {
                    if (s[i] == c)  return (true);
                    else if (!isalnum(mp[index]))
                    {
                        mp[index] = s[i];
                        cout << endl << "md5   : " << s << '\n';
                        cout << "added to map-index : " << index << '\n';
                        cout << "char  : " << s[i] << "\n\n";
                    }
                }
            }
        }

        return (false);
}

bool    check_5time_char(string s, char c)
{
        string  sub = "";
        int     i = 6;

        while (--i) sub += c;
        if (s.find(sub) == s.npos)  return (false);
        return (true);
}

char    fetch_3time_char(string s)
{
        int     i, j;

        i = -1;
        while (++i < s.length() - 3 + 1)
        {
            j = 0;
            while (s[i + j] == s[i])    j++;
            if (j == 3)
            {
                if (i + j > s.length() - 1 || s[i + j] != s[i]) return (s[i]);
                //j++;
            }
        }

        return ((char) 95);
}

/*

//  Part 2
//  salt : abc



index : 10


index : 25

index : 1471

index : 1596

index : 1610
index : 1715

index : 1778

index : 1951

index : 1994

index : 2023

index : 2288
prev  : abc2359
md5   : 4fed3fd7229e0375139e313f555554d5
count : 11

index : 4249
prev  : abc5057
md5   : c763e3dc681483e4888882d4e01a67b6
count : 12

found in map-index : 5057
index : 4340
prev  : 
md5   : 
count : 13

found in map-index : 5057
index : 4352
prev  : 
md5   : 
count : 14

index : 4533
prev  : abc5057
md5   : c763e3dc681483e4888882d4e01a67b6
count : 15

found in map-index : 5057
index : 4829
prev  :
md5   :
count : 16

found in map-index : 5057
index : 4878
prev  : 
md5   : 
count : 17

found in map-index : 5057
index : 5014
prev  : 
md5   : 
count : 18

added to map-index : 6115; value : 2
index : 5226
prev  : abc6115
md5   : a52222258913ae7224fe217fc333cb40
count : 19

found in map-index : 6115
index : 5803
prev  : 
md5   : 
count : 20

added to map-index : 7859
md5   : 5911d278942461111175d67ea80b619e

found in map-index : 7859
index : 6878
prev  : 
md5   : 
count : 21

found in map-index : 7859
index : 7087
prev  : 
md5   : 
count : 22

found in map-index : 7859
index : 7120
prev  : 
md5   : 
count : 23

found in map-index : 7859
index : 7137
prev  : 
md5   : 
count : 24

found in map-index : 7859
index : 7182
prev  : 
md5   : 
count : 25

found in map-index : 7859
index : 7229
prev  : 
md5   : 
count : 26

found in map-index : 7859
index : 7280
prev  : 
md5   : 
count : 27

found in map-index : 7859
index : 7317
prev  : 
md5   : 
count : 28

found in map-index : 7859
index : 7460
prev  : 
md5   : 
count : 29

found in map-index : 7859
index : 7841
prev  : 
md5   : 
count : 30

added to map-index : 8948
md5   : 00d272f8666666e368c964eed8a5f18c

found in map-index : 8948
index : 8058
prev  : 
md5   : 
count : 31

found in map-index : 8948
index : 8277
prev  : 
md5   : 
count : 32

found in map-index : 8948
index : 8472
prev  : 
md5   : 
count : 33

found in map-index : 8948
index : 8473
prev  : 
md5   : 
count : 34

found in map-index : 8948
index : 8487
prev  : 
md5   : 
count : 35

found in map-index : 8948
index : 8550
prev  : 
md5   : 
count : 36

found in map-index : 8948
index : 8574
prev  : 
md5   : 
count : 37

added to map-index : 18355
md5   : 3cccccf58c3a6a3ced39155cda9253bf

found in map-index : 18355
index : 17372
prev  : 
md5   : 
count : 38

found in map-index : 18355
index : 17438
prev  : 
md5   : 
count : 39

found in map-index : 18355
index : 17506
prev  : 
md5   : 
count : 40

found in map-index : 18355
index : 17737
prev  : 
md5   : 
count : 41

found in map-index : 18355
index : 17768
prev  : 
md5   : 
count : 42

found in map-index : 18355
index : 18105
prev  : 
md5   : 
count : 43

found in map-index : 18355
index : 18175
prev  : 
md5   : 
count : 44

found in map-index : 18355
index : 18210
prev  : 
md5   : 
count : 45

found in map-index : 18355
index : 18302
prev  :
md5   :
count : 46

found in map-index : 18355
index : 18302
prev  : 
md5   : 
count : 47

md5   : 52ff1eae704f55555dec14f8e5040b73
added to map-index : 20015
char  : 5

found in map-index : 20015
index : 19212
prev  : 
md5   : 
count : 48

found in map-index : 20015
index : 19236
prev  : 
md5   : 
count : 49

found in map-index : 20015
index : 19270
prev  : 
md5   : 
count : 50

md5   : 39ed4edb214e59811d03ce3666669533
added to map-index : 20330
char  : 6

found in map-index : 20015
index : 19334
prev  : 
md5   : 
count : 51

found in map-index : 20015
index : 19346
prev  : 
md5   : 
count : 52

found in map-index : 20330
index : 19366
prev  : 
md5   : 
count : 53

found in map-index : 20015
index : 19369
prev  : 
md5   : 
count : 54

found in map-index : 20015
index : 19471
prev  : 
md5   : 
count : 55

found in map-index : 20015
index : 19498
prev  : 
md5   : 
count : 56

found in map-index : 20330
index : 19799
prev  : 
md5   : 
count : 57

found in map-index : 20015
index : 19880
prev  : 
md5   : 
count : 58

found in map-index : 20330
index : 19915
prev  : 
md5   : 
count : 59

found in map-index : 20330
index : 19947
prev  : 
md5   : 
count : 60

found in map-index : 20330
index : 19950
prev  : 
md5   : 
count : 61

found in map-index : 20330
index : 20212
prev  : 
md5   : 
count : 62

md5   : 2e559978fffff9ac9c9012eb764c6391
added to map-index : 22859
char  : f

found in map-index : 22859
index : 22097
prev  : 
md5   : 
count : 63

found in map-index : 22859
index : 22122
prev  :
md5   :
count : 64 (???????)

found in map-index : 22859
index : 22551
prev  : 
md5   : 
count : 65 (?????????)
















index : 10
prev  : abc89
md5   : eaa5c17bec47565b98275b404eeeeea6
count : 1

index : 25
prev  : abc89
md5   : eaa5c17bec47565b98275b404eeeeea6
count : 2

index : 1471
prev  : abc2359
md5   : 4fed3fd7229e0375139e313f555554d5
count : 3

index : 1596
prev  : abc2359
md5   : 4fed3fd7229e0375139e313f555554d5
count : 4

index : 1610
prev  : abc2359
md5   : 4fed3fd7229e0375139e313f555554d5
count : 5

index : 1715
prev  : abc2359
md5   : 4fed3fd7229e0375139e313f555554d5
count : 6

index : 1778
prev  : abc2359
md5   : 4fed3fd7229e0375139e313f555554d5
count : 7

index : 1951
prev  : abc2359
md5   : 4fed3fd7229e0375139e313f555554d5
count : 8

index : 1994
prev  : abc2359
md5   : 4fed3fd7229e0375139e313f555554d5
count : 9

index : 2023
prev  : abc2359
md5   : 4fed3fd7229e0375139e313f555554d5
count : 10

index : 2288
prev  : abc2359
md5   : 4fed3fd7229e0375139e313f555554d5
count : 11

index : 4249
prev  : abc5057
md5   : c763e3dc681483e4888882d4e01a67b6
count : 12

found in map-index : 5057
index : 4340
prev  : 
md5   : 
count : 13

found in map-index : 5057
index : 4352
prev  : 
md5   : 
count : 14

index : 4533
prev  : abc5057
md5   : c763e3dc681483e4888882d4e01a67b6
count : 15

found in map-index : 5057
index : 4829
prev  :
md5   :
count : 16

found in map-index : 5057
index : 4878
prev  : 
md5   : 
count : 17

found in map-index : 5057
index : 5014
prev  : 
md5   : 
count : 18

added to map-index : 6115; value : 2
index : 5226
prev  : abc6115
md5   : a52222258913ae7224fe217fc333cb40
count : 19

found in map-index : 6115
index : 5803
prev  : 
md5   : 
count : 20

added to map-index : 7859
md5   : 5911d278942461111175d67ea80b619e

found in map-index : 7859
index : 6878
prev  : 
md5   : 
count : 21

found in map-index : 7859
index : 7087
prev  : 
md5   : 
count : 22

found in map-index : 7859
index : 7120
prev  : 
md5   : 
count : 23

found in map-index : 7859
index : 7137
prev  : 
md5   : 
count : 24

found in map-index : 7859
index : 7182
prev  : 
md5   : 
count : 25

found in map-index : 7859
index : 7229
prev  : 
md5   : 
count : 26

found in map-index : 7859
index : 7280
prev  : 
md5   : 
count : 27

found in map-index : 7859
index : 7317
prev  : 
md5   : 
count : 28

found in map-index : 7859
index : 7460
prev  : 
md5   : 
count : 29

found in map-index : 7859
index : 7841
prev  : 
md5   : 
count : 30

added to map-index : 8948
md5   : 00d272f8666666e368c964eed8a5f18c

found in map-index : 8948
index : 8058
prev  : 
md5   : 
count : 31

found in map-index : 8948
index : 8277
prev  : 
md5   : 
count : 32

found in map-index : 8948
index : 8472
prev  : 
md5   : 
count : 33

found in map-index : 8948
index : 8473
prev  : 
md5   : 
count : 34

found in map-index : 8948
index : 8487
prev  : 
md5   : 
count : 35

found in map-index : 8948
index : 8550
prev  : 
md5   : 
count : 36

found in map-index : 8948
index : 8574
prev  : 
md5   : 
count : 37

added to map-index : 18355
md5   : 3cccccf58c3a6a3ced39155cda9253bf

found in map-index : 18355
index : 17372
prev  : 
md5   : 
count : 38

found in map-index : 18355
index : 17438
prev  : 
md5   : 
count : 39

found in map-index : 18355
index : 17506
prev  : 
md5   : 
count : 40

found in map-index : 18355
index : 17737
prev  : 
md5   : 
count : 41

found in map-index : 18355
index : 17768
prev  : 
md5   : 
count : 42

found in map-index : 18355
index : 18105
prev  : 
md5   : 
count : 43

found in map-index : 18355
index : 18175
prev  : 
md5   : 
count : 44

found in map-index : 18355
index : 18210
prev  : 
md5   : 
count : 45

found in map-index : 18355
index : 18302
prev  :
md5   :
count : 46

found in map-index : 18355
index : 18302
prev  : 
md5   : 
count : 47

md5   : 52ff1eae704f55555dec14f8e5040b73
added to map-index : 20015
char  : 5

found in map-index : 20015
index : 19212
prev  : 
md5   : 
count : 48

found in map-index : 20015
index : 19236
prev  : 
md5   : 
count : 49

found in map-index : 20015
index : 19270
prev  : 
md5   : 
count : 50

md5   : 39ed4edb214e59811d03ce3666669533
added to map-index : 20330
char  : 6

found in map-index : 20015
index : 19334
prev  : 
md5   : 
count : 51

found in map-index : 20015
index : 19346
prev  : 
md5   : 
count : 52

found in map-index : 20330
index : 19366
prev  : 
md5   : 
count : 53

found in map-index : 20015
index : 19369
prev  : 
md5   : 
count : 54

found in map-index : 20015
index : 19471
prev  : 
md5   : 
count : 55

found in map-index : 20015
index : 19498
prev  : 
md5   : 
count : 56

found in map-index : 20330
index : 19799
prev  : 
md5   : 
count : 57

found in map-index : 20015
index : 19880
prev  : 
md5   : 
count : 58

found in map-index : 20330
index : 19915
prev  : 
md5   : 
count : 59

found in map-index : 20330
index : 19947
prev  : 
md5   : 
count : 60

found in map-index : 20330
index : 19950
prev  : 
md5   : 
count : 61

found in map-index : 20330
index : 20212
prev  : 
md5   : 
count : 62

md5   : 2e559978fffff9ac9c9012eb764c6391
added to map-index : 22859
char  : f

found in map-index : 22859
index : 22097
prev  : 
md5   : 
count : 63

found in map-index : 22859
index : 22122
prev  :
md5   :
count : 64 (???????)

found in map-index : 22859
index : 22551
prev  : 
md5   : 
count : 65 (?????????)

*/

/****************************************************************************/

/*

//  Part 2
//  salt : ___



*/

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


// MD5 hash function ::
//
// programmingalgorithms.com/algorithm/md5/
//

typedef union uwb {
	unsigned w;
	unsigned char b[4];
} MD5union;

typedef unsigned DigestArray[4];

static unsigned func0(unsigned abcd[]){
	return (abcd[1] & abcd[2]) | (~abcd[1] & abcd[3]);
}

static unsigned func1(unsigned abcd[]){
	return (abcd[3] & abcd[1]) | (~abcd[3] & abcd[2]);
}

static unsigned func2(unsigned abcd[]){
	return  abcd[1] ^ abcd[2] ^ abcd[3];
}

static unsigned func3(unsigned abcd[]){
	return abcd[2] ^ (abcd[1] | ~abcd[3]);
}

typedef unsigned(*DgstFctn)(unsigned a[]);

static unsigned *calctable(unsigned *k)
{
	double s, pwr;
	int i;

	pwr = pow(2.0, 32);
	for (i = 0; i<64; i++) {
		s = fabs(sin(1.0 + i));
		k[i] = (unsigned)(s * pwr);
	}
	return k;
}

static unsigned rol(unsigned r, short N)
{
	unsigned  mask1 = (1 << N) - 1;
	return ((r >> (32 - N)) & mask1) | ((r << N) & ~mask1);
}

static unsigned* MD5Hash(string msg)
{
	int mlen = msg.length();
	static DigestArray h0 = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };
	static DgstFctn ff[] = { &func0, &func1, &func2, &func3 };
	static short M[] = { 1, 5, 3, 7 };
	static short O[] = { 0, 1, 5, 0 };
	static short rot0[] = { 7, 12, 17, 22 };
	static short rot1[] = { 5, 9, 14, 20 };
	static short rot2[] = { 4, 11, 16, 23 };
	static short rot3[] = { 6, 10, 15, 21 };
	static short *rots[] = { rot0, rot1, rot2, rot3 };
	static unsigned kspace[64];
	static unsigned *k;

	static DigestArray h;
	DigestArray abcd;
	DgstFctn fctn;
	short m, o, g;
	unsigned f;
	short *rotn;
	union {
		unsigned w[16];
		char     b[64];
	}mm;
	int os = 0;
	int grp, grps, q, p;
	unsigned char *msg2;

	if (k == NULL) k = calctable(kspace);

	for (q = 0; q<4; q++) h[q] = h0[q];

	{
		grps = 1 + (mlen + 8) / 64;
		msg2 = (unsigned char*)malloc(64 * grps);
		memcpy(msg2, msg.c_str(), mlen);
		msg2[mlen] = (unsigned char)0x80;
		q = mlen + 1;
		while (q < 64 * grps){ msg2[q] = 0; q++; }
		{
			MD5union u;
			u.w = 8 * mlen;
			q -= 8;
			memcpy(msg2 + q, &u.w, 4);
		}
	}

	for (grp = 0; grp<grps; grp++)
	{
		memcpy(mm.b, msg2 + os, 64);
		for (q = 0; q<4; q++) abcd[q] = h[q];
		for (p = 0; p<4; p++) {
			fctn = ff[p];
			rotn = rots[p];
			m = M[p]; o = O[p];
			for (q = 0; q<16; q++) {
				g = (m*q + o) % 16;
				f = abcd[1] + rol(abcd[0] + fctn(abcd) + k[q + 16 * p] + mm.w[g], rotn[q % 4]);

				abcd[0] = abcd[3];
				abcd[3] = abcd[2];
				abcd[2] = abcd[1];
				abcd[1] = f;
			}
		}
		for (p = 0; p<4; p++)
			h[p] += abcd[p];
		os += 64;
	}

	return h;
}

//static string GetMD5String(string msg) {
string  GetMD5String(string msg) {
	string str;
	int j;//, k;
	unsigned *d = MD5Hash(msg);
	MD5union u;
	for (j = 0; j<4; j++){
		u.w = d[j];
		char s[9];
		sprintf(s, "%02x%02x%02x%02x", u.b[0], u.b[1], u.b[2], u.b[3]);
		str += s;
	}

	return str;
}

//  Example
//  string data = "jdfgsdhfsdfsd 156445dsfsd7fg/*/+bfjsdgf%$^";
//  string value = GetMD5String(data);
//  Output
//  67046f2ecf6d4a8aee9dedcffc35b91b
