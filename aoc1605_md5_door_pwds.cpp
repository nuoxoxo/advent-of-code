// MD5 hash function ::
//
// programmingalgorithms.com/algorithm/md5/
//

/*****Please include following header files*****/
// string
/***********************************************/

/*****Please use following namespaces*****/
// std
/*****************************************/

#include <string>
using namespace std;

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

static string GetMD5String(string msg) {
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

//  DRIVE

#include <iostream>
#include <sstream>
#include <array> // len- & index-friendly compared to vector

int     islowdig(int c);

int     main(int argc, char **argv)
{
        string          id;
        string          md5string;
        string          index;
        string          pwd1;
        array<char, 8>  pwd2;
        int             integer_index;
        int             len1, len2, i;

        if (argc != 2)  return (1);
        id = argv[1];
        integer_index = len1 = len2 = i = 0;
        while (i < 8)   pwd2[i++] = 0;
        while (1)
        {
            stringstream ss;
            ss << integer_index;
            ss >> index;
            md5string = GetMD5String(id + index);
            i = 0;
            while (i < 5)
            {
                if (md5string[i] - 48) break;
                i++;
            }
            if (i == 5)
            {
                char    fifth = md5string[5];
                char    sixth = md5string[6];
                char    post = fifth - 48;

                if (len1 < 8)  pwd1 += fifth;
                if (post < 8 && !pwd2[post] && islowdig(sixth))
                {
                    len2++;
                    pwd2[post] = sixth;
                }
                len1++;
            }
            if (len2 == 8) break;
            integer_index++;
        }
        cout << "Star 1 : " << pwd1 << endl;
        cout << "Star 2 : ";
        i = 0;
        while (i < 8)   cout << pwd2[i++];
        cout << endl;

        return (0);
}

//

int     islowdig(int c)
{
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) return (1);
        return (0);
}
